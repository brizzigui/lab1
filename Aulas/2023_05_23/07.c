#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void intercala(char *strA, char *strB, char *strC){
    int j = 0;

    for (int i = 0; j < (strlen(strA) + strlen(strB)); i++)
    {
        if (i < strlen(strA))   
        {
            strC[j] = strA[i];
            j++;
        }
        
        if (i < strlen(strB))   
        {
            strC[j] = strB[i];
            j++;
        }
        
    }
    
    
}   


void desintercala(char *str_desintercalada, char *strB, char *str_intercalada){
    int i, j;

    for (i = 0, j = 0; j < strlen(str_intercalada) && i < strlen(str_intercalada) - strlen(strB); i++, j+=2)
    {
        str_desintercalada[i] = str_intercalada[j];

    }

    str_desintercalada[i] = '\0';
    
}

int main(){
    char strA[16], strB[16];
    scanf("%s", strA);
    scanf("%s", strB);

    char str_intercalada[32];
    intercala(strA, strB, str_intercalada);

    printf("%s\n\n", str_intercalada);

    char str_desintercalada[32];
    desintercala(str_desintercalada, strB, str_intercalada);

    printf("%s\n\n", str_desintercalada);

    
}
