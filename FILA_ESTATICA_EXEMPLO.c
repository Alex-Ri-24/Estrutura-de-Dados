#include <stdio.h>
#include <string.h>
#define MAX_FILA 10
#define MAX_NOME 20

typedef struct {
    char nome[MAX_NOME];
    int senha;
} Cliente;

typedef struct {
    Cliente data[MAX_FILA];
    int head;
    int tail;
    int qtde;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->head = 0;
    fila->tail = 0;
    fila->qtde = 0;
}

int fila_cheia(Fila *fila) {
    return fila->qtde >= MAX_FILA;
}

int fila_vazia(Fila *fila) {
    return fila->qtde == 0;
}

void entrar_na_fila(Fila *fila, char *nome, int senha) {
    if(fila_cheia(fila)){
        printf("Fila lotada\n");
        return;
    }
    
    // Criar cliente temporário
    Cliente novo_cliente;
    strcpy(novo_cliente.nome, nome);
    novo_cliente.senha = senha;

    // Adicionar na posição tail
    fila->data[fila->tail] = novo_cliente;
    fila->tail = (fila->tail + 1) % MAX_FILA;
    fila->qtde++;

    printf("Cliente [%s] adicionado - Senha: [%d]\n", nome, senha);
}

void atender_cliente(Fila *fila) {
    if(fila_vazia(fila)){
        printf("Fila vazia\n");
        return;
    }
    Cliente cliente_atendido = fila->data[fila->head];
    printf("Atendendo: %s (Senha: %d)\n", cliente_atendido.nome, cliente_atendido.senha);
    fila->head = (fila->head + 1) % MAX_FILA;
    fila->qtde--;
}

void mostrar_fila(Fila *fila) {
    printf("Fila atual:\n");
    int contador = 1;
    for(int i = fila->head; i != fila->tail; i = (i + 1) % MAX_FILA){
        printf("%d. %s (Senha: %d)\n", contador++, fila->data[i].nome, fila->data[i].senha);
    }
}

int buscar_cliente(Fila *fila, int senha) {
    int contador = 1;
    for(int i = fila->head; i != fila->tail; i = (i + 1) % MAX_FILA){
        if(fila->data[i].senha == senha){
            printf("Cliente encontrado: %s (Posicao: %d)\n", fila->data[i].nome, contador);
            return 1;
        }
        contador++;
    }
    printf("Cliente nao encontrado\n");
    return 0;
}

void tamanho_fila(Fila *fila) {
    printf("Tamanho da fila: %d\n", fila->qtde);
}

int main(void) {
    Fila fila_atendimento;
    inicializar_fila(&fila_atendimento);
    
    int senha = 1000;
    
    // Adicionar clientes iniciais para teste
    entrar_na_fila(&fila_atendimento, "Maria", senha++);
    entrar_na_fila(&fila_atendimento, "Joao", senha++);
    entrar_na_fila(&fila_atendimento, "Ana", senha++);
    
    printf("Fila inicial criada com 3 clientes\n");
    mostrar_fila(&fila_atendimento);
    printf("\n");
    
    // Demonstrar operações
    printf("=== DEMONSTRACAO DAS OPERACOES ===\n");
    
    // Operação 1: Mostrar tamanho
    printf("\n1. Verificar tamanho da fila:\n");
    tamanho_fila(&fila_atendimento);
    
    // Operação 2: Buscar cliente
    printf("\n2. Buscar cliente com senha 1001:\n");
    buscar_cliente(&fila_atendimento, 1001);
    
    // Operação 3: Atender cliente
    printf("\n3. Atender proximo cliente:\n");
    atender_cliente(&fila_atendimento);
    mostrar_fila(&fila_atendimento);
    
    // Operação 4: Adicionar novo cliente
    printf("\n4. Adicionar novo cliente:\n");
    entrar_na_fila(&fila_atendimento, "Pedro", senha++);
    mostrar_fila(&fila_atendimento);
    
    // Operação 5: Atender todos os clientes
    printf("\n5. Atender todos os clientes restantes:\n");
    while (!fila_vazia(&fila_atendimento)) {
        atender_cliente(&fila_atendimento);
    }
    
    // Operação 6: Tentar atender fila vazia
    printf("\n6. Tentar atender fila vazia:\n");
    atender_cliente(&fila_atendimento);
    
    // Operação 7: Verificar tamanho final
    printf("\n7. Tamanho final da fila:\n");
    tamanho_fila(&fila_atendimento);
    
    return 0;
}