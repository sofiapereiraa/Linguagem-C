#include <stdio.h>

int main (void) {
    float saldo;
    float valor;
    int opcao;

    saldo = 6000.25;

    printf ("Banco\n");
    printf ("Escolha uma das opcoes abaixo.\n");
    printf("\t1: Saldo.\n");
    printf ("\t2: Saque.\n");
    printf ("\t3: Deposito.\n");
    scanf ("%d", &opcao);

    switch (opcao){
        case 1:
            printf ("Seu saldo: %.2f reais\n", saldo);
            break;

        case 2:
            printf ("Deseja sacar qual valor? ");
            scanf ("%f", &valor);

            if (valor <= saldo) {
                saldo = saldo - valor;
                printf ("Restou na sua conta: %.2f reais\n", saldo);
            } else {
                printf ("Saldo insuficiente!\n");
            }
            break;

        case 3:
            printf ("Digite o valor depositado: ");
            scanf ("%f", &valor);

            saldo = saldo + valor;
            printf ("Saldo atual da conta: %.2f reais\n", saldo);
            break;

        default:
            printf ("Opcao invalida, tente novamente.\n");
    }
    return 0;
}