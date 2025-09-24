#include "../headers/queue.h"

void enq(Queue *pq, Process value) { pq->items[pq->size++] = value; }

Process deq(Queue *pq) {
  Process item = pq->items[0];
  pq->items[0] = pq->items[--pq->size];
  return item;
}

Process peekTop(Queue *pq) {
  assert(!pq->size);
  return pq->items[0];
}

void printQueue(Queue *pq) {
  for (int i = 0; i < pq->size; i++) {
    printf("ID: %d\n", pq->items[i].id);
  }
}
