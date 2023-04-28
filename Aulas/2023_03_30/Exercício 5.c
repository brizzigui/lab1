#include <stdio.h>

int main(){
    int idade;
    printf("Insira a sua idade: \n");
    scanf("%d", &idade);

    int dias = idade * 365;
    printf("Tu tem %d dias de idade", dias);

}
