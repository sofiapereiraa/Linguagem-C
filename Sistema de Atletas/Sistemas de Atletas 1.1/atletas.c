#include <stdio.h>
#include <string.h>
#include <ctype.h>
void limparTela();
void pause();
int validarNome(char nome[]);
int validarIdade(int idade);
int validarCpf(char cpf[]);
int validarAltura(float altura);
int validarPeso(float peso);
int validarPosicao(char posicao[]);

typedef struct
{
    char nome[60];
    int idade;
    float altura;
    float peso;
    char posicao[20];
} Atleta;

typedef struct
{
    int partidasJogadas;
    int pontosporPartidas[100];
    int bloqueiosporPartida[100];
    int acePorPartidas[100];
    int passesPorPartidas[100];
    float mediaPontos;
    float mediaBloqueios;
    float mediaAces;
    float mediaPasses;
} Desempenho;

typedef struct
{
    int Id;
    char cpf[13];
    Atleta documentos;
    Desempenho desempenho;
} Identificacao;

void Cadastro(Identificacao atletas[], int *id, int *proximoId);
void editarAtleta(Identificacao atletas[], int *id);
void removerAtleta(Identificacao atletas[], int *id);
void FazerRelatorio(Identificacao atletas[], int *id);
void VerRelatorio(Identificacao atletas[], int *id);

