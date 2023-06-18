#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080

#define LARG_BOTAO_PADRAO 350
#define ALT_BOTAO_PADRAO 125
#define OFFSET_BOTAO_PADRAO_X 20
#define OFFSET_BOTAO_PADRAO_Y 20

#define LARG_BOTAO_PEQ 210
#define ALT_BOTAO_PEQ 75
#define OFFSET_BOTAO_PEQ_X 10
#define OFFSET_BOTAO_PEQ_Y 10

#define LADO_DADO 100
#define OFFSET_INTRA_DADO 15

#define FILA_ANCORA_ESQUERDA_X 50
#define FILA_OFFSET_X 310
#define FILA_ANCORA_Y 850

#define MATRIZ_ANCORA_X 150
#define MATRIZ_ANCORA_Y 200

#define RAIO_INDICADOR_PTS 20
#define INDICADORES_PTS_ANCORA_X MATRIZ_ANCORA_X+(LADO_DADO+OFFSET_INTRA_DADO)*5 + RAIO_INDICADOR_PTS
#define INDICADORES_PTS_ANCORA_Y MATRIZ_ANCORA_Y+(LADO_DADO+OFFSET_INTRA_DADO)*5 + RAIO_INDICADOR_PTS

#define BRANCO al_map_rgb(255, 255, 255)
#define PRETO al_map_rgb(0, 0, 0)
#define AZUL_ESCURO al_map_rgb(0, 15, 50)
#define AZUL_CLARO al_map_rgb(90, 150, 240)

#define CODE_RED 0
#define CODE_BLUE 1
#define CODE_YELLOW 2
#define CODE_GREEN 3
#define CODE_PURPLE 4

#include "code/buttons.h"

void inicializar()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_image_addon();
    al_init_ttf_addon();
}

char menu(ALLEGRO_DISPLAY* display)
{
    ALLEGRO_FONT* font_2p_regular_72 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 72, 0);
    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));
    ALLEGRO_EVENT event;

    ALLEGRO_BITMAP* botao_jogar = al_load_bitmap("media/images/buttons/jogar.png");
    ALLEGRO_BITMAP* botao_restaurar = al_load_bitmap("media/images/buttons/restaurar.png");
    ALLEGRO_BITMAP* botao_record = al_load_bitmap("media/images/buttons/record.png");
    ALLEGRO_BITMAP* botao_help = al_load_bitmap("media/images/buttons/help.png");
    ALLEGRO_BITMAP* botao_sair = al_load_bitmap("media/images/buttons/sair.png");

    ALLEGRO_MOUSE_STATE state;

    float x_mouse = 0, y_mouse = 0;
    int click = 0;

    bool update = true;
    al_start_timer(timer_fps);
    while (1)
    {
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&state);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER: 
                update = true;
                x_mouse = state.x;
                y_mouse = state.y;
                break;
            
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                x_mouse = state.x;
                y_mouse = state.y;
                click = 1;
        }               
        
        al_clear_to_color(AZUL_ESCURO);
        al_draw_text(font_2p_regular_72, BRANCO, LARGURA_TELA/2, ALTURA_TELA/4, ALLEGRO_ALIGN_CENTER, "DecaDado");

        bool ir_jogar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, 450, botao_jogar, x_mouse, y_mouse, click);
        bool ir_restaurar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO-OFFSET_BOTAO_PADRAO_X, 450+ALT_BOTAO_PADRAO+OFFSET_BOTAO_PADRAO_Y, botao_restaurar, x_mouse, y_mouse, click);
        bool ir_record = botao_padrao(LARGURA_TELA/2+OFFSET_BOTAO_PADRAO_X, 450+ALT_BOTAO_PADRAO+OFFSET_BOTAO_PADRAO_Y, botao_record, x_mouse, y_mouse, click);
        bool ir_help = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO-OFFSET_BOTAO_PADRAO_X, 450+(OFFSET_BOTAO_PADRAO_Y+ALT_BOTAO_PADRAO)*2, botao_help, x_mouse, y_mouse, click);
        bool ir_sair = botao_padrao(LARGURA_TELA/2+OFFSET_BOTAO_PADRAO_X, 450+(OFFSET_BOTAO_PADRAO_Y+ALT_BOTAO_PADRAO)*2, botao_sair, x_mouse, y_mouse, click);


        if(ir_jogar)
            return 'j';
        else if(ir_restaurar)
            return 'r';
        else if(ir_record)
            return 'd';
        else if(ir_help)
            return 'h';
        else if(ir_sair)
            return 's';

        if (update)
        {
            al_flip_display();
            update = false;
        }

        click = 0;
    }
}

