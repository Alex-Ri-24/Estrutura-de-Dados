#include <stdio.h>
#define TAMANHO 10

typedef struct {
    int valores[TAMANHO];
    int n;
} Lista;

int esta_cheia(Lista *lista) {
    return lista->n == TAMANHO;
}

int esta_vazia(Lista *lista) {
    return lista->n == 0;
}

/**
 * @brief Encontra posição de inserção para manter ordem crescente.
 */
int encontrar_posicao_insercao(Lista *lista, int valor) {
    int i = 0;
    while(i < lista->n && lista->valores[i] < valor){
        i++;
    }
    return i;
}

/**
 * @brief Busca valor na lista e retorna seu índice.
 * @return Índice do valor, ou -1 se não encontrado.
 */
int buscar(Lista *lista, int valor) {
    int i = 0;
    while(i < lista->n && lista->valores[i] != valor){
        i++;
    }
    if(i >= lista->n){
        return -1;
    }
    return i;
}

void deslocar_direita(Lista *lista, int indice) {
    for(int i = lista->n; i > indice; i--){
        lista->valores[i] = lista->valores[i - 1];
    }
}

void deslocar_esquerda(Lista *lista, int indice) {
    for(int i = indice; i < lista->n; i++){
        lista->valores[i] = lista->valores[i + 1];
    }
}

/**
 * @brief Insere valor mantendo ordem crescente.
 * @return 1 se sucesso, 0 se lista cheia.
 */
int inserir(Lista *lista, int valor) {
    if (esta_cheia(lista)) {
        return 0;
    }
    int indice = encontrar_posicao_insercao(lista, valor);
    if (!esta_vazia(lista)) {
        deslocar_direita(lista, indice);
    }
    lista->valores[indice] = valor;
    lista->n++;
    return 1;
}

/**
 * @brief Remove valor da lista.
 * @return 1 se removido, 0 se não encontrado, -1 se lista vazia.
 */
int remover(Lista *lista, int valor) {
    if (esta_vazia(lista)) {
        return -1;
    }
    
    int indice = buscar(lista, valor);
    if (indice == -1) {
        return 0;  // Não encontrado
    }
    
    deslocar_esquerda(lista, indice);
    lista->n--;
    return 1;
}

void exibir_lista(const Lista *lista) {
    for (int i = 0; i < lista->n; i++) {
        printf("%d ", lista->valores[i]);
    }
    printf("\n");
}

int main(void) {
    Lista lista = { .n = 0 };
    Lista *pl = &lista;
    
    int valores[] = {21, 14, 13, 10, 87, 35, 27, 56, 85, 29};
    
    printf("=== INSERINDO VALORES ===\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (inserir(pl, valores[i])) {
            printf("Inserido %d: ", valores[i]);
            exibir_lista(pl);
        } else {
            printf("Falha ao inserir %d (lista cheia)\n", valores[i]);
        }
    }
    
    printf("\n=== BUSCANDO VALORES ===\n");
    for (int i = 0; i < TAMANHO; i++) {
        int pos = buscar(pl, valores[i]);
        if (pos != -1) {
            printf("Valor %d encontrado na posição %d\n", valores[i], pos);
        } else {
            printf("Valor %d NÃO encontrado\n", valores[i]);
        }
    }
    
    printf("\n=== REMOVENDO VALORES ===\n");
    for (int i = 0; i < TAMANHO; i++) {
        int resultado = remover(pl, valores[i]);
        if (resultado == 1) {
            printf("Removido %d: ", valores[i]);
            exibir_lista(pl);
        } else if (resultado == 0) {
            printf("Valor %d não encontrado para remoção\n", valores[i]);
        } else {
            printf("Lista vazia\n");
        }
    }
    
    return 0;
}