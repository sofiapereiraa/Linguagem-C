#include <stdio.h>

int main (void) {
    int t1, t2,t3; 
    int p1,p2,p3; 
    float mediaTrabs;
    float mediaProvs;
    float mediaFinal;

    printf("Informe as notas dos trabalhos: ");
    scanf("%d %d %d", &t1, &t2, &t3);
  
    printf("Informe as notas das provas: ");
    scanf("%d %d %d", &p1, &p2, &p3);

    mediaTrabs = (t1+t2+t3)/3.0;
    mediaProvs = (p1+2*p2+3*p3)/6.0;
    mediaFinal = (mediaProvs+mediaTrabs)/2.0;

    if (mediaFinal >= 6) 
        printf ("Aprovado com media %.2f", mediaFinal);
    
    else if (mediaFinal <4) 
        printf ("Reprovado com media %.2f", mediaFinal);
    
    else 
        printf ("Recuperacao com media %.2f", mediaFinal);
    
    return 0;
}