struct celula
{
    bool ocupada;
    int num_dado;
    int cor;
    ALLEGRO_BITMAP* bitmap;
    float x, y;
};

struct dados_gerados
{
    bool ocupada;
    int qnt_dados;
    int numeros[3];
    int rotacao;
    int cor;

    float x[3], y[3];
    float x_origem[3], y_origem[3];
    ALLEGRO_BITMAP* bitmap[3];

    float click_point_diff_x[3];
    float click_point_diff_y[3];
    bool puxada;
};

struct controla_jogo
{
    int broken;
    int pont;

    bool tab_concl;
    bool multilinha;
    int combo;

    int linhas_broken[5];
    int colunas_broken[5];
};


void gera_dados(struct dados_gerados fila[])
{
    for (int i = 0; i < 3; i++)
    {
        if(fila[i].ocupada == true)
        {
            return;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        fila[i].cor = (rand() % 5);
        fila[i].qnt_dados = (rand() % 3) + 1;
        fila[i].ocupada = true;

        if (fila[i].qnt_dados == 2)
        {
            fila[i].rotacao = rand() % 4;
        }
        
        else if (fila[i].qnt_dados == 3)
        {
            fila[i].rotacao = rand() % 4;
        }

        else
        {
            fila[i].rotacao = 0;
        }
        
        for (int j = 0; j < fila[i].qnt_dados; j++)
        {
            fila[i].numeros[j] = (rand() % 7);
        }
    }  
}

void posiciona_dados(struct dados_gerados fila_dados[], ALLEGRO_BITMAP* red[], ALLEGRO_BITMAP* blue[], ALLEGRO_BITMAP* yellow[], ALLEGRO_BITMAP* green[], ALLEGRO_BITMAP* purple[])
{
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < fila_dados[i].qnt_dados; j++)
        {
            switch (fila_dados[i].cor)
            {
                case CODE_RED:
                    fila_dados[i].bitmap[j] = red[fila_dados[i].numeros[j]];
                    break;
                case CODE_BLUE:
                    fila_dados[i].bitmap[j] = blue[fila_dados[i].numeros[j]];
                    break;
                case CODE_YELLOW:
                    fila_dados[i].bitmap[j] = yellow[fila_dados[i].numeros[j]];
                    break;
                case CODE_GREEN:
                    fila_dados[i].bitmap[j] = green[fila_dados[i].numeros[j]];
                    break;
                case CODE_PURPLE:
                    fila_dados[i].bitmap[j] = purple[fila_dados[i].numeros[j]];
                    break;
            }
        }

        switch (fila_dados[i].qnt_dados)
        {
            case 1:
                fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                fila_dados[i].y[0] = FILA_ANCORA_Y;
                break;
            
            case 2:
                switch (fila_dados[i].rotacao)
                {
                    case 0:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[0] = FILA_ANCORA_Y;

                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[1] = FILA_ANCORA_Y;

                        break;

                    case 1:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[0] = FILA_ANCORA_Y;

                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[1] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        
                        break;

                    case 2: 
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[1] = FILA_ANCORA_Y;

                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[0] = FILA_ANCORA_Y;

                        break;

                    case 3:
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[1] = FILA_ANCORA_Y;

                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].y[0] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        
                        break;
                }
                break;

            case 3:

                switch (fila_dados[i].rotacao)
                {
                    case 0:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].x[2] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;

                        fila_dados[i].y[0] = FILA_ANCORA_Y;
                        fila_dados[i].y[1] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[2] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        break;
                    
                    case 1:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].x[2] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;

                        fila_dados[i].y[0] = FILA_ANCORA_Y;
                        fila_dados[i].y[1] = FILA_ANCORA_Y;
                        fila_dados[i].y[2] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        break;

                    case 2:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].x[2] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;

                        fila_dados[i].y[0] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[1] = FILA_ANCORA_Y;
                        fila_dados[i].y[2] = FILA_ANCORA_Y;
                        break;

                    case 3:
                        fila_dados[i].x[0] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i;
                        fila_dados[i].x[1] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].x[2] = FILA_ANCORA_ESQUERDA_X + FILA_OFFSET_X*i + LADO_DADO + OFFSET_INTRA_DADO;

                        fila_dados[i].y[0] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[1] = FILA_ANCORA_Y + LADO_DADO + OFFSET_INTRA_DADO;
                        fila_dados[i].y[2] = FILA_ANCORA_Y;
                        break;
                }   

                break;
        }

    }
    
    
}

