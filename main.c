#include <stdio.h>

#define LEN 10

typedef struct{
    int values[LEN];
    int n;
} list;

int is_full(list *l){
    if (l->n == LEN){
        return 1;
    } else {
        return 0;
    }
}

int is_empty(list *l){
    if (l->n == 0){
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Encontra posição de inserção para manter ordem crescente.
 */

int find_idx(list *l, int valor){
    int i = 0;
    while(i < l->n && valor > l->values[i]){
        i++;
    }
    /**while(list->values[i] < valor){
        i++;
    }*/
    return i;
}

/**
 * @brief Busca valor na lista e retorna seu índice.
 * @return Índice do valor, ou -1 se não encontrado.
 */

int search(list *l, int valor) {
    int i = 0;
    while(i < l->n && l->values[i] != valor){
        i++;
    }
    if(i >= l->n){
        return -1;
    }
    return i;
}

void move_right(list *l, int idx){
    for(int i = l->n ; i > idx ; i--){
        l->values[i] = l->values[i-1];
    }
}

void move_left(list *l, int idx){
    for(int i = idx ; i < l->n - 1 ; i++){
        l->values[i] = l->values[i+1];
    }
}

/**
 * @brief Insere valor mantendo ordem crescente.
 * @return 1 se sucesso, 0 se lista cheia.
 */

int insert(list *l, int valor){
    if (is_full(l)){
        return 0;
    }

    int idx = 0;

    if (!is_empty(l)){
        idx = find_idx(l, valor);
        move_right(l, idx);
    }

    l->values[idx] = valor;
    l->n++;
    return 1;
}


int remove(list *l, int valor){
    if (is_empty(l)){
        return -1;
    }

    int idx = search(l, valor);

    if (idx == -1){
        return 0; // não encontrado
    }

    move_left(l, idx);
    l->n--;
    return 1;
}

void show(list *l){
    printf("[ ");
    for(int i = 0 ; i < l->n; i++){
        printf("%d ", l->values[i]);
    }
    printf("]\n");
}

int main(){
    printf("Hello World!\n");

    list l;
    l.n = 0;

    

/**
    insert(&l, 2);
    insert(&l, 4);
    insert(&l, 8);
    insert(&l, 5);

    show(&l);
*/
}