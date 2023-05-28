#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int remove_repetidos(char string[]){
    int tam = strlen(string);

    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (string[i] == string[j])
            {
                for (int x = j; x < tam+1; x++)
                {
                    string[x] = string[x+1];
                }

            }
            
            
        }
        
        
    }
    
    int removidos = tam - strlen(string);
    return removidos;
    
}

int main(){
    char string[32];
    scanf("%s", string);
    int removidos = remove_repetidos(string);
    printf("%s. Foram removidos %d caracteres", string, removidos);
}
