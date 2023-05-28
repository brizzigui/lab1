#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    char string[30];
    int k;

    fgets(string, 30, stdin);
    scanf("%d", &k);

    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] += k;
    }

    printf("%s\n", string);

    //descriptografa
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] -= k;
    }

    printf("%s\n", string);
    
}
