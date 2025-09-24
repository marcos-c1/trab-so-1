#ifndef PQ_H
#define PQ_H
#include "process.h"

typedef struct {
  Process items[PROCESS_NUM];
  int size;
} PriorityQueue;

void heapifyUp(PriorityQueue *pq, int index);
void enqueue(PriorityQueue *pq, Process value);
void heapifyDown(PriorityQueue *pq, int index);
Process dequeue(PriorityQueue *pq);
Process peek(PriorityQueue *pq);
void print(PriorityQueue *pq);

#endif
