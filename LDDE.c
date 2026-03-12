#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proxima;
    struct Celula *anterior;

} Celula;

typedef struct{
    int qtde;
    Celula *primeira;
    //Celula *ultima;

} LDDE;

LDDE *inicializa(){
    LDDE *lista = (LDDE*)malloc(sizeof(LDDE));
    lista->qtde = 0;
    lista->primeira = NULL;
    return lista;
}

Celula *inicializa_celula(int valor){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proxima = NULL;
    nova->anterior = NULL;
    return nova;
}

void mostrar(LDDE *lista){
    printf("[ ");
    Celula *atual = lista->primeira;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proxima;
    }
    printf("]\n");
}

void insert(LDDE *lista, int valor){
    Celula *nova = inicializa_celula(valor);

    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    //Celula *aux = lista->ultima;

    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual = atual->proxima;
    }
    // lista vazia
    if(anterior == NULL && atual == NULL){
        lista->primeira = nova;
        //lista->ultima = nova;
    }
    // final da lista
    else if(anterior != NULL && atual == NULL){
        anterior->proxima = nova;
        nova->anterior = anterior;
        //lista->ultima = atual;
    }
    // meio da lista
    else if(anterior != NULL && atual != NULL){
        nova->anterior = anterior;
        nova->proxima = atual;
        anterior->proxima = nova;
        atual->anterior = nova;
    }
    // inicio da lista
    else if(anterior == NULL && atual != NULL){
        atual->anterior = nova;
        lista->primeira = nova;
        nova->proxima = atual;
    }
    lista->qtde++;
}

void remover(LDDE *lista, int valor){
    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proxima;
    }
    // lista vazia e elemento não encontrado
    if(atual == NULL){ 
        return;
    }
    else if(anterior == NULL){
        if(atual->proxima != NULL){
            atual->proxima->anterior = NULL;
        }
        atual->proxima->anterior = NULL;
        lista->primeira = atual->proxima;
        lista->qtde--;
        free(atual);
        return;
    }

    anterior->proxima = atual->proxima;
    if(atual->proxima != NULL){
        atual->proxima->anterior = anterior;
    }
    lista->qtde--;
    free(atual);
    return;
}

void imprimir_invertido(LDDE *lista){
    printf("[ ");
    Celula *atual = lista->primeira;
    while (atual->proxima != NULL){
        atual = atual->proxima;
    }
    while(atual->anterior != NULL){
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("%d", atual->valor);
    printf(" ]\n");
}

int main(){
    printf("Lista Dinamica Duplamente Encadeada (LDDE)\n");
    LDDE *lista = inicializa();
    insert(lista, 1);
    insert(lista, 20);
    insert(lista, 10);
    insert(lista, 0);
    mostrar(lista);
    imprimir_invertido(lista);
    remover(lista, 1);
    mostrar(lista);
    return 0;
}