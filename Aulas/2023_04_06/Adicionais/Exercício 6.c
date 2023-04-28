#include <stdio.h>
#include <math.h>

int recalcmes(int meses){
    int diasDoMes = 0;
    if ((meses-1) == 1){
        return 31;

    }

    else if ((meses-1) == 2){
        return (31 + 28);
    }

    else if ((meses-1) == 3){
        return (31 + 28 + 31);
    }

    else if ((meses-1) == 4){
        return (31 + 28 + 31 + 30);
    }

    else if ((meses-1) == 5){
        return (31 + 28 + 31 + 30 + 31);
    }

    else if ((meses-1) == 6){
        return 31 + 28 + 31 + 30 + 31 + 30;
    }

    else if ((meses-1) == 7){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31);
    }

    else if ((meses-1) == 8){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
    }

    else if ((meses-1) == 9){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
    }

    else if ((meses-1) == 10){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
    }

    else if ((meses-1) == 11){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
    }

    else if ((meses-1) == 12){
        return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31);
        //inutilizado

    }

    else return 0;
}


void terraTermopA(){
    int dia, mes, hora, minuto, segundo, totalEmSegundos;
    int brat, mazel, salek, tak, blip;

    printf("Insira a data em formato terrestre (dia mes hora minuto segundo):\n");
    scanf("%d %d %d %d %d", &dia, &mes, &hora, &minuto, &segundo);
    int dias = recalcmes(mes);
    dia = dia + dias;
    totalEmSegundos = (dia-1)*86400 + hora*3600 + minuto*60 + segundo;

    printf("\nTotal de segundos: %d\n", totalEmSegundos);

    brat = totalEmSegundos / 432000;
    mazel = fmod(totalEmSegundos, 432000) / 54000;
    salek = fmod(fmod(totalEmSegundos, 432000),54000) / 1800;
    tak = fmod(fmod(fmod(totalEmSegundos, 432000), 54000), 1800) / 120;
    blip = fmod(fmod(fmod(fmod(totalEmSegundos, 432000), 54000), 1800), 120) / 3;

    printf("\n\nA data em termopilita corresponde a: ");
    printf("%d/%d %d:%d:%d (bb/mm ss:tt:bb)\n", brat, mazel, salek, tak, blip);
    //considera-se que todas unidades do calendário termopilita podem ser iguais a 0


}

void termopTerraB(){
    int totalEmSegundos;
    float mes, dia, hora, minuto, segundo;
    int brat, mazel, salek, tak, blip;

    printf("Insira a data em formato termopilita (brat, mazel, salek, tak, blip):\n");
    scanf("%d %d %d %d %d", &brat, &mazel, &salek, &tak, &blip);

    totalEmSegundos = brat*144000*3 + mazel*18000*3 + salek*600*3 + tak*40*3 + blip*3;

    printf("\nTotal de segundos: %d", totalEmSegundos);

    dia = totalEmSegundos / 86400;
    hora = fmod(totalEmSegundos, 86400) / 3600;
    minuto = fmod(fmod(totalEmSegundos, 86400),3600) / 60;
    segundo = fmod(fmod(fmod(totalEmSegundos,86400), 3600), 60);


    //como sempre, os meses nao terem o mesmo numero de dias fode tudo
    //fuck calendario gregoriano

    //esse codigo usa a mesma função dos meses pra resolver
    //mas basicamente inverte o funcionamento
    //funcionou bem

    int cont = 0;
    while (cont <= 12){
        cont++;
        if (dia < recalcmes(cont)){
            mes = cont - 1;
            break;
        }
    }

    float dias = recalcmes(mes);
    dia = ceil(dia) - dias + 1;


    printf("\n\nA data em terrestre corresponde a: ");
    printf("%d/%d %d:%d:%d (dd/mm hh:mm:ss)\n", (int)(dia), (int)mes, (int)hora, (int)minuto, (int)segundo);
}

void tabela(){

}


int main(){
    char opcao;

    printf("Selecione a opcao de conversao desejada:\n");
    printf("Digite 'A' para converter unidades terraqueas em termopilitas\n");
    printf("Digite 'B' para converter unidades termopilitas em terraqueas\n");
    printf("Ou, digite 'L' para ver uma tabela rapida de conversoes\n");
    printf("Digite: ");
    scanf("%c", &opcao);

    if (opcao == 'L'){
        tabela();
    }

    else if (opcao == 'A'){
        terraTermopA();
    }

    else if (opcao == 'B'){
        termopTerraB();
    }
}
