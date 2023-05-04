#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    for (int coluna = x; coluna <= y+1; coluna++){
        if (coluna == x){
            printf("    |");
        }

        else{
            printf("%4d", (coluna-1)); 
        }
    }
    
    printf("\n");
    for (int coluna = x; coluna <= y+1; coluna++){
        printf("----");
    }
    printf("\n");
    
    

    for (int linha = x; linha <= y; linha++){
        for (int coluna = x; coluna <= y; coluna++){
            if (coluna == x){
                printf("%3d |", linha);   
            }

        printf("%4d", linha * coluna);  
        }
        printf("\n");
    }
}
