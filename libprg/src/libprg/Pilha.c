
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>


/*Função que cria uma pilha*/
void criar_pilha(Pilha *pilha, int capacidade) {
    pilha -> valores = malloc((sizeof (float)) * capacidade);
    if (pilha -> valores == NULL) {
        printf("Falha na alocação de memória\n");
        exit(1);
    }

    pilha-> capacidade = capacidade;
    pilha-> topo = 0;
}
/*Função para mostrar a pilha criada*/
void imprimir_pilha(Pilha *pilha) {
    for (int i = 0; i < (pilha -> topo); ++i) {
        printf("%f ", pilha -> valores[i]);
    }
    printf("\n");
}
/*Função para acrescentar um valor ao topo da pilha*/
void empilhar (Pilha *pilha, float p) {
    pilha -> valores[pilha -> topo] = p;
    pilha -> topo++;
}

/*Função ṕara desempilhar, removendo o ultimo valor empilhado*/
float desempilhar (Pilha *pilha) {
    if (vazio(pilha)) {
    } else {
        pilha -> topo--;
        float p = pilha->valores[pilha->topo];
        return p;
    }
}

/*Função que retorna o numero de elementos da pilha*/
int tamanho (Pilha *pilha) {
    return pilha -> topo;
}

/*Função para verificar se a pilha está vazia*/
int vazio (Pilha *pilha) {
    if (pilha -> topo == 0) {
        return 1;
    }
    return 0;
}
