# Operacionalito

O primeiro trabalho de Sistemas Operacionais.

## Grupo
>
> Henrique Stiler Bellinaso; 22205798
>
## Compilação

Compile os arquivos usando a ferramenta Make a partir do comando a seguir:

```bash
make
./objects/main.o
```

## Construção do algoritmo

1. Criou-se a estrutura de Fila de Prioridade usando o conceito de Heap. Heap é uma árvore especializada que mantém uma ordem específica entre a relação de nós pai-filho, podendo ser uma heap-máxima ou uma heap-mínima. Em uma heap-maxima, os valores de cada nó pai são maiores ou iguais aos valores dos filhos, sendo o maior elemento da heap o nó raiz. Em uma heap-minima é o posto, os valores de cada nó pai são menores ou iguais aos valores dos filhos, sendo o menor elemento da heap o nó da raiz.

2. Criou-se a estrutura de Fila Simples.

3. Definiu-se a estrutura Processo contendo todos os atributos referidos:
    * ID do processo
    * O tempo de entrada
    * O tempo de I/O
    * O tempo de processamento
    * A prioridade
    * Uma flag identificando se o processo havia finalizado

4. Criou-se a lógica do algoritmo conforme explicitada no trabalho
