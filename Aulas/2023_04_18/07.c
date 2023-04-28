#include <stdio.h>

int main(){
    int tab, limite, cont;
    printf("Qual tabuada voce quer? ");
    scanf("%d", &tab);
    printf("Ate que numero voce quer? ");
    scanf("%d", &limite);

    for(cont = 1; cont*tab <= limite; cont++){
        printf("%d\n", tab*cont);
    }
}
