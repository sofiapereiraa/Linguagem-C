#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char cpf[15];
    int turma;

    int t1, t2, t3;
    int p1, p2, p3;
} Cadastro;

typedef struct
{
    int Id;
    Cadastro cadastro;
} Aluno;

int main()
{
    int opcao;
    int status = 1;
    int c;
    int id = 0;

    Aluno alunos[99];

    while (status)
    {
        printf("\e[1;1H\e[2J");

        printf("SISTEMA DE ALUNOS\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Calcular media\n");
        printf("4 - Mostrar aprovado/reprovado\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            if (id >= 99)
            {
                printf("Limite de alunos atingido!\n");
                break;
            }

            while ((c = getchar()) != '\n' && c != EOF)
                ;

            alunos[id].Id = id + 1;

            printf("\nAluno de ID: %d\n", alunos[id].Id);

            printf("Digite o nome do aluno: ");
            fgets(alunos[id].cadastro.nome,
                  sizeof(alunos[id].cadastro.nome),
                  stdin);

            alunos[id].cadastro.nome[strcspn(alunos[id].cadastro.nome, "\n")] = '\0';

            printf("Digite o CPF do aluno: ");
            scanf("%14s", alunos[id].cadastro.cpf);

            printf("Digite a turma do aluno: ");
            scanf("%d", &alunos[id].cadastro.turma);

            printf("Digite as 3 notas dos trabalhos: ");
            scanf("%d %d %d",
                  &alunos[id].cadastro.t1,
                  &alunos[id].cadastro.t2,
                  &alunos[id].cadastro.t3);

            printf("Digite as 3 notas das provas: ");
            scanf("%d %d %d",
                  &alunos[id].cadastro.p1,
                  &alunos[id].cadastro.p2,
                  &alunos[id].cadastro.p3);

            printf("\nAluno cadastrado com sucesso!\n");

            id++;
            break;
        }

        case 2:
        {
            printf("\e[1;1H\e[2J");

            if (id == 0)
            {
                printf("Nenhum aluno cadastrado.\n");
                break;
            }

            for (int i = 0; i < id; i++)
            {
                printf("\n=====================\n");
                printf("ID: %d\n", alunos[i].Id);
                printf("Nome: %s\n", alunos[i].cadastro.nome);
                printf("CPF: %s\n", alunos[i].cadastro.cpf);
                printf("Turma: %d\n", alunos[i].cadastro.turma);

                printf("Trabalhos: %d %d %d\n",
                       alunos[i].cadastro.t1,
                       alunos[i].cadastro.t2,
                       alunos[i].cadastro.t3);

                printf("Provas: %d %d %d\n",
                       alunos[i].cadastro.p1,
                       alunos[i].cadastro.p2,
                       alunos[i].cadastro.p3);
            }

            break;
        }

        case 3:
        {
            int busca;

            printf("Digite o ID do aluno: ");
            scanf("%d", &busca);

            if (busca < 1 || busca > id)
            {
                printf("Aluno nao encontrado.\n");
                break;
            }

            int i = busca - 1;

            float mediaTrabs =
                (alunos[i].cadastro.t1 +
                 alunos[i].cadastro.t2 +
                 alunos[i].cadastro.t3) /
                3.0;

            float mediaProvs =
                (alunos[i].cadastro.p1 +
                 2 * alunos[i].cadastro.p2 +
                 3 * alunos[i].cadastro.p3) /
                6.0;

            float mediaFinal =
                (mediaTrabs + mediaProvs) / 2.0;

            printf("Media final: %.2f\n", mediaFinal);

            break;
        }

        case 4:
        {
            int busca;

            printf("Digite o ID do aluno: ");
            scanf("%d", &busca);

            if (busca < 1 || busca > id)
            {
                printf("Aluno nao encontrado.\n");
                break;
            }

            int i = busca - 1;

            float mediaTrabs =
                (alunos[i].cadastro.t1 +
                 alunos[i].cadastro.t2 +
                 alunos[i].cadastro.t3) /
                3.0;

            float mediaProvs =
                (alunos[i].cadastro.p1 +
                 2 * alunos[i].cadastro.p2 +
                 3 * alunos[i].cadastro.p3) /
                6.0;

            float mediaFinal =
                (mediaTrabs + mediaProvs) / 2.0;

            if (mediaFinal >= 6)
                printf("APROVADO - Media %.2f\n", mediaFinal);
            else if (mediaFinal < 4)
                printf("REPROVADO - Media %.2f\n", mediaFinal);
            else
                printf("RECUPERACAO - Media %.2f\n", mediaFinal);

            break;
        }

        case 5:
        {
            status = 0;
            break;
        }

        default:
        {
            printf("Opcao invalida!\n");
        }
        }

        if (status)
        {
            printf("\nPressione ENTER para continuar...");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            getchar();
        }
    }

    return 0;
}