#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

struct No* criarNo(int valor) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro de memoria\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

struct No* inserir(struct No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void preOrdem(struct No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(struct No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(struct No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void liberarArvore(struct No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    struct No *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);
    return 0;
}