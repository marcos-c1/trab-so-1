#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

struct Queue {
  pid_t data;
  int executionTime;
  struct Queue *next;
};

void schedulingProcess(struct Queue *f){
    struct Queue *aux = f;
    while(aux != NULL){
        printf("Process %d, executing..\n", aux->data);
        sleep(aux->executionTime);
        aux = aux->next;
    }
    free(aux);
}

int main() {
    srand(time(NULL));
    int it = 0;
    
    struct Queue *f = malloc(sizeof(struct Queue));
    f->next = NULL;

    // processo atual
    pid_t pid = getpid();
    float rndExecTime = rand() % 10;

    f->data = pid;
    f->executionTime = rndExecTime;
    
    // processo pai
    pid_t ppid = getppid();
    rndExecTime = rand() % 10;

    f->next = ppid;
    f->next->executionTime = rndExecTime;
    f->next->next = NULL;

    schedulingProcess(f);

    free(f);
    return 0;
}