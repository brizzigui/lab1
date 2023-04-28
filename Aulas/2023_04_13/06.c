#include <stdio.h>

char podeColar(){
    float alturaPagina, larguraPagina, alturaFotoA, larguraFotoA, alturaFotoB, larguraFotoB, intermed;

    printf("Insira a altura e largura da pagina: ");
    scanf("%f %f", &alturaPagina, &larguraPagina);

    printf("Insira a altura da primeira foto e a largura da primeira foto: ");
    scanf("%f %f", &alturaFotoA, &larguraFotoA);

    printf("Insira a altura da segunda foto e a largura da segunda foto: ");
    scanf("%f %f", &alturaFotoB, &larguraFotoB);

    float maiorMedPagina, maiorMedFotoA, maiorMedFotoB;
    float menorMedPagina, menorMedFotoA, menorMedFotoB;

    if (alturaPagina >= larguraPagina){
        maiorMedPagina = alturaPagina;
        menorMedPagina = larguraPagina;
    }

    else{
        maiorMedPagina = larguraPagina;
        menorMedPagina = alturaPagina;
    }

    if (alturaFotoA >= larguraFotoA){
        maiorMedFotoA = alturaFotoA;
        menorMedFotoA = larguraFotoA;
    }

    else{
        maiorMedFotoA = larguraFotoA;
        menorMedFotoA = alturaFotoA;

    }

    if (alturaFotoB >= larguraFotoB){
        maiorMedFotoB = alturaFotoB;
        menorMedFotoB = larguraFotoB;
    }

    else{
        maiorMedFotoB = larguraFotoB;
        menorMedFotoB = alturaFotoB;
    }

    float maiorMedFotos = (maiorMedFotoA >= maiorMedFotoB) ? maiorMedFotoA : maiorMedFotoB;



    if (maiorMedFotos > maiorMedPagina){
        return 'n';
    }

    if (alturaFotoA + alturaFotoB > alturaPagina){
        alturaFotoA = intermed;
        alturaFotoA = larguraFotoA;
        larguraFotoA = intermed;
    }

    if (alturaFotoA + alturaFotoB <= alturaPagina){
        if (larguraFotoA + larguraFotoB <= larguraPagina)
            return 's';

        else{
            alturaFotoB = intermed;
            alturaFotoB = larguraFotoB;
            larguraFotoB = intermed;
        }

            if (larguraFotoA + larguraFotoB <= larguraPagina)
                return 's';

            else{
                alturaFotoA = intermed;
                alturaFotoA = larguraFotoA;
                larguraFotoA = intermed;

                if (alturaFotoA + alturaFotoB <= alturaPagina && larguraFotoA + larguraFotoB <= larguraPagina)
                    return 's';

                else return 'n';
            }


    }

    else{
        alturaFotoB = intermed;
        alturaFotoB = larguraFotoB;
        larguraFotoB = intermed;

        if (alturaFotoA + alturaFotoB <= alturaPagina && larguraFotoA + larguraFotoB <= larguraPagina)
            return 's';

        else return 'n';
    }




}

int main(){
    char resposta = podeColar();
    printf("Consegue colar 2 fotos numa pagina? %c", resposta);
}
