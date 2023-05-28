#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void insere_string(char *strA, char *strB, int valor){
    int i, tamanho = strlen(strA);

    for (i = 0; strB[i] != '\0'; i++)
    {
        strA[i+valor] = strB[i];
    }

    if (tamanho + valor > strlen(strA))
    {
        strA[i+valor] = '\0';
    }

    
}

int main(){
    char strA[30], strB[30];
    int valor;

    scanf("%s", strA);
    scanf("%s", strB);
    scanf("%d", &valor);

    insere_string(strA, strB, valor);

    printf("%s", strA);
    
    


    
}
