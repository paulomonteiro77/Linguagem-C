#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definindo a estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializando a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verificando se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilhando um item
void empilhar(Pilha *p, int valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

// Desempilhando um item
int desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

// Invertendo a pilha
void inverter(Pilha *p) {
    int aux[MAX];
    int i = 0;
    
    while (!estaVazia(p)) {
        aux[i++] = desempilhar(p);
    }
    
    for (int j = 0; j < i; j++) {
        empilhar(p, aux[j]);
    }
}

// Função principal para testar a inversão da pilha
int main() {
    Pilha pilha;
    inicializar(&pilha);

    empilhar(&pilha, 1);
    empilhar(&pilha, 2);
    empilhar(&pilha, 3);
    
    printf("Pilha original: ");
    for (int i = 0; i <= pilha.topo; i++) {
        printf("%d ", pilha.itens[i]);
    }
    printf("\n");

    inverter(&pilha);

    printf("Pilha invertida: ");
    for (int i = 0; i <= pilha.topo; i++) {
        printf("%d ", pilha.itens[i]);
    }
    printf("\n");

    return 0;
}
