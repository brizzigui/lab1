#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    printf((num%2 == 0) ? "Numero par" : "Numero impar");
}
