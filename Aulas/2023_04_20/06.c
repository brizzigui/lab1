#include <stdio.h>

int sequencia(int N, int i){
    for (int x = 0; x<=N; x = x + i){
        printf("%d\n", x);
    }
}


int main(){
    int N, i;
    scanf("%d %d", &N, &i);
    sequencia(N, i);
}
