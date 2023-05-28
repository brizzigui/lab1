#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    char stringA[30], stringB[30];

    fgets(stringA, 30, stdin);

    strcpy(stringB, stringA);

    for (int i = 0; stringB[i] != '\0'; i++)
    {
        if (stringB[i] == ' ')
        {
            stringB[i] = '*';
        }
    }

    puts(stringB);
    

}
