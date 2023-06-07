#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, k, *pi, *pk;
    i = 2;
    k = 0;
    puts ("Qual sera o valor de k? ");
    pk = &k;
    pi = &i;
    *pk = i--;
    printf ("para *pk = i, temos k = %d\n", k);
    k = *pi;
    printf ("para k = *pi, temos k = %d\n", k);
}