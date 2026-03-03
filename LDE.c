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
    printf("Lista Dinamica Encadeada\n");

    LDE *l = inicializa();
    
    inserir(l, 0);
    inserir(l, 1);
    inserir(l, 3);
    inserir(l, 2);
    imprimir(l);

    buscar(l, 4);
    
    return 0;
}