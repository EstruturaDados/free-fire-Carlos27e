#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct { // STRUCT DO ITEM

    char nome[30];
    char tipo[20];
    int quantidade;

} Item;

void inserirItem(Item mochila[], int *quantidade){ // FUNÇÃO PARA INSERIR ITEM

    if(*quantidade >= MAX_ITENS){

        printf("\nA mochila esta cheia!\n");
        return;
    }

    printf("\n=== CADASTRAR ITEM ===\n");

    printf("Nome do item: ");
    fgets(mochila[*quantidade].nome, 30, stdin);
    mochila[*quantidade].nome[
        strcspn(mochila[*quantidade].nome, "\n")
    ] = '\0';

    printf("Tipo do item: ");
    fgets(mochila[*quantidade].tipo, 20, stdin);
    mochila[*quantidade].tipo[
        strcspn(mochila[*quantidade].tipo, "\n")
    ] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*quantidade].quantidade);

    getchar();

    (*quantidade)++;
    printf("\nItem cadastrado com sucesso!\n");
}

void removerItem(Item mochila[], int *quantidade){ // FUNÇÃO PARA REMOVER ITEM

    char nomeBusca[30];
    int i;
    int posicao = -1;

    if(*quantidade == 0){
        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // BUSCA DO ITEM

    for(i = 0; i < *quantidade; i++){

        if(strcmp(mochila[i].nome, nomeBusca) == 0){
            posicao = i;
            break;
        }
    }

    if(posicao == -1){ // ITEM NÃO ENCONTRADO
        printf("\nItem nao encontrado!\n");
        return;
    }

    for(i = posicao; i < *quantidade - 1; i++){ // DESLOCAR ELEMENTOS
        mochila[i] = mochila[i + 1];
    }

    (*quantidade)--;
    printf("\nItem removido com sucesso!\n");
}

void listarItens(Item mochila[], int quantidade){ // FUNÇÃO PARA LISTAR ITENS

    int i;

    if(quantidade == 0){

        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\n=========== ITENS DA MOCHILA ===========\n");

    for(i = 0; i < quantidade; i++){

        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

void buscarItem(Item mochila[], int quantidade){ // FUNÇÃO DE BUSCA SEQUENCIAL

    char nomeBusca[30];
    int i;

    if(quantidade == 0){

        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, 30, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for(i = 0; i < quantidade; i++){ // BUSCA SEQUENCIAL

        if(strcmp(mochila[i].nome, nomeBusca) == 0){

            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            return;
        }
    }

    printf("\nItem nao encontrado!\n");
}

int main(){ // FUNÇÃO PRINCIPAL

    Item mochila[MAX_ITENS];

    int quantidade = 0;
    int opcao;

    do{

        printf("\n====================================\n");
        printf("         MOCHILA DO JOGADOR         \n");
        printf("====================================\n");

        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        getchar();

        switch(opcao){

            case 1:
                inserirItem(mochila, &quantidade);
                listarItens(mochila, quantidade);
                break;

            case 2:
                removerItem(mochila, &quantidade);
                listarItens(mochila, quantidade);
                break;

            case 3:
                listarItens(mochila, quantidade);
                break;

            case 4:
                buscarItem(mochila, quantidade);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
