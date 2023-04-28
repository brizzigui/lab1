#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numA, numB, divisor = 1, mdc = 1;
    printf("Insira dois numeros para calcular seu MDC:\n");
    scanf("%d %d", &numA, &numB);

    do{
        if (numA%divisor == 0 && numB%divisor == 0){
            mdc = divisor;
        }

        divisor++;

    } while (divisor <= numA && divisor <= numB);

    printf("MDC igual a: %d", mdc);
}
