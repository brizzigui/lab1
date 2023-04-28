#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float numA = 0, numB = 0, numTemp = 0, numRes = 0;
    char simbolo = ' ', opTemp;
    scanf("%f", &numA);
    while (1){   
        
        getchar();
        simbolo = getchar();

        if (simbolo == '\n' || simbolo == 13){
            break;
        }

        scanf("%f", &numB);

        if (simbolo == '+' || simbolo == '-'){
            if (simbolo == '+'){
                numTemp += numA;
            }
            
            else{
                numTemp += numA;
                numB = numB * -1;
            }
            
        
        }

        else{
            if (simbolo == '*'){
                numB = numA * numB;
            }
            else{
                numB = numA / numB;
            }
            
        }

        numA = numB;
    }



    numRes = numB + numTemp;

    printf("\n\nResultado: %g\n\n", numRes);
    
}
