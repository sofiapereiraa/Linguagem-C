#include <stdio.h>
#include <windows.h>

int main(void)
{
    int min, seg;
    printf("Informe os minutos e os segundos, nesta ordem: um numero e aperte Enter e depois outro numero e aperte Enter.\n");
    scanf("%d %d", &min, &seg);

    if (min < 0 || seg < 0 || min > 59 || seg > 59 || (min == 0 && seg == 0))
    {
        printf("Valores invalidos, tente novamente.\n");
    }
    else
    {
        do
        {
            system("cls");
            if (min < 10)
            {
                if (seg < 10)
                {
                    printf("0%d:0%d\n", min, seg);
                }
                else
                {
                    printf("0%d:%d\n", min, seg);
                }
            }
            else if (seg < 10)
            {
                printf("%d:0%d\n", min, seg);
            }
            else
            {
                printf("%d:%d\n", min, seg);
            }

            Sleep(1000);
            if (seg == 0)
            {
                min--;
                seg = 59;
            }
            else
            {
                seg--;
            }
        } while (min != 0 || seg != 0);
        system("cls");
        printf("0%d:0%d ", min, seg);
        printf(" \nTEMPO ESGOTADO !");

        for (int i = 0; i < 5; i++)
        {
            Beep(880, 1000);
            Sleep(500);
        }
    }

    return 0;
}