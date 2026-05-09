#include <stdio.h>

int main(void) {
    int opcao;
    int x, y;

    printf("Digite dois numeros inteiros para o calculo: ");
    scanf("%d %d", &x, &y);

    printf("\n\t1: Soma\n");
    printf("\t2: Subtracao\n");
    printf("\t3: Multiplicacao\n");
    printf("\t4: Divisao\n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Resultado: %d\n", x + y);
    } 
    else if (opcao == 2) {
        printf("Resultado: %d\n", x - y);
    } 
    else if (opcao == 3) {
        printf("Resultado: %d\n", x * y);
    } 
    else if (opcao == 4) {
        if (y != 0)
            printf("Resultado: %d\n", x / y);
        else
            printf("Erro: divisao por zero!\n");
    } 
    else {
        printf("Opcao invalida!\n");
    }
    getchar();
    getchar();
    return 0;
}