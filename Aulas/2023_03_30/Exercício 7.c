#include <stdio.h>

int main(){
    int data, ano, mes, dia;
    scanf("%d", &data);

    ano = data%100;
    mes = (data%10000 - data%100)/100;
    dia = (data%1000000 - data%10000)/10000;

    printf("Dia: %d\n", dia);
    printf("Mes: %d\n", mes);
    printf("Ano: 20%02d\n", ano);


}
