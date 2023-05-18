#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetA[10], vetB[10], vetC[20];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetA[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetB[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        vetC[i] = vetA[i];
    }

    for (int i = 0; i < 10; i++)
    {
        vetC[10+i] = vetB[i];
    }

    int aux;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(vetC[j+1] > vetC[j]){
                aux = vetC[j];
                vetC[j] = vetC[j+1];
                vetC[j+1] = aux;
            }
        }
        
    }
    
    for (int i = 0; i < 20; i++)
    {
        printf("%3d", vetC[i]);
    }
    
    
}
