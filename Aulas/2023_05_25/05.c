#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void inverte(char string[]){
    int tam = strlen(string);
    char temp;

    for (int i = 0; i < tam/2; i++)
    {
        temp = string[i];
        string[i] = string[tam-i-1];
        string[tam-i-1] = temp;
        
    }
    
    
}

int main(){
    char texto[10];
    scanf("%s", &texto);

    inverte(texto);

    printf("%s", texto);
}
