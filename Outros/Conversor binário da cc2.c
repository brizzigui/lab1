#include <stdio.h>
#include <math.h>


void imp_bin(int v){
    if (v > 255){
        printf("Esse numero nao pode ser aceito pelo contador de 8 bits.");
    }
    else{
        int doisElevadoNaNum, num = 7;
        while (num >= 0){
            doisElevadoNaNum = pow(2, num);
            putchar('0'+v/doisElevadoNaNum%2);
            num--;
        }
    }



}

int main(){
    int numeroDoUser;
    printf("Insira um numero para converte-lo em binario: ");
    scanf("%d", &numeroDoUser);
    imp_bin(numeroDoUser);

}
