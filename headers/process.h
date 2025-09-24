#ifndef PROCESS_H
#define PROCESS_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define PROCESS_NUM 15

typedef struct Process {
  int id;
  int inputTime;
  int IOtime;
  int processTime;
  int priority;
  int isUp;
} Process;

void swap(Process *a, Process *b);

#endif
