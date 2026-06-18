#include <stdio.h>
#include <string.h>

typedef struct
{
    char nomeLivro[50];
    char autor[50];
    int anoPublicacao;
    char editora[50];
} Cadastro;

typedef struct
{
    int Id;
    Cadastro cadastro;
} Identificador;

int main()
{

    int id = 0;
    int opcao;
    Identificador livros[99];
    int status = 1;
    int c;
    char busca[50];
    int emprestado[99] = {0};

    while (status)
    {

        printf("\e[1;1H\e[2J");
        printf(" BEM VINDO AO SISTEMA DE BIBLIOTECA \n");
        printf("Nosso sistema de biblioteca armazena somente 99 livros,por isso, tome cuidado com a quantidade de livros cadastrados.\n");
        printf("Escolha uma das alternativas abaixo: \n");

        printf("1 - Cadastrar livros.\n");
        printf("2 - Listar livros cadastrados.\n");
        printf("3 - Buscar livros cadastros.\n");
        printf("4 - Emprestar livros.\n");
        printf("5 - Devolver livros.\n");
        printf("6 - Sair.\n");

        printf("Alternativa:");
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (opcao)
        {
        case 1:
        {
            if (id >= 99)
            {
                printf("Limite de livros cadastrados atingido!\n");
                break;
            }

            livros[id].Id = id + 1;
            printf("Livro %d\n", livros[id].Id);

            printf("Digite o nome do livro: ");
            fgets(livros[id].cadastro.nomeLivro, sizeof(livros[id].cadastro.nomeLivro), stdin);
            livros[id].cadastro.nomeLivro[strcspn(livros[id].cadastro.nomeLivro, "\n")] = '\0';

            printf("Digite o nome do autor: ");
            fgets(livros[id].cadastro.autor, sizeof(livros[id].cadastro.autor), stdin);
            livros[id].cadastro.autor[strcspn(livros[id].cadastro.autor, "\n")] = '\0';

            printf("Digite o ano de publicacao: ");
            scanf("%d", &livros[id].cadastro.anoPublicacao);

            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("Digite a editora: ");
            fgets(livros[id].cadastro.editora, sizeof(livros[id].cadastro.editora), stdin);
            livros[id].cadastro.editora[strcspn(livros[id].cadastro.editora, "\n")] = '\0';

            printf("\nLivro cadastrado com sucesso!\n");
            id++;
            break;
        }
        case 2:
        {
            printf("LIVROS CADASTRADOS");

            if (id == 0)
            {
                printf("Nenhum livro cadastrado.\n");
                break;
            }

            for (int i = 0; i < id; i++)
            {
                printf("\n");
                printf("ID: %d\n", livros[i].Id);
                printf("Nome do livro: %s\n", livros[i].cadastro.nomeLivro);
                printf("Autor: %s\n", livros[i].cadastro.autor);
                printf("Ano de publicacao: %d\n", livros[i].cadastro.anoPublicacao);
                printf("Editora: %s\n", livros[i].cadastro.editora);
            }
        }
        break;

        case 3:
        {
            printf("Digite o nome do livro buscado: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (int i = 0; i < id; i++)
            {
                if (strcmp(livros[i].cadastro.nomeLivro, busca) == 0)
                {
                    printf("Livro encontrado:\n");
                    printf("ID: %d\n", livros[i].Id);
                    printf("Nome do livro: %s\n", livros[i].cadastro.nomeLivro);
                    printf("Autor: %s\n", livros[i].cadastro.autor);
                    printf("Ano de publicacao: %d\n", livros[i].cadastro.anoPublicacao);
                    printf("Editora: %s\n", livros[i].cadastro.editora);
                    break;
                }
                else if (i == id - 1)
                {
                    printf("Livro nao encontrado.\n");
                }
            }
            break;
        }
        case 4:
        {

            printf("Digite o nome do livro que deseja emprestar: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            if (id == 0)
            {
                printf("Nenhum livro cadastrado.\n");
                break;
            }
            for (int i = 0; i < id; i++)
            {
                if (strcmp(livros[i].cadastro.nomeLivro, busca) == 0)
                {
                    if (emprestado[i] == 0)
                    {
                        emprestado[i] = 1;
                        printf("Livro emprestado com sucesso!\n");
                    }
                    else
                    {
                        printf("Livro já está emprestado.\n");
                    }
                    break;
                }
                else if (i == id - 1)
                {
                    printf("Livro nao encontrado.\n");
                }
            }
            break;
        }
        case 5:
        {
            printf("Digite o nome do livro que deseja devolver: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            if (id == 0)
            {
                printf("Nenhum livro cadastrado.\n");
                break;
            }
            for (int i = 0; i < id; i++)
            {
                if (strcmp(livros[i].cadastro.nomeLivro, busca) == 0)
                {
                    if (emprestado[i] == 1)
                    {
                        emprestado[i] = 0;
                        printf("Livro devolvido com sucesso!\n");
                    }
                    else
                    {
                        printf("Livro nao esta emprestado.\n");
                    }
                    break;
                }
                else if (i == id - 1)
                {
                    printf("Livro nao encontrado.\n");
                }
            }
            break;
        }
        case 6:
        {
            printf("Obrigado por usar o sistema!\n");
            status = 0;
            break;
        }

        default:
        {
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
        }

        printf("\nPressione Enter para continuar...");
        getchar();
    }

    return 0;
}