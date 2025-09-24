#include "../headers/pq.h"

void heapifyUp(PriorityQueue *pq, int index) {
  if (index &&
      pq->items[(index - 1) / 2].priority > pq->items[index].priority) {
    swap(&pq->items[(index - 1) / 2], &pq->items[index]);
    heapifyUp(pq, (index - 1) / 2);
  }
}

void enqueue(PriorityQueue *pq, Process value) {
  pq->items[pq->size++] = value;
  heapifyUp(pq, pq->size - 1);
}

void heapifyDown(PriorityQueue *pq, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < pq->size &&
      pq->items[left].priority < pq->items[smallest].priority)
    smallest = left;

  if (right < pq->size &&
      pq->items[right].priority < pq->items[smallest].priority)
    smallest = right;

  if (smallest != index) {
    swap(&pq->items[index], &pq->items[smallest]);
    heapifyDown(pq, smallest);
  }
}

Process dequeue(PriorityQueue *pq) {
  Process item = pq->items[0];
  pq->items[0] = pq->items[--pq->size];
  heapifyDown(pq, 0);
  return item;
}

Process peek(PriorityQueue *pq) {
  assert(!pq->size);

  return pq->items[0];
}

void print(PriorityQueue *pq) {
  for (int i = 0; i < pq->size; i++) {
    printf("ID: %d, Priority: %d\n", pq->items[i].id, pq->items[i].priority);
  }
}