void cria_matriz(struct celula matriz[5][5], ALLEGRO_BITMAP* cell)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j].ocupada = false;
            matriz[i][j].bitmap = cell;

            matriz[i][j].x = MATRIZ_ANCORA_X + j*(LADO_DADO+OFFSET_INTRA_DADO);
            matriz[i][j].y = MATRIZ_ANCORA_Y + i*(LADO_DADO+OFFSET_INTRA_DADO);
        }
        
    }
    
}

void atualiza_matriz(struct celula matriz[5][5], ALLEGRO_BITMAP* cell, ALLEGRO_BITMAP* red[], ALLEGRO_BITMAP* blue[], ALLEGRO_BITMAP* yellow[], ALLEGRO_BITMAP* green[], ALLEGRO_BITMAP* purple[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j].ocupada)
            {
                switch (matriz[i][j].cor)
                {
                    case CODE_RED:
                        matriz[i][j].bitmap = red[matriz[i][j].num_dado];
                        break;
                    case CODE_BLUE:
                        matriz[i][j].bitmap = blue[matriz[i][j].num_dado];
                        break;
                    case CODE_YELLOW:
                        matriz[i][j].bitmap = yellow[matriz[i][j].num_dado];
                        break;
                    case CODE_GREEN:
                        matriz[i][j].bitmap = green[matriz[i][j].num_dado];
                        break;
                    case CODE_PURPLE:
                        matriz[i][j].bitmap = purple[matriz[i][j].num_dado];
                        break;
                }
            }

            else
            {
                matriz[i][j].bitmap = cell;
            }
            
        }
        
    }
}

float dist_pts_centrais(float x0, float y0, float x1, float y1)
{
    float x0_central, y0_central, x1_central, y1_central;
    x0_central = x0 + LADO_DADO/2;
    x1_central = x1 + LADO_DADO/2;
    y0_central = y0 + LADO_DADO/2;
    y1_central = y1 + LADO_DADO/2;
    
    float dif_x = x0_central - x1_central;
    float dif_y = y0_central - y1_central;

    
    float distancia = sqrt((double)(dif_x*dif_x + dif_y*dif_y));
    return distancia;
}

int intersec(struct dados_gerados fila[], struct celula matriz[5][5])
{

    int redesenhar = 0;
    int encaixe_possivel = 0;
    int i_celula[3];
    int j_celula[3];

    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < fila[a].qnt_dados; b++)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (dist_pts_centrais(fila[a].x[b], fila[a].y[b], matriz[i][j].x, matriz[i][j].y) <= LADO_DADO/2 && matriz[i][j].ocupada == false)
                    {
                        i_celula[encaixe_possivel] = i;
                        j_celula[encaixe_possivel] = j;
                        encaixe_possivel++;
                    }
                    
                }
                
            }
        
        }


        if(encaixe_possivel == fila[a].qnt_dados && fila[a].ocupada == true)
        {
            fila[a].ocupada = false;
            for (int i = 0; i < fila[a].qnt_dados; i++)
            {
                matriz[i_celula[i]][j_celula[i]].cor = fila[a].cor;
                matriz[i_celula[i]][j_celula[i]].num_dado = fila[a].numeros[i];
                matriz[i_celula[i]][j_celula[i]].ocupada = true;
            }
            
            redesenhar = 1;
        }

        encaixe_possivel = 0;
    }
    
    return redesenhar;
}

