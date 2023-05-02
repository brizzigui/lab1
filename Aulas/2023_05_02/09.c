#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void multiplos(int n, int a, int b){
    int cont = 1;
    while(cont <= n){
        printf("%d\n", a*b*cont);
        cont++;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d %d", &a, &b);
    multiplos(n, a, b);

}
