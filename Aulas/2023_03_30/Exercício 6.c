#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
//    num %= 100;
//    num = (num - num%10)/10;
    num = (num/10)%10;
    printf("%d", num);
}
