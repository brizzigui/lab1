#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetorA[10], vetorB[20];
    int vetorC[20], cont = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetorA[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &vetorB[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (vetorA[i] == vetorB[j])
            {
                vetorC[cont] = vetorA[i];
                cont++;
            }
            
        }
        
    }
    

    for (int i = 0; i < cont; i++)
    {
        for (int j = i+1; j < cont; j++)
        {
            if (vetorC[i] == vetorC[j])
            {   
                for (int k = j; k < cont; k++)
                {
                    vetorC[k] = vetorC[k+1];
                }

                j--;
                cont--; 
            }
            
        }
        
        
    }
    
    for (int i = 0; i < cont; i++)
    {
        printf("%d ", vetorC[i]);
    }
    
    
    
}
