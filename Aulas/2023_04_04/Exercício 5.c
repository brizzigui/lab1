#include <stdio.h>

int main(){

    int a, b, c;
    scanf("%d %d", &a, &b);

    c = a;
    a = b;
    b = c;

    printf("A = %d, B = %d", a, b);


}
