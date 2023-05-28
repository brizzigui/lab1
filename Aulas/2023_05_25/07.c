#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void duplica_chars(char *string){

    int tamanho = strlen(string)*2;
    for (int i = 0; i < tamanho; i+=2)
    {
        for (int x = strlen(string)+1; x > i; x--)
        {
            string[x] = string[x-1];
            
        }
    }
    
}

int main(){
    char string[32];
    scanf("%s", string);
    duplica_chars(string);
    printf("%s", string);
}
