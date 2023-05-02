#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int primoOuNao(int num){
    for (int j = 2; j <= num; j++){
         if (j == num){
            return 1;
        }

        else if (num % j == 0){
            return 0;
        }
    }
}

int goldbach(int num){
    int primo; 
    for (int i = 2; i < num && i >= 2; i++){
        for (int j = 2; j <= i; j++){                
            if (j == i){
                primo = j;
                if (primoOuNao(num - primo)){
                    printf("%d + %d\n", primo, num-primo); 
                    if (primo != num-primo){
                        printf("%d + %d\n", num-primo, primo); 
                    }
                    
                }
                break;
            }
            else if (i % j == 0){
                break;
            }
        }
    }

    
    
        
}

int main(){
    int numero = 0;
    while (numero % 2 == 0){
        printf("Insira um numero par: ");
        scanf("%d", &numero);
        goldbach(numero);
    }

        
}
