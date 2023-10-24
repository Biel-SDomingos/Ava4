#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>


/*Função que realiza as operações*/
float notacao_polonesa_inversa (int argc, char *argv[]) {
    Pilha pilha_polonesa;
    criar_pilha(&pilha_polonesa, argc);

    for (int i = 1; i < argc; ++i) {
        char *p = argv[i];
        if (*p == '*') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n *= desempilhar(&pilha_polonesa);
            empilhar(&pilha_polonesa, n);
        } else if (*p == '+') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n  += desempilhar(&pilha_polonesa);
            empilhar(&pilha_polonesa, n);
        } else if (*p == '/') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n = desempilhar(&pilha_polonesa) / n;
            empilhar(&pilha_polonesa, n);
        } else if (*p == '-') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n = desempilhar(&pilha_polonesa) - n;
            empilhar(&pilha_polonesa, n);
        } else {
            *p = atof(p);
            empilhar(&pilha_polonesa, *p);
        }

    }
    return desempilhar(&pilha_polonesa);
}