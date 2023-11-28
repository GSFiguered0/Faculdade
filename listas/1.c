#include <stdio.h> 
#include <stdlib.h> 
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

pessoa* cadastrarUsuario(pessoa *lista) {
    pessoa *novoUser = novoUsuario();

    srand(time(NULL));
    novoUser->id = rand() % 100;

    printf("\nDigite o nome do usuário: ");
    fgets(novoUser->nome, sizeof(novoUser->nome), stdin);
    while (getchar() != '\n');

    printf("Digite a idade: ");
    scanf("%d", &novoUser->idade);

    while (getchar() != '\n');

    novoUser->prox = NULL;


    if(lista == NULL) {
        lista = novoUser;
    } else {
        pessoa *atual = lista; 

        while(atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novoUser;
    }

    return lista;
}

int main() {

    int opcao; 
    pessoa *lista =  iniciarLista(); 

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
                lista = cadastrarUsuario(lista);
            break;

            case 2: 
            break;

            case 3: 
            break;

            case 4: 
            break;

            case 5: 
            break;
        }

    }while (opcao != 0);

    return 0;
}