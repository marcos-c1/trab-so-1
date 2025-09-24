#include "../headers/process.h"

void swap(Process *a, Process *b) {
  Process temp = *a;
  *a = *b;
  *b = temp;
}
