#include <stdio.h>

float somaFracoes(int N){
    float H = 0;

    for (float i = 1; i <= N; i++){
        H = H + (1/i);
    }

    return H;
}

int main(){
    float N;
    scanf("%d", &N);

    float resultado = somaFracoes(N);
    printf("%f", resultado);

}
