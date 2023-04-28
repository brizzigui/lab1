#include <stdio.h>
#include <math.h>

double custo(int horaEntrada, int minEntrada, int horaSaida, int minSaida){
    int tempoEmMinutos, tEntrada, tSaida, tempoEmHorasRound;
    double preco, tempoEmHoras;

    tEntrada = horaEntrada * 60 + minEntrada;
    tSaida = horaSaida * 60 + minSaida;
    tempoEmMinutos = tSaida - tEntrada;

    if (tempoEmMinutos <= 0){
        tempoEmMinutos = tempoEmMinutos + 24 * 60;
    }

    tempoEmHoras = ceil((tempoEmMinutos/60.0f));
    tempoEmHorasRound = (int)tempoEmHoras;

    printf("\nVoce ficou um total de %d minutos. Isso sera contabilizado como %d horas.\n", tempoEmMinutos, tempoEmHorasRound);

    switch(tempoEmHorasRound){
        case 1: case 2:
            preco = tempoEmHorasRound * 1;
            break;
        case 3: case 4:
            preco = 2 * 1 + (tempoEmHorasRound - 2) * 1.4;
            break;
        default:
            preco = 2 * 1 + 2 * 1.4 + (tempoEmHorasRound - 4) * 2;
            break;
    }

    return preco;

}

int main(){
    int horaEntrada, minEntrada, horaSaida, minSaida;
    float precoFinal;
    printf("Insira o horario de entrada: ");
    scanf("%d %d", &horaEntrada, &minEntrada);
    printf("Insira o horario de saida: ");
    scanf("%d %d", &horaSaida, &minSaida);

    precoFinal = custo(horaEntrada, minEntrada, horaSaida, minSaida);
    printf("\nO preco final foi de %.2f\n", precoFinal);

}
