#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

typedef struct
{
    int Id;
    Produto produtos[99];
    float Total;
} Pedido;

int main()
{
    int status = 1, id = 0, c;
    Pedido pedidos[99];

    memset(pedidos, 0, sizeof(pedidos));

    while (status)
    {
        printf("\e[1;1H\e[2J");

        printf("Escolha uma das opcoes abaixo.\n");
        printf("\t1: Cadastro Produto.\n");
        printf("\t2: Listar produtos.\n");
        printf("\t3: Sair.\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            printf("\e[1;1H\e[2J");

            pedidos[id].Id = id + 1;

            printf("Pedido de ID: %d\n", pedidos[id].Id);

            float total = 0;

            for (int i = 0; i < 99; i++)
            {
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                printf("Digite o nome do produto: ");

                char nome[50];
                fgets(nome, sizeof(nome), stdin);

                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o valor do produto: ");
                float preco;
                scanf("%f", &preco);

                printf("Digite a quantidade do produto: ");
                int quantidade;
                scanf("%d", &quantidade);

                Produto produto = {
                    .preco = preco,
                    .quantidade = quantidade};

                strcpy(produto.nome, nome);

                pedidos[id].produtos[i] = produto;

                total += preco * quantidade;

                printf("Deseja adicionar outro produto? (s/n): ");

                char resposta;
                scanf(" %c", &resposta);

                if (resposta != 's' && resposta != 'S')
                {
                    break;
                }
            }

            pedidos[id].Total = total;
            id++;

            break;
        }

        case 2:
        {
            printf("\e[1;1H\e[2J");

            for (int i = 0; i < id; i++)
            {
                printf("\nPedido ID: %d\n", pedidos[i].Id);

                for (int j = 0; j < 99; j++)
                {
                    if (pedidos[i].produtos[j].quantidade == 0)
                    {
                        break;
                    }

                    printf("\nProduto #%d\n", j + 1);
                    printf("Nome do produto: %s\n", pedidos[i].produtos[j].nome);
                    printf("Preco do produto: %.2f\n", pedidos[i].produtos[j].preco);
                    printf("Quantidade do produto: %d\n", pedidos[i].produtos[j].quantidade);
                }

                printf("Total de todos os produtos: %.2f\n", pedidos[i].Total);
            }

            break;
        }

        case 3:
            status = 0;
            break;

        default:
            printf("Opcao invalida!\n");
        }

        printf("\nPressione Enter para continuar...");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        getchar();
    }

    return 0;
}