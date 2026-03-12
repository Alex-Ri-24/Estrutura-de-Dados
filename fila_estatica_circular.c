#include <stdio.h>
#include <stdlib.h>

#define LEN 6

typedef struct {
    char dados[LEN];
    int head;
    int tail;
    int qtde;
} Queue; // Fila em inglês

int isFull(Queue *queue){
    return (queue->tail +1) %LEN == queue->head;
}

int isEmpty(Queue *queue){
    return (queue->tail == queue->head);
}

// enqueue = enfilerar
void enqueue(Queue *queue, char valor){
    if(isFull(queue)) return;
    
    queue->dados[queue->tail] = valor;
    queue->tail = (queue->tail + 1) % LEN;
    queue->qtde++;
}

// dequeue = desfilerar
char dequeue(Queue *queue){
    if(isEmpty(queue)) return '\0';

    char valor = queue->dados[queue->head];
    queue->head = (queue->head + 1) % LEN;
    queue->qtde--;
    return valor;
}

// show = mostrar
void show(Queue *queue){
    printf("[ ");
    for(int i = queue->head; i != queue->tail; i = (i + 1) % LEN){
        printf("%c ", queue->dados[i]);
    }
    printf("]\n");
}

// inicializa a fila
void setup(Queue *queue){
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(){
    printf("Fila Estática Circular\n");

    Queue queue;
    setup(&queue);
    enqueue(&queue, 'A');
    enqueue(&queue, 'B');
    enqueue(&queue, 'C');
    enqueue(&queue, 'D');
    enqueue(&queue, 'E');
    enqueue(&queue, 'F');
    show(&queue);
    char proximo = dequeue(&queue);
    printf("%c foi atendido\n", proximo);
    show(&queue);

    return 0;
}