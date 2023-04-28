#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c){
        printf("\nEmpate!\n");
    }

    else if (b == c && a != b){
        printf("\nAna vence!\n");
    }

    else if (a == c && b != a){
        printf("\nBob vence!\n");
    }

    else if (a == b && c != a){
        printf("\nCaren vence!\n");
    }
}
