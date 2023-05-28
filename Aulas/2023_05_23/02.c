#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char C, S[10];
    int V[10], cont = 0;

    scanf("%s", S);
    scanf(" %c", &C);
    

    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == C)
        {
            V[cont] = i;
            cont++;
        }
        
    }
    
    for (int i = 0; i < cont; i++)
    {
        printf("%d ", V[i]);
    }
    
}
