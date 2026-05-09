#include <stdio.h>

int main () {

int idade;

printf ("Bem vindo ao verificador de idade ! \n");
printf ("Digite a idade: ");
scanf ("%d", &idade);

if (idade < 0) {
    printf("Idade invalida");
}
else if (idade >= 18 && idade <=29) {
    printf ("Jovem adulto !");
} 
else if (idade>=30 && idade <=59){
    printf ("Adulto !");
}
else if (idade>=60) {
    printf ("Idoso !");
} 
else if (idade >=12 && idade <=17){
    printf ("Adolescente");
} 
else if (idade <=11) {
    printf ("Crianca"); 
}
return 0;
}