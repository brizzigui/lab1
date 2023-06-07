#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main( ){
    int y, *p, x;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x--;
    (*p) += x;
    printf ("y = %d\n", y);
    printf ("x = %d\n", x);
    printf ("p = %d\n", *p);
}
