#include <stdio.h>

int main(){
    float a, b, resultado;
    char simbolo;

    printf("Escreva, respectivamente, dois numeros e um simbolo para a ");
    printf("operacao que voce quer realizar entre eles.\n");
    scanf("%f %f %c", &a, &b, &simbolo);

    if (simbolo == '/' && b == 0){
        printf("Essa operacao nao pode ser aceita. Tente novamente!\n");
        main();
    }

    if (simbolo == '+'){
        resultado = a + b;
    }

    else if (simbolo == '-'){
        resultado = a - b;
    }

    else if (simbolo == '*'){
        resultado = a * b;
    }

    else if (simbolo == '/'){
        resultado = a / b;
    }


    printf("O resultado foi de %f", resultado);




}
