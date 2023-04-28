#include <stdio.h>

int main(){
    float precoHora, qntHoras, bruto, liquido, ir, inss, contrsind;
    printf("Digite sua remuneracao por hora e quantas horas voce trabalhou: ");
    scanf("%f %f", &precoHora, &qntHoras);

    bruto = precoHora*qntHoras;
    ir = bruto * 0.11;
    inss = bruto * 0.08;
    contrsind = bruto * 0.05;

    liquido = bruto - ir - inss - contrsind;

    printf("O salario bruto era: %.2f\n", bruto);
    printf("O salario liquido ficou: %.2f\n", liquido);
    printf("Descontou-se:\n Ir: %.2f\n Inss: %.2f\n Contribuicao sindical: %.2f\n", ir, inss, contrsind);

}
