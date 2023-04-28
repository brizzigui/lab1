#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, semiperimetro, area;
    scanf("%f %f %f", &a, &b, &c);

    if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))){
        if ((a > fabs(b - c)) && (b > fabs(a - c)) && (c > fabs(a - b))){

            semiperimetro = (a + b + c) / 2;
            area = sqrt(semiperimetro * (semiperimetro - a) * (semiperimetro - b) * (semiperimetro - c));
            printf("A area sera de %.2f\n", area);
        }

        else{
            printf("Isso nao forma um triangulo");
        }

    }

    else{
        printf("Isso nao forma um triangulo");
    }


}
