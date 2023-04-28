#include <stdio.h>
#include <math.h>


void imp_bin(int v){
    int significativo, doisElevadoNaNum, num = 32;
    while (num >= 0){
        doisElevadoNaNum = pow(2, num);
        if (v/doisElevadoNaNum%2 == 0){

            if (significativo == 1){
                putchar('0'+v/doisElevadoNaNum%2);
            }
        }

        else{
            significativo = 1;
            putchar('0'+v/doisElevadoNaNum%2);
        }
        num--;
    }
}



int main(){
    int numeroDoUser;
    printf("Insira um numero para converte-lo em binario: ");
    scanf("%d", &numeroDoUser);
    imp_bin(numeroDoUser);

}