int main()
{
    int id = 0;
    int opcao;
    Identificacao atletas[99];
    int status = 1;
    int c;
    char busca[50];
    int proximoId = 1;

    while (status)
    {
        printf("\n ===  CONTROLE DE ELENCO DE VOLEIBOL === \n");
        printf("Cadastre, consulte e acompanheo o desempenho dos atletas.\n");
        printf("Escolha uma das alternativas abaixo: \n");
        printf("1 - Cadastrar atletas.\n");
        printf("2 - Listar atletas cadastrados.\n");
        printf("3 - Buscar atletas cadastrados.\n");
        printf("4 - Editar atletas.\n");
        printf("5 - Remover atletas.\n");
        printf("6 - Fazer relatorios.\n");
        printf("7 - Ver relatorios.\n");
        printf("8 - Sair.\n");
        printf("Alternativa: ");
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (opcao)
        {
        case 1:
        {
            limparTela();
            Cadastro(atletas, &id, &proximoId);
            break;
        }

        case 2:
        {
            limparTela();
            printf("\n === Lista de atletas cadastrados === \n");
            if (id == 0)
            {
                printf("Nenhum atleta cadastrado. \n");
                pause();
                break;
            }
            for (int i = 0; i < id; i++)
            {
                printf("\n");
                printf("Atleta de ID: %d\n", atletas[i].Id);
                printf("Nome: %s\n", atletas[i].documentos.nome);
                printf("CPF: %s\n", atletas[i].cpf);
                printf("Idade: %d\n", atletas[i].documentos.idade);
                printf("Altura: %.2f\n", atletas[i].documentos.altura);
                printf("Peso: %.2f\n", atletas[i].documentos.peso);
                printf("Posicao: %s\n", atletas[i].documentos.posicao);
            }
            pause();
            break;
        }
        case 3:
        {
            limparTela();
            printf("\n === Busca ===\n");
            printf("Digete o CPF do atleta buscado: ");
            fgets(busca, sizeof(busca), stdin);
            busca[strcspn(busca, "\n")] = '\0';
            int encontrado = 0;

            for (int i = 0; i < id; i++)
            {
                if (strcmp(atletas[i].cpf, busca) == 0)
                {
                    printf("Atleta encontrado!\n\n");
                    printf("Atleta de ID: %d\n", atletas[i].Id);
                    printf("Nome: %s\n", atletas[i].documentos.nome);
                    printf("CPF: %s\n", atletas[i].cpf);
                    printf("Idade: %d\n", atletas[i].documentos.idade);
                    printf("Altura: %.2f\n", atletas[i].documentos.altura);
                    printf("Peso: %.2f\n", atletas[i].documentos.peso);
                    printf("Posicao: %s\n", atletas[i].documentos.posicao);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Atleta nao encontrado!\n");
            }
            pause();
            break;
        }
        case 4:
        {
            limparTela();
            editarAtleta(atletas, &id);
            break;
        }
        case 5:
        {
            limparTela();
            removerAtleta(atletas, &id);
            break;
        }
        case 6:
        {
            limparTela();
            FazerRelatorio(atletas, &id);
            break;
        }
        case 7:
        {
            limparTela();
            VerRelatorio(atletas, &id);
            break;
        }
        case 8:
        {
            limparTela();
            printf("Obrigado por usar o sistema!\n");
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

void Cadastro(Identificacao atletas[], int *id, int *proximoId)
{
    if (*id >= 99)
    {
        printf("Limite de atletas cadastrados atingido!\n");
        pause();
        return;
    }
    char entrada[20];
    atletas[*id].Id = *proximoId;
    (*proximoId)++;
    printf("\n === Cadastro de atletas === \n");
    printf("Atleta #%d\n", atletas[*id].Id);

    do
    {
        printf("Nome da Atleta: ");
        fgets(atletas[*id].documentos.nome,
              sizeof(atletas[*id].documentos.nome),
              stdin);

        atletas[*id].documentos.nome[strcspn(atletas[*id].documentos.nome, "\n")] = '\0';

        if (!validarNome(atletas[*id].documentos.nome))
        {
            printf("Nome invalido! Digite pelo menos 3 letras e sem numeros.\n");
        }

    } while (!validarNome(atletas[*id].documentos.nome));

    do
    {
        printf("Idade: ");
        fgets(entrada, sizeof(entrada), stdin);

        sscanf(entrada, "%d", &atletas[*id].documentos.idade);

        if (!validarIdade(atletas[*id].documentos.idade))
        {
            printf("Idade invalida! Digite um valor entre 1 e 99.\n");
        }

    } while (!validarIdade(atletas[*id].documentos.idade));

    do
    {
        printf("Altura: ");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%f", &atletas[*id].documentos.altura);

        if (!validarAltura(atletas[*id].documentos.altura))
        {
            printf("Altura invalida! Digite um valor entre 1.00 e 2.50.\n");
        }
    } while (!validarAltura(atletas[*id].documentos.altura));

    do
    {

        printf("Peso: ");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%f", &atletas[*id].documentos.peso);

        if (!validarPeso(atletas[*id].documentos.peso))
        {
            printf("Peso invalido! Digite um valor entre 20 e 250.\n");
        }

    } while (!validarPeso(atletas[*id].documentos.peso));

    do
    {
        printf("Posicao: ");
        fgets(atletas[*id].documentos.posicao,
              sizeof(atletas[*id].documentos.posicao),
              stdin);

        atletas[*id].documentos.posicao[strcspn(atletas[*id].documentos.posicao, "\n")] = '\0';

        if (!validarPosicao(atletas[*id].documentos.posicao))
        {
            printf("Posicao invalida! Digite uma das posicoes validas.\n");
        }
    } while (!validarPosicao(atletas[*id].documentos.posicao));

    do
    {
        printf("CPF (somente numeros): ");
        fgets(atletas[*id].cpf,
              sizeof(atletas[*id].cpf),
              stdin);
        atletas[*id].cpf[strcspn(atletas[*id].cpf, "\n")] = '\0';

        if (!validarCpf(atletas[*id].cpf))
        {
            printf("CPF invalido! Digite exatamente 11 numeros.\n");
        }

    } while (!validarCpf(atletas[*id].cpf));

    (*id)++;
    printf("\nAtleta cadastrada com sucesso!\n");
    pause();
}
void editarAtleta(Identificacao atletas[], int *id)
{
    int escolhaEditar;
    int encontrado = 0;
    char entrada[20];
    int c;
    char busca[50];

    printf("\n=== Editar Atleta ===\n");
    printf("Digite o CPF do atleta: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int i = 0; i < *id; i++)
    {
        if (strcmp(atletas[i].cpf, busca) == 0)
        {
            encontrado = 1;
            printf("Atleta encontrado!\n\n");
            printf("Atleta de ID: %d\n", atletas[i].Id);
            printf("Nome: %s\n", atletas[i].documentos.nome);
            printf("CPF: %s\n", atletas[i].cpf);
            printf("Idade: %d\n", atletas[i].documentos.idade);
            printf("Altura: %.2f\n", atletas[i].documentos.altura);
            printf("Peso: %.2f\n", atletas[i].documentos.peso);
            printf("Posicao: %s\n", atletas[i].documentos.posicao);
            pause();
            limparTela();
            printf("Escolha o que deve ser editado.\n");
            printf("1 - Editar nome.\n");
            printf("2 - Editar idade.\n");
            printf("3 - Editar altura.\n");
            printf("4 - Editar peso.\n");
            printf("5 - Editar posicao.\n");
            printf("6- Editar CPF.\n");
            printf("7- Sair.\n");
            printf("Alternativa: ");
            scanf("%d", &escolhaEditar);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            switch (escolhaEditar)
            {
            case 1:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("Nome: ");
                    fgets(atletas[i].documentos.nome, sizeof(atletas[i].documentos.nome), stdin);
                    atletas[i].documentos.nome[strcspn(atletas[i].documentos.nome, "\n")] = '\0';

                    if (!validarNome(atletas[i].documentos.nome))
                    {
                        printf("Nome invalido! Digite pelo menos 3 letras e sem numeros.\n");
                    }

                } while (!validarNome(atletas[i].documentos.nome));

                printf("Nome atualizado com sucesso!\n");
                pause();
                break;
            }
            case 2:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("Idade: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    sscanf(entrada, "%d", &atletas[i].documentos.idade);

                    if (!validarIdade(atletas[i].documentos.idade))
                    {
                        printf("Idade invalida! Digite um valor entre 1 e 99.\n");
                    }

                } while (!validarIdade(atletas[i].documentos.idade));

                printf("Idade atualizada com sucesso!\n");
                pause();
                break;
            }
            case 3:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("Altura: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    sscanf(entrada, "%f", &atletas[i].documentos.altura);

                    if (!validarAltura(atletas[i].documentos.altura))
                    {
                        printf("Altura invalida! Digite um valor entre 1.00 e 2.50.\n");
                    }
                } while (!validarAltura(atletas[i].documentos.altura));

                printf("Altura atualizada com sucesso!\n");
                pause();
                break;
            }

            case 4:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("Peso: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    sscanf(entrada, "%f", &atletas[i].documentos.peso);

                    if (!validarPeso(atletas[i].documentos.peso))
                    {
                        printf("Peso invalido! Digite um valor entre 20 e 250.\n");
                    }

                } while (!validarPeso(atletas[i].documentos.peso));

                printf("Peso atualizado com sucesso!\n");
                pause();
                break;
            }

            case 5:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("Posicao: ");
                    fgets(atletas[i].documentos.posicao, sizeof(atletas[i].documentos.posicao), stdin);
                    atletas[i].documentos.posicao[strcspn(atletas[i].documentos.posicao, "\n")] = '\0';

                    if (!validarPosicao(atletas[i].documentos.posicao))
                    {
                        printf("Posicao invalida! Digite uma das posicoes validas.\n");
                    }
                } while (!validarPosicao(atletas[i].documentos.posicao));

                printf("Posicao atualizada com sucesso!\n");
                pause();
                break;
            }
            case 6:
            {
                do
                {
                    printf("\n=== Editor ===\n ");
                    printf("CPF: ");
                    fgets(atletas[i].cpf, sizeof(atletas[i].cpf), stdin);
                    atletas[i].cpf[strcspn(atletas[i].cpf, "\n")] = '\0';

                    if (!validarCpf(atletas[i].cpf))
                    {
                        printf("CPF invalido! Digite exatamente 11 numeros.\n");
                    }

                } while (!validarCpf(atletas[i].cpf));
                printf("CPF atualizado com sucesso!\n");
                pause();
                break;
            }
            case 7:
            {
                printf("Saindo de editar atleta...");
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
        printf("Atleta nao encontrado !");
        pause();
    }
}

void removerAtleta(Identificacao atletas[], int *id)
{
    char busca[50];
    int encontrado = 0;
    int c;
    int confirmar;
    printf("\n === Remover atleta ===\n");
    printf("Digite o CPF do atleta que deseja remover: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int i = 0; i < *id; i++)
    {
        if (strcmp(atletas[i].cpf, busca) == 0)
        {
            printf("Atleta encontrado!\n\n");
            printf("Atleta de ID: %d\n", atletas[i].Id);
            printf("Nome: %s\n", atletas[i].documentos.nome);
            printf("CPF: %s\n", atletas[i].cpf);
            printf("Idade: %d\n", atletas[i].documentos.idade);
            printf("Altura: %.2f\n", atletas[i].documentos.altura);
            printf("Peso: %.2f\n", atletas[i].documentos.peso);
            printf("Posicao: %s\n", atletas[i].documentos.posicao);
            pause();
            encontrado = 1;

            printf("Deseja remover este atleta ?\n ");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            printf("Alternativa:");
            scanf("%d", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            switch (confirmar)
            {
            case 1:
            {
                for (int j = i; j < *id - 1; j++)
                {
                    atletas[j] = atletas[j + 1];
                }
                (*id)--;
                printf("Atleta removido com sucesso!\n");
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
        printf("Atleta nao encontrado!\n");
        pause();
    }
}

void FazerRelatorio(Identificacao atletas[], int *id)
{
    char entrada[50];
    char busca[50];
    printf("\n === Fazer relatorios ===\n");
    printf("Digite o CPF da atleta que deseja fazer o relatorio: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;

    for (int i = 0; i < *id; i++)
    {
        if (strcmp(atletas[i].cpf, busca) == 0)
        {
            printf("Atleta encontrado!\n\n");
            printf("Atleta de ID: %d\n", atletas[i].Id);
            printf("Nome: %s\n", atletas[i].documentos.nome);
            printf("CPF: %s\n", atletas[i].cpf);
            printf("Idade: %d\n", atletas[i].documentos.idade);
            printf("Altura: %.2f\n", atletas[i].documentos.altura);
            printf("Peso: %.2f\n", atletas[i].documentos.peso);
            printf("Posicao: %s\n", atletas[i].documentos.posicao);

            encontrado = 1;
            printf("\n");
            printf("Quantas partidas jogadas: ");
            fgets(entrada, sizeof(entrada), stdin);
            sscanf(entrada, "%d", &atletas[i].desempenho.partidasJogadas);

            for (int j = 0; j < atletas[i].desempenho.partidasJogadas; j++)
            {
                printf("Digite o total de pontos por partida: Partida %d - pontos: ", j + 1);
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &atletas[i].desempenho.pontosporPartidas[j]);
            }
            for (int j = 0; j < atletas[i].desempenho.partidasJogadas; j++)
            {
                printf("Digite o total de bloqueios por partida: Partida %d - Bloqueios: ", j + 1);
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &atletas[i].desempenho.bloqueiosporPartida[j]);
            }
            for (int j = 0; j < atletas[i].desempenho.partidasJogadas; j++)
            {
                printf(" Digite o total de aces por partida: Partida %d - Aces: ", j + 1);
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &atletas[i].desempenho.acePorPartidas[j]);
            }
            for (int j = 0; j < atletas[i].desempenho.partidasJogadas; j++)
            {
                printf("Digite o total de passes por partida: Partida %d - Passes: ", j + 1);
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &atletas[i].desempenho.passesPorPartidas[j]);
            }
            printf("\nRelatorio cadastrado com sucesso!");
            break;
        }
    }
    if (!encontrado)
    {
        printf("Atleta nao encontrado!\n");
    }
    pause();
}

void VerRelatorio(Identificacao atletas[], int *id)
{

    char busca[50];
    printf("\n === Relatorio do atleta ===\n");
    printf("Digite o CPF da atleta que deseja visualizar o relatorio: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;
    int somaPontos = 0;
    int somaBloqueios = 0;
    int somaAces = 0;
    int somaPasses = 0;

    for (int i = 0; i < *id; i++)
    {
        if (strcmp(atletas[i].cpf, busca) == 0)
        {
            encontrado = 1;
            printf("Atleta encontrado!\n\n");
            printf("Atleta de ID: %d\n", atletas[i].Id);
            printf("Nome: %s\n", atletas[i].documentos.nome);
            printf("Altura: %.2f\n", atletas[i].documentos.altura);
            printf("Peso: %.2f\n", atletas[i].documentos.peso);
            printf("Posicao: %s\n", atletas[i].documentos.posicao);

            printf("\n===== RELATORIO =====\n");
            printf("Partidas jogadas: %d\n", atletas[i].desempenho.partidasJogadas);

            for (int j = 0; j < atletas[i].desempenho.partidasJogadas; j++)
            {
                somaPontos += atletas[i].desempenho.pontosporPartidas[j];
                somaBloqueios += atletas[i].desempenho.bloqueiosporPartida[j];
                somaAces += atletas[i].desempenho.acePorPartidas[j];
                somaPasses += atletas[i].desempenho.passesPorPartidas[j];

                printf("\n=== Partida %d ===\n", j + 1);
                printf("Pontos: %d\n", atletas[i].desempenho.pontosporPartidas[j]);
                printf("Bloqueios: %d\n", atletas[i].desempenho.bloqueiosporPartida[j]);
                printf("Aces: %d\n", atletas[i].desempenho.acePorPartidas[j]);
                printf("Passes: %d\n", atletas[i].desempenho.passesPorPartidas[j]);
            }
            if (atletas[i].desempenho.partidasJogadas > 0)
            {
                float mediaPontos = (float)somaPontos / atletas[i].desempenho.partidasJogadas;
                float mediaBloqueios = (float)somaBloqueios / atletas[i].desempenho.partidasJogadas;
                float mediaAces = (float)somaAces / atletas[i].desempenho.partidasJogadas;
                float mediaPasses = (float)somaPasses / atletas[i].desempenho.partidasJogadas;

                printf("\n=== MEDIAS ===\n");
                printf("Media de pontos: %.2f\n", mediaPontos);
                printf("Media de bloqueios: %.2f\n", mediaBloqueios);
                printf("Media de aces: %.2f\n", mediaAces);
                printf("Media de passes: %.2f\n", mediaPasses);
            }
            else
            {
                printf("\nNenhuma partida cadastrada para esta atleta.\n");
            }
            break;
        }
    }
    if (!encontrado)
    {
        printf("Atleta nao encontrado!\n");
    }
    pause();
}

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

int validarNome(char nome[])
{
    if (strlen(nome) < 3)
        return 0;

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!(isalpha((unsigned char)nome[i]) || nome[i] == ' '))
        {
            return 0;
        }
    }
    return 1;
}

int validarIdade(int idade)
{
    if (idade < 1 || idade > 99)
    {
        return 0;
    }

    return 1;
}

int validarCpf(char cpf[])
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }

    for (int i = 0; cpf[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)cpf[i]))
        {
            return 0;
        }
    }

    return 1;
}

int validarAltura(float altura)
{
    return altura >= 1.00 && altura <= 2.50;
}

int validarPeso(float peso)
{
    return peso >= 20 && peso <= 250;
}

int validarPosicao(char posicao[])
{
    if (strcmp(posicao, "Levantadora") == 0 ||
        strcmp(posicao, "Levantador") == 0 ||
        strcmp(posicao, "Ponteira") == 0 ||
        strcmp(posicao, "Ponteiro") == 0 ||
        strcmp(posicao, "Oposta") == 0 ||
        strcmp(posicao, "Oposto") == 0 ||
        strcmp(posicao, "Central") == 0 ||
        strcmp(posicao, "Libero") == 0)
    {
        return 1;
    }
    return 0;
}