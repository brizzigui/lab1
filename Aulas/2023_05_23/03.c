#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int palindromo(char *string){
    int tamanho = strlen(string);

    for (int i = 0; i < tamanho/2; i++)
    {
        if(string[i] != string[tamanho-i-1]){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    char string[32];

    scanf("%s", string);
    int cumpre = palindromo(string);

    printf("1 se for palindromo e 0 se nao for: %d", cumpre);
}
