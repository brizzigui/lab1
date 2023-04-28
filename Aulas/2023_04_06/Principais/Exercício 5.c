#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, delta, raiz1, raiz2;
    scanf("%f %f %f", &a, &b, &c);
    delta = b*b -(4*a*c);

    if (a == 0){
        raiz1 = (-c)/b;
        raiz2 = raiz1;
    }

    else{

        if (delta < 0){
            printf("Essa equacao nao possui raizes reais.\n");
        }

        else{
            raiz1 = ((-b) + sqrt(delta))/(2*a);
            raiz2 = ((-b) - sqrt(delta))/(2*a);
        }

    }

    if (raiz1 == raiz2){
        printf("A raiz foi %f", raiz1);

    }

    else{
        if (delta > 0){
            printf("As raizes foram %f e %f", raiz1, raiz2);
        }
    }
}

