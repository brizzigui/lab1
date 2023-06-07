#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main( ){
    char a, b, *p;
    b = 'c';
    p = &a;
    *p = b;
    printf ("%c", a);
}

