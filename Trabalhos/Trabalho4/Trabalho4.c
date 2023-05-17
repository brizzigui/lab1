#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void imprimir_notas(int indice_maior, int *ocorrencia, double *lista_notas, int *repetido, int n){
    printf("As notas e suas frequencias foram:\n\n");

    for(int i = 0; i < n; i++)
        if(repetido[i] != 1){
            if (ocorrencia[i] == 1)
                printf("-> %.2lf ocorre %d vez.\n", lista_notas[i], ocorrencia[i]);
            else
                printf("-> %.2lf ocorre %d vezes.\n", lista_notas[i], ocorrencia[i]);
        }

    printf("A nota mais frequente equivale a %.2lf, com %d ocorrencias.", lista_notas[indice_maior], ocorrencia[indice_maior]);
        
}

int maior_ocorrencia(int *ocorrencia, double *lista_notas, int n){

    int maior = ocorrencia[0];
    int indice_maior = 0;

    for (int i = 0; i < n; i++){
        if (ocorrencia[i] > maior){
            maior = ocorrencia[i];
            indice_maior = i;
        }
    }

    for (int i = 0; i < n; i++){
        if (ocorrencia[i] == maior){
            if (lista_notas[i] > lista_notas[indice_maior]){
                maior = ocorrencia[i];
                indice_maior = i;
            }
        }
    }

    return indice_maior;
}


int comparar_notas(double *lista_notas, int n){

    int ocorrencia[n];
    int repetido[n];

    for(int i = 0; i < n; i++){
        ocorrencia[i] = 1;
    }

    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (lista_notas[i] == lista_notas[j]){
                ocorrencia[i]++;
                repetido[j] = 1;
            }
        }
    }

    int indice_maior = maior_ocorrencia(ocorrencia, lista_notas, n);

    imprimir_notas(indice_maior, ocorrencia, lista_notas, repetido, n);

}


int pegar_notas(int n){

    double lista_notas[n];
    printf("Digite %d notas:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%lf", &lista_notas[i]);
    }

    comparar_notas(lista_notas, n);

}


int pegar_qnt(){
    int qnt_notas;
    do{
        printf("Insira quantas notas voce deseja analisar: ");
        scanf("%d", &qnt_notas);

        if(qnt_notas <= 0 || qnt_notas > 100){
            printf("Quantia invalida. Digite uma quantia entre entre 1 e 100.\n");
        }

    }while(qnt_notas <= 0 || qnt_notas > 100);
    

    return qnt_notas;
}

int main(){
    printf("ANALISADOR DE NOTAS\n\n");

    int qnt_notas = pegar_qnt();
    pegar_notas(qnt_notas);

}
