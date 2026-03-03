#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;

} Celula;

typedef struct LDE{
    int qtde;
    Celula *primeiro;

} LDE;

LDE *inicializa(){
    LDE *l = (LDE*)malloc(sizeof(LDE));
    l->qtde = 0;
    l->primeiro = NULL;
    return l;
}

void imprimir(LDE *l){
    Celula *atual;
    printf("[ ");
    atual = l->primeiro;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("]\n");
}

void inserir(LDE *l, int valor){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    
    Celula *atual = l->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual= atual->proximo;
    }

    //LISTA VAZIA
    if(anterior == NULL && atual == NULL){
        l->primeiro = nova;
    }
    //FIM DA LISTA
    else if(anterior != NULL && atual == NULL){
        anterior->proximo = nova;
    }
    //MEIO DA LISTA
    else{
        anterior->proximo = nova;
        nova->proximo = atual;
    }
    l->qtde++;
}

void remover(LDE *l, int valor){
    // buscar(l, valor);

    Celula *atual = l->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual= atual->proximo;
    }

    if (atual == NULL || l->qtde == 0){
        printf("Não encontrou %d ou lista vazia\n", valor);
        return;
    }
    else if (anterior == NULL){
        l->primeiro = atual->proximo;
    }
    else{
        anterior->proximo = atual->proximo;
    }
    free(atual);
    l->qtde--;
    printf("Encontrou %d\n", valor);
}

int buscar(LDE *l, int valor){
    Celula *atual;
    atual = l->primeiro;

     while(atual != NULL){
        if(valor == atual->valor){
            printf("Encontrou\n");
            return 1;
        } else{
            atual = atual->proximo;
        }
    }
    printf("Não encontrou\n");
    return 0;
}

int main() {
    printf("Lista Dinamica Encadeada (LDE)\n");

    LDE *l = inicializa();

    int valores[] = {3, 6, 1, 9, 0, 4, 2, 8, 7, 5};

    for(int i = 0; i < 10; i++){
        inserir(l, i);
        imprimir(l);
    }

    for(int i = 0; i < 10; i++){
        remover(l, i);
        imprimir(l);
    }
    
    //inserir(l, 18);
    //inserir(l, 30);
    //inserir(l, 23);
    //imprimir(l);

    //remover(l, 50);
    //imprimir(l);

    //remover(l, 18);
    // imprimir(l);

    //remover(l, 23);
    //imprimir(l);

    //remover(l, 30);
    //imprimir(l);

    //remover(l, 31);
    //imprimir(l);

    // buscar(l, 4);
    
    return 0;
}