#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h> 

typedef struct pessoa{
    int id; 
    char nome[40];
    int idade;
    struct pessoa *prox;
} pessoa;

pessoa* iniciarLista(){
    return NULL;
}

pessoa* novoUsuario() {
    pessoa *novoUser = (pessoa*)malloc(sizeof(pessoa));

    if(novoUser == NULL) {
        printf("Não há memória suficiente...");
        exit(EXIT_FAILURE);
    } 

    novoUser -> prox = NULL;

    return novoUser;
}

pessoa* cadastrarUsuario(pessoa *aux) {
    pessoa *novoUser = novoUsuario();

    srand(time(NULL));
    novoUser->id = rand() % 100;

    printf("\nDigite o nome do usuário: ");
    fgets(novoUser->nome, sizeof(novoUser->nome), stdin);
    while (getchar() != '\n');
    novoUser->nome[strcspn(novoUser->nome, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &novoUser->idade);

    while (getchar() != '\n');

    novoUser->prox = NULL;


    if(aux == NULL) {
        aux = novoUser;
    } else {
        pessoa *atual = aux; 

        while(atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novoUser;
    }

    return aux;
}

void mostrarLista(pessoa *aux) {
    pessoa *atual = aux; 

    if(atual == NULL) {
        printf("Não há ninguém na lista");
        return; 
    } else {
        while(atual != NULL) {
            printf("Nome: %s", atual->nome);
            printf("\n");
            printf("Idade: %d", atual->idade);
            printf("\n");
            printf("ID: %d", atual->id);
            printf("\n");

            atual = atual->prox;
        }
    }

}

pessoa* buscarId(pessoa *aux, int idBusca) {
    pessoa *atual = aux; 

    if(atual == NULL) {
        printf("Não há ninguém na lista");
    } else {
        while(atual != NULL) {
            if(atual->id == idBusca) {
                printf("Nome: %s", atual->nome);
                printf("\n");
                printf("Idade: %d", atual->idade);
                printf("\n");
                printf("ID: %d", atual->id);
                printf("\n");

                return atual;
        }
    }
    }  
    atual = atual->prox;
}

int main() {

    int opcao, idBusca; 
    pessoa *aux =  iniciarLista(); 

    do{ 

        printf("\n1 - Cadastrar novo usuário");
        printf("\n2 - Mostrar todos os usuários");
        printf("\n3 - Buscar usuário");
        printf("\n4 - Alterar usuário");
        printf("\n5 - Excluir usuário");
        printf("\n0 - Sair");
        printf("\n");

        scanf("%d", &opcao); 

        switch(opcao) {
            case 1: 
                aux = cadastrarUsuario(aux);
            break;

            case 2: 
                mostrarLista(aux);
            break;

            case 3: 
                printf("Digite o ID que deseja buscar:");
                scanf("%d", &idBusca);

                buscarId(aux, idBusca);
            break;

            case 4: 
            break;

            case 5: 
            break;
        }

    }while (opcao != 0);

    return 0;
}