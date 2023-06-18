#ifndef BUTTONS_H
#define BUTTONS_H

int botao_padrao(int x, int y, ALLEGRO_BITMAP* imagem_botao, float x_mouse, float y_mouse, int click)
{
    float x0 = x;
    float x1 = x0 + LARG_BOTAO_PADRAO;
    float y0 = y;
    float y1 = y0 + ALT_BOTAO_PADRAO;

    al_draw_bitmap(imagem_botao, x0, y0, 0);
    if (x_mouse >= x0 && x_mouse <= x1 && y_mouse >= y0 && y_mouse <= y1 && click)
    {
        click = 0;
        return 1;
    }

    return 0;
}

int botao_pequeno(int x, int y, ALLEGRO_BITMAP* imagem_botao, float x_mouse, float y_mouse, int click)
{
    float x0 = x;
    float x1 = x0 + LARG_BOTAO_PEQ;
    float y0 = y;
    float y1 = y0 + ALT_BOTAO_PEQ;

    al_draw_bitmap(imagem_botao, x0, y0, 0);
    if (x_mouse >= x0 && x_mouse <= x1 && y_mouse >= y0 && y_mouse <= y1 && click)
    {
        click = 0;
        return 1;
    }

    return 0;
}

#endif