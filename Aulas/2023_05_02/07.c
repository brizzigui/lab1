#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void divisaoEResto(int a, int b){
    int quoficiente = 0;

    while (a > b){
        quoficiente++;
        a = a - b;
    }

    printf("%d e %d", quoficiente, a);

}

int main(){
    int numA, numB;
    scanf("%d %d", &numA, &numB);
    divisaoEResto(numA, numB);
}
