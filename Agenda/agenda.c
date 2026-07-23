#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void pause()
{
    int x;
    printf("\nPressione Enter para continuar...");
    while ((x = getchar()) != '\n' && x != EOF)
        ;
}

void limparTela()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

typedef struct
{
    char nome[50];
    char email[50];
    char telefone[20];

} Contato;

int validarNome(char nome[])
{
    if (strlen(nome) < 3)
    {
        return 0;
    }

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (isdigit(nome[i]))
        {
            return 0;
        }
    }

    return 1;
}

int validarEmail(char email[])
{
    int temArroba = 0;
    int temPonto = 0;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            temArroba = 1;

        if (email[i] == '.')
            temPonto = 1;
    }

    if (temArroba && temPonto)
        return 1;

    return 0;
}

int validarTelefone(char telefone[])
{
    if (strlen(telefone) != 11)
    {
        return 0;
    }

    for (int i = 0; telefone[i] != '\0'; i++)
    {
        if (!isdigit(telefone[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char busca[50];
    int quantidade = 0;
    int capacidade = 0;
    int opcao;
    int status = 1;
    int c;

    int editar;
    int confirmar;

    Contato *agenda = NULL;

    while (status)
    {
        printf("\n === AGENDA DE CONTATOS ===\n");
        printf("1- Adicionar contato\n");
        printf("2- Listar contatos\n");
        printf("3- Buscar contato pelo nome\n");
        printf("4- Editar contato\n");
        printf("5- Excluir contato\n");
        printf("6- Salvar contatos em arquivo\n");
        printf("7- Visualizar contatos em arquivo\n");
        printf("8- Sair\n");
        printf("Alternativa: ");
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (opcao)
        {

        case 1:
        {
            printf("\n === Adicionar Contatos ===\n");

            if (capacidade == 0)
            {
                capacidade = 5;

                agenda = malloc(capacidade * sizeof(Contato));

                if (agenda == NULL)
                {
                    printf("Erro ao alocar memória!\n");
                    break;
                }
            }

            if (quantidade == capacidade)
            {

                capacidade *= 2;
                Contato *temp = realloc(agenda, capacidade * sizeof(Contato));

                if (temp == NULL)
                {
                    printf("Erro ao realocar memoria!\n");
                    break;
                }

                agenda = temp;
            }
            do
            {
                printf("Nome: ");
                fgets(agenda[quantidade].nome, 50, stdin);
                agenda[quantidade].nome[strcspn(agenda[quantidade].nome, "\n")] = '\0';

                if (!validarNome(agenda[quantidade].nome))
                {
                    printf("Nome invalido! Tente novamente.\n");
                }

            } while (!validarNome(agenda[quantidade].nome));

            do
            {
                printf("Email: ");
                fgets(agenda[quantidade].email, 50, stdin);
                agenda[quantidade].email[strcspn(agenda[quantidade].email, "\n")] = '\0';

                if (!validarEmail(agenda[quantidade].email))
                {
                    printf("Email invalido! Tente novamente.\n");
                }

            } while (!validarEmail(agenda[quantidade].email));

            do
            {
                printf("Telefone: ");
                fgets(agenda[quantidade].telefone, 20, stdin);
                agenda[quantidade].telefone[strcspn(agenda[quantidade].telefone, "\n")] = '\0';

                if (!validarTelefone(agenda[quantidade].telefone))
                {
                    printf("Telefone invalido! Tente novamente.\n");
                }

            } while (!validarTelefone(agenda[quantidade].telefone));

            quantidade++;

            printf("Contato cadastrado com sucesso!\n");
            pause();

            break;
        }

        case 2:
        {
            limparTela();
            printf("\n === Lista de Contatos === \n");

            if (quantidade == 0)
            {
                printf("Nenhum contato cadastrado. \n");
                pause();
                break;
            }
            for (int i = 0; i < quantidade; i++)
            {
                printf("\n");
                printf("- Nome: %s\n", agenda[i].nome);
                printf("- Email: %s\n", agenda[i].email);
                printf("- Telefone: %s\n", agenda[i].telefone);
            }
            pause();
            break;
        }

        case 3:
        {
            limparTela();
            printf("\n === BUSCA === \n");

            printf("Digite o nome da pessoa procurada: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            int encontrado = 0;

            for (int i = 0; i < quantidade; i++)
            {

                if (strcmp(agenda[i].nome, busca) == 0)
                {
                    printf("\n Contato Encontrado ! \n");
                    printf("- Nome: %s\n", agenda[i].nome);
                    printf("- Email: %s\n", agenda[i].email);
                    printf("- Telefone: %s\n", agenda[i].telefone);

                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Contato nao encontrado!\n");
            }

            pause();
            break;
        }

        case 4:
        {
            limparTela();

            printf("\n === Editar Contato ===\n");

            printf("Digite o nome do contato: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            int encontrado = 0;

            for (int i = 0; i < quantidade; i++)
            {
                if (strcmp(agenda[i].nome, busca) == 0)
                {

                    encontrado = 1;
                    printf("\n Contato:\n");
                    printf("- Nome: %s\n", agenda[i].nome);
                    printf("- Email: %s\n", agenda[i].email);
                    printf("- Telefone: %s\n", agenda[i].telefone);
                    pause();

                    printf("Escolha o que deve ser editado.\n");
                    printf("1 - Editar nome.\n");
                    printf("2 - Editar email.\n");
                    printf("3 - Editar telefone.\n");
                    printf("4 - Sair\n");
                    scanf("%d", &editar);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;

                    switch (editar)
                    {
                    case 1:
                    {
                        do
                        {
                            printf("Novo nome: ");
                            fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
                            agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0';

                            if (!validarNome(agenda[i].nome))
                            {
                                printf("Nome invalido! Tente novamente.\n");
                            }

                        } while (!validarNome(agenda[i].nome));

                        printf("Nome atualizado com sucesso!\n");
                        pause();
                        break;
                    }
                    case 2:
                    {
                        do
                        {
                            printf("Novo email: ");
                            fgets(agenda[i].email, sizeof(agenda[i].email), stdin);
                            agenda[i].email[strcspn(agenda[i].email, "\n")] = '\0';

                            if (!validarEmail(agenda[i].email))
                            {
                                printf("Email invalido! Tente novamente.\n");
                            }

                        } while (!validarEmail(agenda[i].email));

                        printf("Email atualizado com sucesso!\n");
                        pause();
                        break;
                    }
                    case 3:
                    {
                        do
                        {
                            printf("Novo telefone: ");
                            fgets(agenda[i].telefone, sizeof(agenda[i].telefone), stdin);
                            agenda[i].telefone[strcspn(agenda[i].telefone, "\n")] = '\0';

                            if (!validarTelefone(agenda[i].telefone))
                            {
                                printf("Telefone invalido! Tente novamente.\n");
                            }

                        } while (!validarTelefone(agenda[i].telefone));

                        printf("Telefone atualizado com sucesso!\n");
                        pause();
                        break;
                    }
                    case 4:
                    {
                        printf("Saindo de editar contato...");
                        pause();
                        break;
                    }
                    default:
                    {
                        printf("Opcao invalida. Tente novamente.\n");
                        pause();
                        break;
                    }
                    break;
                    }
                }
            }
            if (!encontrado)
            {
                printf("Contato nao encontrado !");
                pause();
            }

            break;
        }

        case 5:
        {
            limparTela();
            printf("\n === Remover Contato ===\n");

            printf("Digite o nome do contato: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';

            int encontrado = 0;

            for (int i = 0; i < quantidade; i++)
            {
                if (strcmp(agenda[i].nome, busca) == 0)
                {
                    encontrado = 1;
                    printf("\n Contato: ");
                    printf("- Nome: %s\n", agenda[i].nome);
                    printf("- Email: %s\n", agenda[i].email);
                    printf("- Telefone: %s\n", agenda[i].telefone);

                    printf("Deseja remover este contato ?\n ");
                    printf("1 - Sim\n");
                    printf("2 - Nao\n");
                    printf("Alternativa: ");
                    scanf("%d", &confirmar);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;

                    switch (confirmar)
                    {
                    case 1:
                    {
                        for (int j = i; j < quantidade - 1; j++)
                        {
                            agenda[j] = agenda[j + 1];
                        }
                        quantidade--;
                        printf("Contato removido com sucesso!\n");
                        pause();
                        break;
                    }

                    case 2:
                    {
                        printf("Remocao cancelada.\n");
                        pause();
                        break;
                    }
                    default:
                    {
                        printf("Opcao invalida.\n");
                        pause();
                        break;
                    }
                    }
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Contato nao encontrado!\n");
                pause();
            }
            break;
        }

        case 6:
        {
            FILE *arquivo;

            arquivo = fopen("contatos.txt", "w");

            if (arquivo == NULL)
            {
                printf("Erro ao abrir arquivo!\n");
            }
            else
            {
                for (int i = 0; i < quantidade; i++)
                {
                    fprintf(arquivo, "%s\n", agenda[i].nome);
                    fprintf(arquivo, "%s\n", agenda[i].email);
                    fprintf(arquivo, "%s\n", agenda[i].telefone);
                }

                fclose(arquivo);

                printf("\n === Salvar Arquivo ===\n");
                printf("\nContatos salvos com sucesso!\n");
                pause();
            }
            break;
        }
        case 7:
        {
            FILE *arquivo = fopen("contatos.txt", "r");

            char linha[1000];

            if (arquivo)
            {
                printf("\n Dados lidos do arquivo: \n");

                while (fgets(linha, 1000, arquivo) != NULL)
                {
                    printf("\n - %s", linha);
                }

                fclose(arquivo);
            }
            else
            {
                printf("\n Erro ao abrir o arquivo!");
            }
            pause();
            break;
        }
        case 8:
        {
            limparTela();
            printf("Obrigado por usar o sistema!\n");

            free(agenda);
            agenda = NULL;

            status = 0;
            break;
        }
        default:
        {
            printf("Opcao invalida. Tente novamente.\n");
            pause();
            break;
        }
        }
    }
}