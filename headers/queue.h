#ifndef QUEUE_H
#define QUEUE_H
#include "process.h"

typedef struct {
  Process items[PROCESS_NUM];
  int size;
} Queue;

void enq(Queue *pq, Process value);
Process deq(Queue *pq);
Process peekTop(Queue *pq);
void printQueue(Queue *pq);

#endif
