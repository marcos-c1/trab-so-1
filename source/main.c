#include "../headers/pq.h"
#include "../headers/process.h"
#include "../headers/queue.h"

void consume(PriorityQueue *pq, Queue *q) {
  int processPiece = 3;

  Process process = dequeue(pq);
  process.processTime -= processPiece;

  if (process.processTime <= 0) {
    if (process.IOtime <= 0)
      return;

  } else {
    if (process.IOtime <= 0) {
      enqueue(pq, process);
    }
  }

  if (process.IOtime > 0) {
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
    enqueue(&pq, p);
  }
  print(&pq);
  fclose(f);

  return 0;
}
