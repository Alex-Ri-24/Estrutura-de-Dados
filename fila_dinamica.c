#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
} Celula;

typedef struct {
    Celula *head;
    Celula *tail;
    int qtde;
} Fila;

// inicializa a fila
Fila *inicializa(){
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
    return fila;
}

void mostrar(Fila *fila){
    printf("[ ");
    Celula *atual = fila->head;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void enfilerar(Fila *fila, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    nova->anterior = NULL;

    if(fila->qtde == 0){
        fila->head = nova;
        fila->tail = nova;
        fila->qtde++;
    }
    else{
        nova->anterior = fila->tail;
        fila->tail->proximo = nova;
        fila->tail = nova;
        fila->qtde++;
    }
}

int desfilerar(Fila *fila){
    if(fila->qtde == 0){
        printf("Fila vazia\n");
        return -1;
    }
    Celula *atual = fila->head;
    if(atual != NULL){ // fila não vazia
        int retirado = atual->valor;
        fila->head = atual->proximo;
        if(fila->head != NULL){ // tem mais de um elemento
            atual->proximo->anterior = NULL;
        }
        else{ // fila ficou vazia
            fila->tail = NULL;
        }
        printf("Retirado o %d\n", retirado);
        free(atual);
        fila->qtde--;
        return retirado;
    }
}

int main(){
    printf("Fila Dinâmica\n");

    Fila *fila = inicializa();
    enfilerar(fila, 1);
    mostrar(fila);
    enfilerar(fila, 2);
    mostrar(fila);
    enfilerar(fila, 3);
    mostrar(fila);
    int ret1 = desfilerar(fila);
    mostrar(fila);
    int ret2 = desfilerar(fila);
    mostrar(fila);
    int ret3 = desfilerar(fila);
    mostrar(fila);

    return 0;
}