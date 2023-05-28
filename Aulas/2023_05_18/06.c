#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char menu(){
    printf("a) uniao: Z e a uniao de X com Y\n");
    printf("b) diferenca: Z e a diferenca entre X e Y\n");
    printf("c) soma: Z e a soma de X com Y\n");
    printf("d) produto: Z e o produto entre X e Y\n");
    printf("e) interseccao: Z e a interseccao entre X e Y\n");

    printf("Sua escolha: ");
    char escolha;
    scanf(" %c", &escolha);

    return escolha;
}

int main(){
    int vetorX[10], vetorY[10];
    int vetorZ[10];
    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetorX[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetorY[i]);
    }
    

    char escolha = menu();

    switch (escolha)
    {
        case 'a':
            uniao();
            break;
    
        case 'b':
            diferenca();
            break;

        case 'c':
            soma();
            break;
        
        case 'd':
            produto();
            break;
        
        case 'e':
            interseccao();
            break;
    }
}
