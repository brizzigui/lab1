#include <stdio.h>

int main(){
    int i;
    float a, b, c, primeiro, segundo, terceiro;

    printf("Indique o modo:");
    scanf("%d", &i);
    printf("\nIndique os numeros:");
    scanf("%f %f %f", &a, &b, &c);

    primeiro = a;
    segundo = b;
    terceiro = c;

    if (primeiro < terceiro){
        primeiro = primeiro + terceiro;
        terceiro = primeiro - terceiro;
        primeiro = primeiro - terceiro;
    }

    if (primeiro < segundo){
        primeiro = primeiro + segundo;
        segundo = primeiro - segundo;
        primeiro = primeiro - segundo;
    }

    if (segundo < terceiro){
        segundo = segundo + terceiro;
        terceiro = segundo - terceiro;
        segundo = segundo - terceiro;

    }
    switch (i){
        case 1:
            printf("%f %f %f", terceiro, segundo, primeiro);
            break;

        case 2:
            printf("%f %f %f", primeiro, segundo, terceiro);
            break;

        case 3:
            printf("%f %f %f", terceiro, primeiro, segundo);
            break;

        default: printf("Tente novamente");
    }
}
