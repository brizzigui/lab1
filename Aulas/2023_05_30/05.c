#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main( ){
    int x, y, *px, *py;
    printf ("Digite um valor: ");
    scanf ("%d", &x);
    px = &x;
    y = *px;
    printf ("x = %d e y = %d\n", x, y);
    *px = 8;
    py = px;
    printf ("x = %d e y = %d\n", x, y);
    *py = 9;
    printf ("x = %d e y = %d\n", x, y);
}

