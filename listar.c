#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_TITULO 100
#define MAX_AUTOR 100


typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
} Livro;

// Cadastrar um novo Livro
void cadastrar_livro(Livro livros[], int *qtd_livros) {
    if (*qtd_livros >= MAX_LIVROS) {
        printf("Erro: Não é possível cadastrar mais livros. Limite de livros atingido.\n");
        return;
    }

    Livro novo_livro;

    printf("Digite o título do livro: ");
    fgets(novo_livro.titulo, MAX_TITULO, stdin);
    novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(novo_livro.autor, MAX_AUTOR, stdin);
    novo_livro.autor[strcspn(novo_livro.autor, "\n")] = '\0';

    // Adicionando o livro à lista
    livros[*qtd_livros] = novo_livro;
    (*qtd_livros)++;

    printf("Livro '%s' de '%s' cadastrado com sucesso!\n", novo_livro.titulo, novo_livro.autor);
}

//remover livro
void remover_livro(Livro livros[], int *qtd_livros) {
    if (*qtd_livros == 0) {
        printf("Erro: Não há livros cadastrados para remover.\n");
        return;
    }

    //livro cadsastrado
    printf("Livros cadastrados:\n");
    for (int i = 0; i < *qtd_livros; i++) {
        printf("%d - Título: %s, Autor: %s\n", i + 1, livros[i].titulo, livros[i].autor);
    }

    int indice;
    printf("Digite o número do livro que deseja remover: ");
    scanf("%d", &indice);
    getchar();

    if (indice < 1 || indice > *qtd_livros) {
        printf("Erro: Número inválido.\n");
        return;
    }

    // Remover o livro
    for (int i = indice - 1; i < *qtd_livros - 1; i++) {
        livros[i] = livros[i + 1];
    }

    (*qtd_livros)--;
    printf("Livro removido com sucesso!\n");
}

//listar
void listar_livros(Livro livros[], int *qtd_livros) {
    if (*qtd_livros == 0) {
        printf("Não há livros cadastrados.\n");
        return;
    }

    printf("Livros cadastrados:\n");
    for (int i = 0; i < *qtd_livros; i++) {
        printf("%d - Título: %s, Autor: %s\n", i + 1, livros[i].titulo, livros[i].autor);
    }
}

//menu
void menu(Livro livros[], int *qtd_livros) {
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Remover livro\n");
        printf("3. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        getchar();
	printf("\n");

        switch (opcao) {
            case 1:
                cadastrar_livro(livros, qtd_livros);
                break;
            case 2:
                remover_livro(livros, qtd_livros);
                break;
            case 3:
                listar_livros(livros, qtd_livros);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    Livro livros[MAX_LIVROS];
    int qtd_livros = 0;

    menu(livros, &qtd_livros);
    return 0;
}