void somatorios(struct celula matriz[5][5], int soma_linha[5], int soma_coluna[5])
{
    for (int i = 0; i < 5; i++)
    {   
        soma_linha[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j].ocupada)
            {
                soma_linha[i] += matriz[i][j].num_dado;
            }
        }
    }

    for (int j = 0; j < 5; j++)
    {
        soma_coluna[j] = 0;
        for (int i = 0; i < 5; i++)
        {
            if (matriz[i][j].ocupada)
            {
                soma_coluna[j] += matriz[i][j].num_dado;
            }
        }
    }
    

}

void display_somatorios(int soma_linha[5], int soma_coluna[5], ALLEGRO_FONT* font_play_bold_24)
{
    char texto[5];

    for (int i = 0; i < 5; i++)
    {
        sprintf(texto, "%d", soma_linha[i]);
        al_draw_filled_circle(INDICADORES_PTS_ANCORA_X, MATRIZ_ANCORA_Y+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*i, RAIO_INDICADOR_PTS, AZUL_CLARO);
        al_draw_text(font_play_bold_24, BRANCO, INDICADORES_PTS_ANCORA_X, MATRIZ_ANCORA_Y+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*i-0.75*RAIO_INDICADOR_PTS, ALLEGRO_ALIGN_CENTER, texto);
    }

    for (int j = 0; j < 5; j++)
    {
        sprintf(texto, "%d", soma_coluna[j]);
        al_draw_filled_circle(MATRIZ_ANCORA_X+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*j, MATRIZ_ANCORA_Y-OFFSET_INTRA_DADO-RAIO_INDICADOR_PTS, RAIO_INDICADOR_PTS, AZUL_CLARO);
        al_draw_text(font_play_bold_24, BRANCO, MATRIZ_ANCORA_X+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*j, MATRIZ_ANCORA_Y-OFFSET_INTRA_DADO-1.75*RAIO_INDICADOR_PTS, ALLEGRO_ALIGN_CENTER, texto);
    }
    
}

int checa_soma(ALLEGRO_DISPLAY* display, struct celula matriz[5][5], int soma_linha[5], int soma_coluna[5], struct controla_jogo *controlador)
{
    controlador->multilinha = false;
    controlador->tab_concl = false;
    controlador->combo = 0;

    int cont = 0;

    do
    {
        controlador->broken = 0;

        for (int i = 0; i < 5; i++)
        {
            if (soma_linha[i] == 10)
            {
                (controlador->broken)++;
                for (int j = 0; j < 5; j++)
                {
                    if (matriz[i][j].ocupada)
                    {
                        (controlador->pont)++;
                    }
                    
                    matriz[i][j].ocupada = false;
                }  
            }
        }

        for (int j = 0; j < 5; j++)
        {
            if (soma_coluna[j] == 10)
            {
                (controlador->broken)++;
                for (int i = 0; i < 5; i++)
                {
                    if (matriz[i][j].ocupada)
                    {
                        (controlador->pont)++;
                    }
                    
                    matriz[i][j].ocupada = false;
                }  
            }
        }

        int qnt_ocupadas = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matriz[i][j].ocupada)
                {
                    qnt_ocupadas++;
                }
                
            }
            
        }

        if (qnt_ocupadas == 0)
        {
            controlador->tab_concl = true;
        }
        
        if (controlador->broken > 0 && cont > 0)
        {
            controlador->combo++;
        }
        

        if(controlador->broken > 1)
        {
            controlador->multilinha = true;
        }

        cont++;
        somatorios(matriz, soma_linha, soma_coluna);

    } while (controlador->broken != 0);
    
    
}

