#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int digitos(int *num){
    int numero = *num;
    int digits = 0;

    while (numero > 1)
    {
        numero /= 10;
        digits++;
    }

    return digits;
    
}

void ao_contrario(int *num){

    int novo_numero = 0;
    int qnt_digitos = digitos(&*num);

    for (int i = 1, divisor = 10; i <= qnt_digitos; i++, divisor *= 10)
    {
        int digito = (*num % divisor) / (divisor/10); 
        novo_numero = novo_numero + digito * pow(10.0, (double)(qnt_digitos-i));
    }
    
    *num = novo_numero;
    

}

int main(){
    int num;
    scanf("%d", &num);
    ao_contrario(&num);
    printf("%d", num);
}
