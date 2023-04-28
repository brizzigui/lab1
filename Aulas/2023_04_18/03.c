#include <stdio.h>

int main(){
    int matricula;
    float nota1, nota2, nota3, media;

    for (int i = 0; i < 10; i++){
        printf("Insira a matricula do aluno: ");
        scanf("%d", &matricula);

        printf("Insira as notas 1, 2 e 3: ");
        scanf("%f %f %f", &nota1, &nota2, &nota3);

        media = 0.3 * nota1 + 0.3 * nota2 + 0.4 * nota3;
        printf("A media do aluno de matricula %d foi: %.2f\n", matricula, media);
        printf("P1: %.2f, P2: %.2f, P3: %.2f\n", nota1, nota2, nota3);

        if (media < 7){
            printf("\nReprovado! :(\n\n\n");
        }

        else{
            printf("\nAprovado! :)\n\n\n");
        }
    }
}
