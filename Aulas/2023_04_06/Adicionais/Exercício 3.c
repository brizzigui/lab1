#include <stdio.h>

int main(){
    int pontA, pontB, pontC;
    printf("Insira as 3 pontuacoes: \n");
    scanf("%d %d %d", &pontA, &pontB, &pontC);


    if (pontA >= pontB && pontA >= pontC){
        if (pontB >= pontC)
            printf("O segundo colocado obteve: %d", pontB);
        else
            printf("O segundo colocado obteve: %d", pontC);
    }

    else {
        if ((pontB >= pontA && pontA >= pontC) || (pontC >= pontA && pontA >= pontB)){
            printf("O segundo colocado obteve: %d", pontA);
        }
        else{
            if (pontB >= pontC)
                printf("O segundo colocado obteve: %d", pontC);

            else
                printf("O segundo colocado obteve: %d", pontB);
        }

    }

}
