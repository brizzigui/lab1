#include <stdio.h>

int main(){
    int mes;
    printf("Insira o numero de um mes do ano: ");
    scanf("%d", &mes);

    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("\nO numero de dias sera de 31.\n");
            break;
        case 4: case 6: case 9: case 11:
            printf("\nO numero de dias sera de 30.\n");
            break;
        case 2:
            printf("\nO numero de dias sera de 28.\n");
            break;

        default: printf("Isso nao e um mes!\n");
    }
}
