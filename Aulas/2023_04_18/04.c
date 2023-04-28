#include <stdio.h>

int main(){
    int num, qntDivisores;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++){

        if (num%i == 0){
            qntDivisores = qntDivisores + 1;
        }


    }

    if (qntDivisores == 2){
        printf("%d: primo\n", num);

    }

    else{
        printf("%d: nao primo\n", num);
        printf("Seus divisores sao:\n");
        for (int i = 1; i <= num; i++){

            if (num%i == 0){
            printf("%d ", i);
            }

        }

    }





}
