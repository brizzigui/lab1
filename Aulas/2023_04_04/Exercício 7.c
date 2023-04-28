#include <stdio.h>

int main(){
    float comp_terreno, larg_terreno, area_terreno, comp_casa, larg_casa, area_casa, area_livre, percentual;
    printf("Insira as dimensoes do terreno: ");
    scanf("%f %f", &comp_terreno, &larg_terreno);
    printf("Insira as dimensoes da casa: ");
    scanf("%f %f", &comp_casa, &larg_casa);

    area_terreno = comp_terreno * larg_terreno;
    area_casa = comp_casa* larg_casa;

    area_livre = area_terreno - area_casa;
    percentual = area_livre / area_terreno * 100;

    printf("A area livre do terreno equivale a %.2f\n", area_livre);
    printf("Isso equivale a %.2f %%", percentual);


}
