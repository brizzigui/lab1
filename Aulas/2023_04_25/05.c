#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int quadrado_perfeito(double num){
    float soma = 0, termo = 1;
    int i = 1;

    while (i <= (sqrt(num))){
        i++;
        soma = soma + termo;
        termo = termo + 2;
        
    }

    if (soma == num){
        return 1;
    }

    else{
        return 0;
    }
}

int main(){
    double num;
    scanf("%lf", &num);
    int simOuNao = quadrado_perfeito(num);

    if (simOuNao == 1){
        printf("Quadrado perfeito\n");
    }

    else{
        printf("Nao quadrado perfeito\n");
    }
}
