#include <stdio.h>
#include <stdlib.h>

int c;
char anotacao[1000];

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

void escreverAnotacao(char f[])
{
    int op = 1;
    FILE *file = fopen(f, "a");

    if (file)
    {
        do
        {
            printf("\n Digite seu lembrete: ");
            fgets(anotacao, 1000, stdin);
            fprintf(file, "%s", anotacao);
            printf("\n Digite 1 para inserir outro registro ou qualquer outro numero para sair: ");
            scanf("%d", &op);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        } while (op == 1);

        fclose(file);
    }
    else
        printf("Erro ao abrir o arquivo\n");
}

void lerAnotacao(char f[])
{
    FILE *file = fopen(f, "r");

    if (file)
    {
        printf("\n Dados lidos do arquivo: \n");

        while (fgets(anotacao, 1000, file) != NULL)
        {
            printf("%s", anotacao);
        }

        fclose(file);
    }
    else
        printf("\n Erro ao abrir o arquivo !");
}


void removerAnotacao (char f []){

}

int main()
{
    char nome[] = {"diario.txt"};
    int opcao;
    int status = 1;
    while (status)
    {
        printf("\n === Diario de lembretes ===\n");
        printf("1 - Inserir lembretes\n");
        printf("2 - Ler lembretes\n");
        printf("3- Sair \n");
        printf("Alternativa: ");
        scanf("%d", &opcao);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        switch (opcao)
        {

        case 1:
        {
            limparTela();
            printf(" \n === Lembretes === \n");
            escreverAnotacao(nome);
            pause();
            break;
        }
        case 2:
        {
            limparTela();
            printf(" \n === Registro de lembretes === \n");
            lerAnotacao(nome);
            pause();
            break;
        }

        case 3:
        {
            limparTela();
            printf(" \n === Diario de lembretes ===\n");
            printf(" \n Saindo do programa \n");
            pause();
            status = 0;
            break;
        }
        default:
        {
            limparTela();
            printf(" \n === Diario de lembretes ===\n");
            printf("\n Opcao invalida \n");
            pause();
            break;
        }
        }
    }
}