#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main( ){
    int x, y, *px, *py;
    x = 5;
    px = &x;
    py = px;
    y = (*py)--;
 printf ("%d %d", x, y);
}
