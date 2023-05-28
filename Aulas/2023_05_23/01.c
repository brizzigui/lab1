#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char str1[10], c1, c2;

    printf("Digite a string: ");
    scanf("%s", str1);

    printf("Digite o c1: ");
    scanf(" %c", &c1);

    printf("Digite o c2: ");
    scanf(" %c", &c2);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == c1)
        {
            str1[i] = c2;
        }
        
    }
    
    printf("%s", str1);
}
