#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    if (b%a == 0 || a%b == 0){
        printf("%d e %d sao multiplos\n", a, b);
    }

    else {
        printf("Nao sao multiplos\n");
    }
}
