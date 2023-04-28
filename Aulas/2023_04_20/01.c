#include <stdio.h>

int somatorio(int num){
    int soma = 0;
    for (int i = 1; i <= num; i++){
        soma = soma + i;
    }

    return soma;


}

int main(){

    int num;
    scanf("%d", &num);

    int total = somatorio(num);
    printf("%d", total);

}
