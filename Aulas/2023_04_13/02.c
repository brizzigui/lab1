#include <stdio.h>

void intersecta(){
    int x0, y0, x1, y1;
    int a0, b0, a1, b1;
    int temIntersec;

    printf("Insira as coordenadas dos dois pontos do retangulo, no formato x, y, x, y\n");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    printf("Insira as coordenadas dos dois pontos do outro retangulo, no formato x, y, x, y\n");
    scanf("%d %d %d %d", &a0, &b0, &a1, &b1);

    if(a0 >= x0 && a0 <= x1 && b0 >= y0 && b0 <= y1 || a1 >= x0 && a1 <= x1 && b1 >= y0 && b1 <= y1)
        printf("Tem interseccao.");

    else
        printf("Nao tem interseccao.");

}

int main(){
    intersecta();
}
