#include <stdio.h>

int main(){
    int num = 0;

    while (num < 20){

        num = num + 1;

        if (num%3 == 0 && num%5 == 0){
            printf("FizzBuzz\n");
        }

        else{
            if (num%3 != 0 && num%5 != 0){
                printf("%d\n", num);
            }

            else{
                if (num%3 == 0){
                    printf("Fizz\n");
                }
                if (num%5 == 0){
                    printf("Buzz\n");
                }
            }

        }


        }
        }
