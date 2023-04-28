#include <stdio.h>

int main(){
    float x, y;
    scanf("%f %f", &x, &y);

    if (x >= 0 && x <= 432 && y >= 0 && y <= 468){
        printf("Dentro! Lance legal, juiz!\n");
    }

    else{
       printf("Fora! Essa ja ta no japao!");
    }

}
