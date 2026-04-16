#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    char valor;
    struct Celula *proximo;
    struct Celula *anterior;
} Celula;

typedef struct{
    int qtde;
    struct Celula *topo;
} Pilha;

Pilha *inicializa_pilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->qtde = 0;
    p->topo = NULL;
    return p;
}

Celula *inicializa_celula(char valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    nova->anterior = NULL;
    return nova;
}

void mostrar(Pilha *p){
    Celula *atual = p->topo;
    while(atual != NULL){
        printf("%c", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void empilhar(Pilha *p, char valor){
    Celula *nova = inicializa_celula(valor);

    if(p->qtde > 0){
        nova->proximo = p->topo;
        p->topo->anterior = nova;
    }

    p->topo = nova;
    p->qtde++;
}

char desempilhar(Pilha *p){
    if(p->qtde == 0) return '$';

    Celula *atual = p->topo;
    char valor = p->topo->valor;

    p->topo = p->topo->proximo;
    if(p->topo != NULL){
        p->topo->anterior = NULL;
    }
    free(atual);
    p->qtde--;
    return valor;
}

int main(){
    printf("Pilha Dinâmica\n");

    Pilha *p = inicializa_pilha();

    empilhar(p, 'A');
    mostrar(p);
    empilhar(p, 'R');
    mostrar(p);
    empilhar(p, 'A');
    mostrar(p);
    empilhar(p, 'R');
    mostrar(p);
    empilhar(p, 'A');
    mostrar(p);

    char valor;
    valor = desempilhar(p);
    printf("%c", valor);
    valor = desempilhar(p);
    printf("%c", valor);
    valor = desempilhar(p);
    printf("%c", valor);
    valor = desempilhar(p);
    printf("%c", valor);
    valor = desempilhar(p);
    printf("%c", valor);
    mostrar(p);

    return 0;
}