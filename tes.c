#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

typedef struct veiculo {
    char prop[50];
    char combustivel[30];
    char modelo[50];
    char cor[50];
    int chassi;
    int ano;
    char placa[8];  // Aumentar o tamanho da placa para incluir o caractere nulo
    struct veiculo *prox;
} veiculo;

veiculo* iniciarLista() {
    return NULL;
}

veiculo* novoVeiculo() {
    veiculo *novoVeic = (veiculo*)malloc(sizeof(veiculo));

    if (novoVeic == NULL) {
        printf("Não há memória suficiente...");
        exit(EXIT_FAILURE);
    }

    novoVeic->prox = NULL;

    return novoVeic;
}

void limparBuffer() {
    while (getchar() != '\n');
}

veiculo* cadastrarVeiculo(veiculo *aux) {
    veiculo *novoVeic = novoVeiculo();

    printf("\nDigite o nome do proprietário do veículo: ");
    fgets(novoVeic->prop, sizeof(novoVeic->prop), stdin);
    limparBuffer();

    printf("Qual o tipo de combustível? Álcool/Diesel/Gasolina ");
    fgets(novoVeic->combustivel, sizeof(novoVeic->combustivel), stdin);

    printf("Digite o modelo do veículo: ");
    fgets(novoVeic->modelo, sizeof(novoVeic->modelo), stdin);
    limparBuffer();

    printf("Digite a cor do veículo: ");
    fgets(novoVeic->cor, sizeof(novoVeic->cor), stdin);
    limparBuffer();

    printf("Digite o número do chassi: ");
    scanf("%d", &novoVeic->chassi);
    limparBuffer();

    printf("Digite o ano de fabricação: ");
    scanf("%d", &novoVeic->ano);
    limparBuffer();

    printf("Digite a placa do veículo: [abc-1234] ");
    fgets(novoVeic->placa, sizeof(novoVeic->placa), stdin);
    novoVeic->placa[strcspn(novoVeic->placa, "\n")] = '\0';
    limparBuffer();

    novoVeic->prox = NULL;

    if (aux == NULL) {
        aux = novoVeic;
    } else {
        veiculo *atual = aux;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoVeic;
    }

    return aux;
}

void listarPropData(veiculo *aux) {

    veiculo *atual = aux;
    int tes = 0;

    if (atual == NULL) {
        printf("Nenhum veículo registrado...");
        return;
    } else {
        while (atual != NULL) {
            if (atual->ano >= 2010 && strcasecmp(atual->combustivel, "diesel") == 0) {
                system("clear");
                printf("----------------------------------");
                printf("\n");
                printf("Proprietário: %s", atual->prop);
                printf("\n");
                tes++;
            }

            atual = atual->prox;
        }

        if (tes == 0) {
            printf("Não foi encontrado nenhum veículo com os filtros em questão...");
        }
    }
}

void listarPlacas(veiculo *aux) {
    veiculo *atual = aux;
    int tes = 0;

    while (atual != NULL) {
        if (strlen(atual->placa) == 8) {
            char primeiraLetra = atual->placa[0];
            int ultimoNum = atual->placa[7] - '0';

            if ((primeiraLetra == 'j' || primeiraLetra == 'J') &&
                (ultimoNum == 0 || ultimoNum == 2 || ultimoNum == 4 || ultimoNum == 7)) {
                system("cls"); 
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

    if (tes == 0) {
        printf("Não foi encontrado nenhum veículo com os filtros em questão...");
    }
}

void listarModelos(veiculo *aux) {
    veiculo *atual = aux;
    int tes = 0;

    while (atual != NULL) {
        char segundaLetra = atual->placa[1];
        int somaNum = atual->placa[3] + atual->placa[4] + atual->placa[5] + atual->placa[6];

        if ((segundaLetra == 'A' || segundaLetra == 'a' ||
             segundaLetra == 'E' || segundaLetra == 'e' ||
             segundaLetra == 'I' || segundaLetra == 'i' ||
             segundaLetra == 'O' || segundaLetra == 'o' ||
             segundaLetra == 'U' || segundaLetra == 'u') &&
            (somaNum % 2 == 0)) {
            system("cls");
            printf("----------------------------------");
            printf("\n");
            printf("Modelo: %s", atual->modelo);
            printf("\n");
            printf("Cor: %s", atual->cor);
            printf("\n");
            printf("----------------------------------");
            tes++;
        }

        atual = atual->prox;
    }

    if (tes == 0) {
        printf("Não foi encontrado nenhum veículo com os filtros em questão...");
    }
}

void liberarMemoria(veiculo *aux) {
    while (aux != NULL) {
        veiculo *temp = aux;
        aux = aux->prox;
        free(temp);
    }
}

int main() {
    int opcao;
    veiculo *aux = iniciarLista();

    do {
        system("clear");
        printf("\n1 - Registrar novo veículo");
        printf("\n2 - Listar proprietários cujos carros são de 2010 ou superior e que sejam movidos a diesel");
        printf("\n3 - Listar placas que comecem com J e terminem com 0, 2, 4 ou 7 e seus proprietários");
        printf("\n4 - Listar modelo e a cor dos veículos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numéricos fornece um número par");
        printf("\n5 - Realizar troca de proprietário para carros com placas que não possuam nenhum dígito igual a zero");
        printf("\n0 - Sair");
        printf("\n");

        scanf("%d", &opcao);
        limparBuffer();  // Adicionando limpeza do buffer

        switch (opcao) {
            case 1:
                aux = cadastrarVeiculo(aux);
                break;

            case 2:
                listarPropData(aux);
                break;

            case 3:
                listarPlacas(aux);
                break;

            case 4:
                listarModelos(aux);
                break;
        }

    } while (opcao != 0);

    liberarMemoria(aux);

    return 0;
}