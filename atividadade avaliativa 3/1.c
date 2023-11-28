#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

typedef struct produto{
    int codigo; 
    char descricao[60];
    int quantidade;
    float valor;
    struct produto *prox;
} produto;

produto* iniciarLista(){
    return NULL;
}

produto* novoProduto() {
    produto *novoProd = (produto*)malloc(sizeof(produto));

    if(novoProd == NULL) {
        printf("Não há memória suficiente...");
        exit(EXIT_FAILURE);
    } 

    novoProd -> prox = NULL;

    return novoProd;
}

produto* cadastrarProduto(produto *aux) {
    produto *novoProd = novoProduto();

    printf("\nDigite o código do produto: ");
    scanf("%d", &novoProd->codigo);
    while (getchar() != '\n');

    printf("Digite a descrição do produto: ");
    fgets(novoProd->descricao, sizeof(novoProd->descricao), stdin);
    while (getchar() != '\n');

    printf("\nDigite a quantidade do produto: ");
    scanf("%d", &novoProd->quantidade);
    while (getchar() != '\n');

    printf("\nDigite o valor do produto: ");
    scanf("%f", &novoProd->valor);
    while (getchar() != '\n');

    novoProd->prox = NULL;


    if(aux == NULL) {
        aux = novoProd;
    } else {
        produto *atual = aux; 

        while(atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novoProd;
    }

    return aux;
}

void mostrarProdutos(produto *aux) {
    produto *atual = aux; 

    if(atual == NULL) {
        printf("Não há ninguém na lista");
        return; 
    } else {
        while(atual != NULL) {
            printf("Código: %d", atual->codigo);
            printf("\n");
            printf("Descrição: %s", atual->descricao);
            printf("\n");
            printf("Quantidade: %d", atual->quantidade);
            printf("\n");
            printf("Valor: %.2f", atual->valor);
            printf("\n");

            atual = atual->prox;
        }
    }

}

produto* buscarProduto(produto *aux, int codigo) {
    produto *atual = aux; 

    if(atual == NULL) {
        printf("Não há ninguém na lista");
    } else {
        while(atual != NULL) {
            if(atual->codigo == codigo) {
                printf("Código: %d", atual->codigo);
                printf("\n");
                printf("Descrição: %s", atual->descricao);
                printf("\n");
                printf("Quantidade: %d", atual->quantidade);
                printf("\n");
                printf("Quantidade: %.2f", atual->valor);
                printf("\n");

                return atual;
        }
    }
    }  
    atual = atual->prox;
}

int main() {

    int opcao, codigo; 
    produto *aux =  iniciarLista(); 

    do{ 

        printf("\n1 - Cadastrar novo produto");
        printf("\n2 - Mostrar todos os produtos");
        printf("\n3 - Buscar produto");
        printf("\n4 - Excluir produto");
        printf("\n0 - Sair");
        printf("\n");

        scanf("%d", &opcao); 

        switch(opcao) {
            case 1: 
                aux = cadastrarProduto(aux);
            break;

            case 2: 
                mostrarProdutos(aux);
            break;

            case 3: 
                printf("Digite o ID que deseja buscar:");
                scanf("%d", &codigo);

                buscarProduto(aux, codigo);
            break;

            case 4: 
            break;

            case 5: 
            break;
        }

    }while (opcao != 0);

    return 0;
}