#include <stdio.h>
#include <math.h>

int main(){
    double x = 2;
    double y = .7;

    x = fmod(x,y);
    printf("%lf", x);
}
