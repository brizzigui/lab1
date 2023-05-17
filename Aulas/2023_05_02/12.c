#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int linha, coluna;
    printf("Digite a linha e a coluna na qual a torre se encontra: ");
    scanf("%d %d", &linha, &coluna);

    for (int y = 1; y <= 10; y++){
        for (int x = 1; x <= 9; x++){
            if (y == 1){
                if (x == 1){
                    printf("  ");
                }
                else{
                    printf("  %d", x-1);
                }
                
            }

            else if(y == 2){
                if (x == 1){
                    printf("   ");
                }

                else if(x == 2){
                    printf("-----------------------");
                }
                
                
            }

            else{
                if (x == 1){
                    printf("%d |", y-2);
                }

                else{
                    if(x-1 == coluna || y-2 == linha){
                        printf(" X ");
                    }

                    else{
                        printf(" - ");
                    }
                }
            }

        }

        printf("\n");
        
    }

    scanf(" %c");
}