void jogo(ALLEGRO_DISPLAY* display, int restaura)
{
    ALLEGRO_FONT* font_2p_regular_72 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 72, 0);
    ALLEGRO_FONT* font_play_bold_24 = al_load_ttf_font("media/fonts/Play-bold.ttf", 24, 0);
    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE state;

    ALLEGRO_BITMAP* background = al_load_bitmap("media/images/background.png");
    ALLEGRO_BITMAP* cell = al_load_bitmap("media/images/cell.png");
    
    ALLEGRO_BITMAP* botao_sair = al_load_bitmap("media/images/buttons/sair.png");
    ALLEGRO_BITMAP* botao_salvar_e_sair = al_load_bitmap("media/images/buttons/salvar_e_sair.png");
    ALLEGRO_BITMAP* botao_menu_peq = al_load_bitmap("media/images/buttons/menu_peq.png");
    ALLEGRO_BITMAP* botao_voltar = al_load_bitmap("media/images/buttons/voltar.png");


    ALLEGRO_BITMAP* red[7] = {
                                al_load_bitmap("media/images/dice/red_0.png"), 
                                al_load_bitmap("media/images/dice/red_1.png"),
                                al_load_bitmap("media/images/dice/red_2.png"),
                                al_load_bitmap("media/images/dice/red_3.png"),
                                al_load_bitmap("media/images/dice/red_4.png"),
                                al_load_bitmap("media/images/dice/red_5.png"),
                                al_load_bitmap("media/images/dice/red_6.png")
                            };

    ALLEGRO_BITMAP* blue[7] = {
                                al_load_bitmap("media/images/dice/blue_0.png"), 
                                al_load_bitmap("media/images/dice/blue_1.png"),
                                al_load_bitmap("media/images/dice/blue_2.png"),
                                al_load_bitmap("media/images/dice/blue_3.png"),
                                al_load_bitmap("media/images/dice/blue_4.png"),
                                al_load_bitmap("media/images/dice/blue_5.png"),
                                al_load_bitmap("media/images/dice/blue_6.png")
                            };

    ALLEGRO_BITMAP* yellow[7] = {
                                al_load_bitmap("media/images/dice/yellow_0.png"), 
                                al_load_bitmap("media/images/dice/yellow_1.png"),
                                al_load_bitmap("media/images/dice/yellow_2.png"),
                                al_load_bitmap("media/images/dice/yellow_3.png"),
                                al_load_bitmap("media/images/dice/yellow_4.png"),
                                al_load_bitmap("media/images/dice/yellow_5.png"),
                                al_load_bitmap("media/images/dice/yellow_6.png")
                            };

    ALLEGRO_BITMAP* green[7] = {
                                al_load_bitmap("media/images/dice/green_0.png"), 
                                al_load_bitmap("media/images/dice/green_1.png"),
                                al_load_bitmap("media/images/dice/green_2.png"),
                                al_load_bitmap("media/images/dice/green_3.png"),
                                al_load_bitmap("media/images/dice/green_4.png"),
                                al_load_bitmap("media/images/dice/green_5.png"),
                                al_load_bitmap("media/images/dice/green_6.png")
                            };
                    
    ALLEGRO_BITMAP* purple[7] = {
                                al_load_bitmap("media/images/dice/purple_0.png"), 
                                al_load_bitmap("media/images/dice/purple_1.png"),
                                al_load_bitmap("media/images/dice/purple_2.png"),
                                al_load_bitmap("media/images/dice/purple_3.png"),
                                al_load_bitmap("media/images/dice/purple_4.png"),
                                al_load_bitmap("media/images/dice/purple_5.png"),
                                al_load_bitmap("media/images/dice/purple_6.png")
                            };

    float x_mouse = 0, y_mouse = 0;
    int click = 0, release = 0, held = 0;
    bool submenu_aberto = false;
    bool pause_click = false;
    bool update = true;

    struct celula matriz[5][5];
    struct dados_gerados fila_dados[3];
    struct controla_jogo controlador;
    controlador.pont = 0;
    int soma_linha[5] = {}, soma_coluna[5] = {};
    
    for (int i = 0; i < 3; i++)
    {
        fila_dados[i].ocupada = false;
        fila_dados[i].puxada = false;
    }

    gera_dados(fila_dados);
    posiciona_dados(fila_dados, red, blue, yellow, green, purple);
    cria_matriz(matriz, cell);

    al_start_timer(timer_fps);
    while (1)
    {
        
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&state);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER: 
                update = true;
                x_mouse = state.x;
                y_mouse = state.y;               
                
                for (int i = 0; i < 3; i++)
                {
                    if (fila_dados[i].puxada)
                    {
                        for (int j = 0; j < fila_dados[i].qnt_dados; j++)
                        {
                            fila_dados[i].x[j] = x_mouse - fila_dados[i].click_point_diff_x[j];
                            fila_dados[i].y[j] = y_mouse - fila_dados[i].click_point_diff_y[j];
                        } 
                    }
                }
                
                
                
                break;
            
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                x_mouse = state.x;
                y_mouse = state.y;
                click = 1;

                for (int i = 0; i < 3; i++)
                {
                    if (fila_dados[i].ocupada)
                    {
                        for (int j = 0; j < fila_dados[i].qnt_dados; j++)
                        {
                            if (x_mouse >= fila_dados[i].x[j] && x_mouse <= fila_dados[i].x[j]+LADO_DADO && y_mouse >= fila_dados[i].y[j] && y_mouse <= fila_dados[i].y[j]+LADO_DADO && click)
                            {
                                fila_dados[i].puxada = true;
                                for (int k = 0; k < fila_dados[i].qnt_dados; k++)
                                {
                                    fila_dados[i].click_point_diff_x[k] = x_mouse - fila_dados[i].x[k];
                                    fila_dados[i].click_point_diff_y[k] = y_mouse - fila_dados[i].y[k];
                                }
                                
                            }
                        }
                    }
                }

                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                x_mouse = state.x;
                y_mouse = state.y;
                release = 1;
        
                if (intersec(fila_dados, matriz))
                {
                    somatorios(matriz, soma_linha, soma_coluna);
                    checa_soma(display, matriz, soma_linha, soma_coluna, &controlador);
                    atualiza_matriz(matriz, cell, red, blue, yellow, green, purple);
                }
                
                int ocupadas = 0;

                for (int a = 0; a < 3; a++)
                {
                    fila_dados[a].puxada = 0;
                    
                    if (fila_dados[a].ocupada)
                    {
                        ocupadas++;
                    }
                }

                if(ocupadas == 0)
                {
                    gera_dados(fila_dados);
                    posiciona_dados(fila_dados, red, blue, yellow, green, purple);
                }
                
                break;


            case ALLEGRO_EVENT_KEY_DOWN:
                 if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                 {
                    submenu_aberto = !submenu_aberto;
                 }
        }

        al_clear_to_color(AZUL_ESCURO);
        al_draw_bitmap(background, 0, 0, 0);  
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                al_draw_bitmap(matriz[i][j].bitmap, matriz[i][j].x, matriz[i][j].y, 0);
            }
            
        }

        char pont_text[8];
        sprintf(pont_text, "%d", controlador.pont);
        al_draw_text(font_2p_regular_72, BRANCO, MATRIZ_ANCORA_X+2.5*LADO_DADO+2*OFFSET_INTRA_DADO, MATRIZ_ANCORA_Y-165, ALLEGRO_ALIGN_CENTRE, pont_text);

        display_somatorios(soma_linha, soma_coluna, font_play_bold_24);
              

        for (int i = 0; i < 3; i++)
        {
            if (fila_dados[i].ocupada)
            {
            
                for (int j = 0; j < fila_dados[i].qnt_dados; j++)
                {
                    al_draw_bitmap(fila_dados[i].bitmap[j], fila_dados[i].x[j], fila_dados[i].y[j], 0);
                }
            
            }
        }
        

        pause_click = botao_pequeno(LARGURA_TELA-LARG_BOTAO_PEQ-OFFSET_BOTAO_PEQ_X, OFFSET_BOTAO_PEQ_Y, botao_menu_peq, x_mouse, y_mouse, click);

        if (pause_click)
        {
           submenu_aberto = true; 
        } 

        if (submenu_aberto)
        {
            al_draw_filled_rectangle(0, 0, LARGURA_TELA, ALTURA_TELA, al_map_rgba(0, 0, 0, 200));
            al_draw_text(font_2p_regular_72, BRANCO, LARGURA_TELA/2, ALTURA_TELA/4, ALLEGRO_ALIGN_CENTER, "Paused");
            bool sair_salvando = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y, botao_salvar_e_sair, x_mouse, y_mouse, click);
            bool sair_sem_salvar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y*2+ALT_BOTAO_PADRAO, botao_sair, x_mouse, y_mouse, click);
            bool voltar = botao_pequeno(LARGURA_TELA/2-LARG_BOTAO_PEQ/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y*3+ALT_BOTAO_PADRAO*2, botao_voltar, x_mouse, y_mouse, click);
             
            if (sair_salvando)
            {
                //adicionar salvamento
                return;
            }

            else if (sair_sem_salvar)
            {
                return;
            }
            
            else if(voltar)
            {
                submenu_aberto = false;
            }
              
        }

        if (update)
        {
            al_flip_display();
            update = false;
        }

        if (click || release)
        {
            held = !held;
        }

        click = 0;
        release = 0;   
    }
}

