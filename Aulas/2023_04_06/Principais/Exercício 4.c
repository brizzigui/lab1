#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    if (numero%3 == 0 && numero%7 == 0){
        printf("%d pode ser dividido por 3 e por 7", numero);

    }

    else{
        printf("%d nao pode ser dividido por 3 e 7 simultaneamente");
    }
}
