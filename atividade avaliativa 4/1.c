#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

typedef struct veiculo{
    char prop[50];
    char combustivel[30];
    char modelo[50];
    char cor[50];
    int chassi;
    int ano;
    char placa[7];
    struct veiculo *prox;
} veiculo;

veiculo* iniciarLista(){
    return NULL;
}

veiculo* novoVeiculo() {
    veiculo *novoVeic = (veiculo*)malloc(sizeof(veiculo));

    if(novoVeic == NULL) {
        printf("Não há memória suficiente...");
        exit(EXIT_FAILURE);
    } 

    novoVeic -> prox = NULL;

    return novoVeic;
}

veiculo* cadastrarVeiculo(veiculo *aux) {
    veiculo *novoVeic = novoVeiculo();

    printf("\nDigite o nome do proprietário do veiculo: ");
    fgets(novoVeic->prop, sizeof(novoVeic->prop), stdin);
    while (getchar() != '\n');

    printf("Qual o tipo de combustível? Álcool/Diesel/Gasolina ");
    fgets(novoVeic->combustivel, sizeof(novoVeic->combustivel), stdin);

    printf("Digite o modelo do veículo: ");
    fgets(novoVeic->modelo, sizeof(novoVeic->modelo), stdin);
    while (getchar() != '\n');

    printf("Digite a cor do veículo: ");
    fgets(novoVeic->cor, sizeof(novoVeic->cor), stdin);
    while (getchar() != '\n');

    printf("Digite o número do chassi: ");
    scanf("%d", &novoVeic->chassi);
    while (getchar() != '\n');

    printf("Digite o ano de fabricação: ");
    scanf("%d", &novoVeic->ano);

    printf("Digite a placa do veículo: ");
    fgets(novoVeic->placa, sizeof(novoVeic->placa), stdin);
    while (getchar() != '\n');

    novoVeic->prox = NULL;


    if(aux == NULL) {
        aux = novoVeic;
    } else {
        veiculo *atual = aux; 

        while(atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novoVeic;
    }

    return aux;
}

void listarPropData(veiculo *aux) {
    veiculo *atual = aux; 
    int tes = 0;

    if(atual == NULL) {
        printf("Nenhum veículo registrado...");
        return; 
    } else {
        while(atual != NULL) {
            if(atual->ano >= 2010 && strcmp(atual->combustivel, "diesel") == 0) {
                printf("----------------------------------");
                printf("\n");
                printf("Proprietário: %s", atual->prop);
                printf("\n");
                tes++;
        }

            atual = atual->prox;
        }

        if(tes == 0) {
            printf("Não foi encontrado nenhum veículo com os filtros em questão...");
        }
    }

}

void listarPlacas(veiculo *aux) {
    veiculo *atual = aux;
    int tes = 0;

    while (atual != NULL) {
        char primeiraLetra = atual->placa[0];
        int ultimoNum = atual->placa[7]; 
    
        if(primeiraLetra == 'j' || primeiraLetra == 'J') {
            if(ultimoNum == 0 || ultimoNum == 2 || ultimoNum == 4 || ultimoNum == 7) {
                 printf("----------------------------------");
                printf("\n");
                printf("Proprietário: %s", atual->prop);
                printf("\n");
                printf("Placa: %s", atual->placa);
                printf("\n");
                printf("----------------------------------");
                tes++;
            }
        }
        
        atual = atual->prox;
    }

    if(tes == 0) {
         printf("Não foi encontrado nenhum veículo com os filtros em questão...");
    }
}

veiculo* excluirProduto(veiculo *aux, int codigo) {
    veiculo *anterior = NULL;
    veiculo *atual = aux;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->codigo == codigo) {
        if (anterior != NULL) {
            // Excluir depois do primeiro
            anterior->prox = atual->prox;
        } else {
            // Excluir o primeiro elemento
            aux = atual->prox;
        }

        free(atual);
        printf("Produto excluído com sucesso\n");
    } else {
        printf("Produto não encontrado\n");
    }

    return aux; 
}


int main() {

    int opcao; 
    veiculo *aux =  iniciarLista(); 

    do{ 

        printf("\n1 - Registrar novo veículo");
        printf("\n2 - Listar proprietários cujos carros são de 2010 ou superior e que sejam movidos a diesel");
        printf("\n3 - Listar placas que comecem com J e terminem com 0, 2, 4 ou 7 e seus proprietários");
        printf("\n4 - Listar modelo e a cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par");
        printf("\n5 - Realizar troca de proprietário para carros com placas que não possuam nenhum dígito igual a zero");
        printf("\n0 - Sair");
        printf("\n");

        scanf("%d", &opcao); 

        switch(opcao) {
            case 1: 
                aux = cadastrarVeiculo(aux);
            break;

            case 2: 
                listarPropData(aux);
            break;

            case 3: 
                ListarPlacas(aux);
            break;

            case 4: 
                printf("Digite o código que deseja excluir:");
                scanf("%d", &codigo);

                aux = excluirProduto(aux, codigo);
            break;
        }

    }while (opcao != 0);

    return 0;
}