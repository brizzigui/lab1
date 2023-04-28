#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float chico = 150;
    float juca = 110;
    int anos = 0;

    while (juca <= chico){
        chico += 2;
        juca += 3;
        anos++;
    }

    printf("Demorara %d anos\n", anos);
}