#include "../headers/pq.h"
#include "../headers/process.h"
#include "../headers/queue.h"
#include <time.h>
#include <unistd.h>

clock_t startTime, endTime;
double timeSpent;

void addProcessToFile(int processID) {
  FILE *f = fopen("output.txt", "a");
  if (f == NULL) {
    fprintf(
        stderr,
        "Erro ao abrir o arquivo de saida para receber os dados do processo");
    exit(-1);
  }

  fprintf(f, "%f;%d\n", timeSpent * 1000, processID);

  fclose(f);
}

Process consumeIO(Queue *q, int IOPiece) {
  Process item = deq(q);
  item.IOtime -= IOPiece;

  return item;
}

void consume(PriorityQueue *pq, Queue *q) {
  int processPiece = 3;
  int processPieceWhenFinished = 1;

  Process process = dequeue(pq);
  if (process.isFinished != 0) {
    process.processTime -= processPiece;
  } else {
    process.processTime -= processPieceWhenFinished;
  }

  if (process.processTime <= 0) {
    if (process.IOtime <= 0) {
      endTime = clock();
      timeSpent = (double)(endTime - startTime) / CLOCKS_PER_SEC;
      addProcessToFile(process.id);
      return;
    }

  } else {
    if (process.IOtime <= 0) {
      enqueue(pq, process);
    }
  }

  if (process.IOtime > 0) {
    enq(q, process);
    process = consumeIO(q, processPiece * 2);

    if (process.processTime > 0) {
      enqueue(pq, process);
    } else {
      if (process.IOtime > 0) {
        enq(q, process);
      } else {
        process.isFinished = 1;
      }
    }
  }
}

int main() {
  Process p;

  FILE *f = fopen("dados.txt", "r");
  PriorityQueue pq = {{0}, 0};
  Queue queue = {{0}, 0};

  if (f == NULL) {
    fprintf(stderr, "Erro ao abrir o buffer para receber o arquivo");
    return -1;
  }

  while (fscanf(f, "%d;%d;%d;%d;%d", &p.id, &p.inputTime, &p.IOtime,
                &p.processTime, &p.priority) != EOF) {
    // sleep(p.inputTime);
    startTime = clock();
    enqueue(&pq, p);
  }
  print(&pq);
  while (pq.size > 0) {
    consume(&pq, &queue);
  }

  fclose(f);

  return 0;
}
