#include <stdio.h>
#include <stdlib.h>

typedef struct Processo {
    int idProcesso, tempoEntrada, tempoIO, tempoProcessamento, prioridade;
} Processo;

typedef struct Fila {
    Processo processo;
    struct Fila *proximoProcesso;
} Fila;

typedef struct FilaPrioridade {
    Processo processo;
    struct FilaPrioridade *proximoProcesso;
} FilaPrioridade;

FilaPrioridade * criaProcesso(FilaPrioridade *pq, Processo p){
    pq = malloc(sizeof(FilaPrioridade));
    pq->processo = p;
    pq->proximoProcesso = NULL;

    return pq;
}

FilaPrioridade * adicionaProcesso(FilaPrioridade *pq, Processo p){
    if(pq == NULL){
        pq = criaProcesso(pq, p);
        printf("ID Processo: %d\tPrioridade: %d\n", pq->processo.idProcesso, pq->processo.prioridade);

    } else {
        int prioridadeAnt = pq->processo.prioridade;
        int prioridadeAtual = p.prioridade;

        if(prioridadeAnt > prioridadeAtual){
            FilaPrioridade *noAux, *noAux2;
            noAux2 = pq;
            noAux = criaProcesso(noAux, p);
            pq = noAux;
            pq->proximoProcesso = noAux2;

            free(noAux);
            free(noAux2);
        } else {
            adicionaProcesso(pq->proximoProcesso, p);
        }
    }
    return pq;
}

void printaFila(FilaPrioridade *pq){
    FilaPrioridade *noAux = pq;
   
    while(noAux != NULL){
        printf("ID Processo: %d\tPrioridade: %d\n", noAux->processo.idProcesso, noAux->processo.prioridade);
        noAux = noAux->proximoProcesso;
    }

    free(noAux);
}

// 1 -> 2 -> 3 -> 4

// Receber um arquivo dados.txt e atribuir em uma varíavel
// Ler esse arquivo tanto por delimitador quanto por linha
// Ao ler por delimitador, atribuir os valores de cada coluna em suas respectivas variaveis
// Criar as estruturas de fila (simples e prioritaria)
// Depois fazer a logica do programa
int main(){
    Processo p;

    FILE *f = fopen("dados.txt", "r");
    FilaPrioridade *pq = NULL; 
    Fila *q = NULL;

    if(f == NULL){
        fprintf(stderr, "Erro ao abrir o buffer para receber o arquivo");
        return EXIT_FAILURE;
    }

    // ID 1: 3
    // 2  1 
    // ID 2: 2
    while(fscanf(f, "%d;%d;%d;%d;%d", &p.idProcesso, &p.tempoEntrada, &p.tempoIO, &p.tempoProcessamento, &p.prioridade) != EOF){
        pq = adicionaProcesso(pq, p);
    }
    if(pq != NULL) printf("Existe a fila");
    printaFila(pq);

    fclose(f);
    free(pq);
    free(q);
    return EXIT_SUCCESS;
}