#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    a = b + a;
    b = a - b;
    a = a - b;

    printf("A = %d, B = %d", a, b);

}