void record(ALLEGRO_DISPLAY* display)
{
    
}

void help(ALLEGRO_DISPLAY* display)
{
    ALLEGRO_FONT* font_2p_regular_24 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 24, 0);
    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);
    ALLEGRO_BITMAP* pag1 = al_load_bitmap("media/images/pag1.png");
    ALLEGRO_BITMAP* pag2 = al_load_bitmap("media/images/pag1.png");
    ALLEGRO_BITMAP* pag3 = al_load_bitmap("media/images/pag1.png");
    ALLEGRO_BITMAP* pag4 = al_load_bitmap("media/images/pag1.png");
    ALLEGRO_BITMAP* botao_voltar = al_load_bitmap("media/images/buttons/voltar.png");
    ALLEGRO_BITMAP* prox_pag = al_load_bitmap("media/images/buttons/prox_pag.png");
    ALLEGRO_BITMAP* botao_menu = al_load_bitmap("media/images/buttons/menu_peq.png");
    

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE state;

    float x_mouse = 0, y_mouse = 0;
    int click = 0;
    int num = 0;
    int pagina = 1;

    bool update = true;
    al_start_timer(timer_fps);
    while (1)
    {
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&state);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER: 
                update = true;
                x_mouse = state.x;
                y_mouse = state.y;
                break;
            
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                x_mouse = state.x;
                y_mouse = state.y;
                click = 1;
        }               
    
        char contador[32];

        switch(pagina)
        {
            case 1:
                al_draw_bitmap(pag1, 0, 0, 0);
                break;
            case 2:
                al_draw_bitmap(pag2, 0, 0, 0);
                break;
            case 3:
                al_draw_bitmap(pag3, 0, 0, 0);
                break;
            case 4:
                al_draw_bitmap(pag4, 0, 0, 0);
                break;
        }

        sprintf(contador, "Pág. %d/4", pagina);
        al_draw_text(font_2p_regular_24, BRANCO, LARGURA_TELA-LARG_BOTAO_PEQ-OFFSET_BOTAO_PEQ_X, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y*6, 0, contador);

        bool menu = botao_pequeno(OFFSET_BOTAO_PEQ_X, ALTURA_TELA-ALT_BOTAO_PEQ*2-OFFSET_BOTAO_PEQ_Y*2, botao_menu, x_mouse, y_mouse, click);
        bool voltar = botao_pequeno(OFFSET_BOTAO_PEQ_X, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y, botao_voltar, x_mouse, y_mouse, click);
        bool next_page = false;

        if (pagina < 4)
        {
            next_page = botao_pequeno(LARGURA_TELA-OFFSET_BOTAO_PEQ_X-LARG_BOTAO_PEQ, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y, prox_pag, x_mouse, y_mouse, click);
        }

        if(menu)
        {
            return;
        }

        if(voltar)
        {
            pagina--;
            if (pagina == 0)
            {
                return;
            }
        }
        
        if(next_page)
            pagina++;

                

        if (update)
        {
            al_flip_display();
            update = false;
        }
        
        click = 0;
    }
}

void sair()
{
    exit(0);
}

int main()
{
    srand(time(NULL));
    inicializar();

    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    ALLEGRO_DISPLAY* display = al_create_display(LARGURA_TELA, ALTURA_TELA);
    ALLEGRO_BITMAP* icon = al_load_bitmap("media/images/dice/red_6.png");
    al_set_display_icon(display, icon);

    while(1)
    {
        char selecao = menu(display);

        switch (selecao)
        {
            case 'j':
                jogo(display, 0);
                break;
            case 'r':
                jogo(display, 1);
                break;
            case 'l':
                record(display);
                break;
            case 'h':
                help(display);            
                break;
            case 's':
                sair();
                break;
        }
    }

    al_destroy_display(display);

    return 0;

}