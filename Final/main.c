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

#define LARG_BOTAO_MINI 50
#define ALT_BOTAO_MINI 55

#define LADO_DADO 100
#define OFFSET_INTRA_DADO 15

#define FILA_ANCORA_ESQUERDA_X 65
#define FILA_OFFSET_X 310
#define FILA_ANCORA_Y 835

#define MATRIZ_ANCORA_X 150
#define MATRIZ_ANCORA_Y 200

#define RAIO_INDICADOR_PTS 20
#define INDICADORES_PTS_ANCORA_X MATRIZ_ANCORA_X+(LADO_DADO+OFFSET_INTRA_DADO)*5 + RAIO_INDICADOR_PTS
#define INDICADORES_PTS_ANCORA_Y MATRIZ_ANCORA_Y+(LADO_DADO+OFFSET_INTRA_DADO)*5 + RAIO_INDICADOR_PTS

#define OFFSET_PROGRESS_BARS 50
#define ALTURA_PROGRESS_BARS 70
#define LARG_PROGRESS_BARS 400
#define LARG_PROGRESS_BARS_INT 360

#define BRANCO al_map_rgb(255, 255, 255)
#define PRETO al_map_rgb(0, 0, 0)
#define AZUL_MUITO_ESCURO al_map_rgb(0, 5, 25)
#define AZUL_ESCURO al_map_rgb(0, 15, 50)
#define AZUL_MEDIO al_map_rgb(0, 25, 80)
#define AZUL_CLARO al_map_rgb(90, 150, 240)
#define VERMELHO al_map_rgb(160, 0, 0)
#define VERMELHO_ESCURO al_map_rgb(90, 0, 0)
#define LARANJA al_map_rgb(255, 123, 41)
#define LARANJA_ESCURO al_map_rgb(252, 98, 3)

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

    bool ir_jogar, ir_restaurar, ir_record, ir_help, ir_sair;

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

        ir_jogar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, 450, botao_jogar, x_mouse, y_mouse, click);
        ir_restaurar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO-OFFSET_BOTAO_PADRAO_X, 450+ALT_BOTAO_PADRAO+OFFSET_BOTAO_PADRAO_Y, botao_restaurar, x_mouse, y_mouse, click);
        ir_record = botao_padrao(LARGURA_TELA/2+OFFSET_BOTAO_PADRAO_X, 450+ALT_BOTAO_PADRAO+OFFSET_BOTAO_PADRAO_Y, botao_record, x_mouse, y_mouse, click);
        ir_help = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO-OFFSET_BOTAO_PADRAO_X, 450+(OFFSET_BOTAO_PADRAO_Y+ALT_BOTAO_PADRAO)*2, botao_help, x_mouse, y_mouse, click);
        ir_sair = botao_padrao(LARGURA_TELA/2+OFFSET_BOTAO_PADRAO_X, 450+(OFFSET_BOTAO_PADRAO_Y+ALT_BOTAO_PADRAO)*2, botao_sair, x_mouse, y_mouse, click);


        if(ir_jogar || ir_restaurar || ir_record || ir_help || ir_sair)
        {
            break;
        }

        if (update)
        {
            al_flip_display();
            update = false;
        }

        click = 0;
    }

    al_destroy_bitmap(botao_jogar);
    al_destroy_bitmap(botao_restaurar);
    al_destroy_bitmap(botao_record);
    al_destroy_bitmap(botao_help);
    al_destroy_bitmap(botao_sair);
    al_destroy_event_queue(queue);
    al_destroy_font(font_2p_regular_72);
    al_destroy_timer(timer_fps);

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
}

int digitos(int num)
{
    int qnt = 0;
    while(num >= 1)
    {
        num = num/10;
        qnt++;
    }

    return qnt;
}

struct celula
{
    bool animando;
    int cell_animation_frames;
    bool ocupada;
    int num_dado;
    int cor;
    ALLEGRO_BITMAP* bitmap;
    float x, y;
};

struct dados_gerados
{
    bool animando;
    int frames;
    bool ocupada;
    bool foi_rotacionada;
    int qnt_dados;
    int numeros[3];
    int rotacao;
    int cor;

    float x[3], y[3];
    float x_origem[3], y_origem[3];
    float anim_diff_x, anim_diff_y;
    ALLEGRO_BITMAP* bitmap[3];

    float click_point_diff_x[3];
    float click_point_diff_y[3];
    bool puxada;
};

struct controla_jogo
{
    bool change;
    int broken;
    int pont;

    bool tab_concl;
    bool multilinha;
    int combo;

    int linhas_broken[5];
    int colunas_broken[5];
};

struct totais
{
    int pts_rotacao;
    int combo_multi;
    int tabs_concl;
};


void load_dice(ALLEGRO_BITMAP* red[7], ALLEGRO_BITMAP* blue[7], ALLEGRO_BITMAP* yellow[7], ALLEGRO_BITMAP* green[7], ALLEGRO_BITMAP* purple[7])
{   
    char file_name[64];

    for (int i = 0; i < 7; i++)
    {
        sprintf(file_name, "media/images/dice/red_%d.png", i);
        red[i] = al_load_bitmap(file_name);
    }

    for (int i = 0; i < 7; i++)
    {
        sprintf(file_name, "media/images/dice/blue_%d.png", i);
        blue[i] = al_load_bitmap(file_name);
    }

    for (int i = 0; i < 7; i++)
    {
        sprintf(file_name, "media/images/dice/yellow_%d.png", i);
        yellow[i] = al_load_bitmap(file_name);
    }

    for (int i = 0; i < 7; i++)
    {
        sprintf(file_name, "media/images/dice/green_%d.png", i);
        green[i] = al_load_bitmap(file_name);
    }

    for (int i = 0; i < 7; i++)
    {
        sprintf(file_name, "media/images/dice/purple_%d.png", i);
        purple[i] = al_load_bitmap(file_name);
    }
    

}

void destroy_dice(ALLEGRO_BITMAP* red[], ALLEGRO_BITMAP* blue[], ALLEGRO_BITMAP* yellow[], ALLEGRO_BITMAP* green[], ALLEGRO_BITMAP* purple[])
{
    for (int i = 0; i < 7; i++)
    {
        al_destroy_bitmap(red[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        al_destroy_bitmap(blue[i]);
    }
    
    for (int i = 0; i < 7; i++)
    {
        al_destroy_bitmap(yellow[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        al_destroy_bitmap(green[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        al_destroy_bitmap(purple[i]);
    }
}

void load_cell_animation(ALLEGRO_BITMAP* cell_animation[30])
{
    char file_name[64];
    for (int i = 0; i < 30; i++)
    {
        sprintf(file_name, "media/images/animation/%d.png", i);
        cell_animation[i] = al_load_bitmap(file_name);
    }
    
}

void destroy_cell_animation(ALLEGRO_BITMAP* cell_animation[30])
{
    for (int i = 0; i < 30; i++)
    {
        al_destroy_bitmap(cell_animation[i]);
    }
}

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
        fila[i].foi_rotacionada = false;

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

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < fila_dados[i].qnt_dados; j++)
        {
            fila_dados[i].x_origem[j] = fila_dados[i].x[j];
            fila_dados[i].y_origem[j] = fila_dados[i].y[j];
        }
        
    }
    
    
    
}

void cria_matriz(struct celula matriz[5][5], ALLEGRO_BITMAP* cell)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j].animando = false;
            matriz[i][j].ocupada = false;
            matriz[i][j].cell_animation_frames = 0;
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

void salva_estado_dados(struct dados_gerados previous_fila_dados[3], struct celula previous_matriz[5][5], struct dados_gerados fila_dados[3], struct celula matriz[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            previous_matriz[i][j] = matriz[i][j];
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        previous_fila_dados[i] = fila_dados[i];
    }

}

void undo_estado_dados(struct dados_gerados previous_fila_dados[3], struct celula previous_matriz[5][5], struct dados_gerados fila_dados[3], struct celula matriz[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = previous_matriz[i][j];
        }
        
    }
    
    int qnt_ocupadas = 0;
    for (int i = 0; i < 3; i++)
    {
        if (fila_dados[i].ocupada)
        {
            qnt_ocupadas++;
        } 
    }
    
    if (qnt_ocupadas == 3)
    {
        int idx_ultima_mov;
        for (int i = 0; i < 3; i++)
        {
            if(previous_fila_dados[i].ocupada)
            {
                idx_ultima_mov = i;
            }
        }
        
        fila_dados[2] = previous_fila_dados[idx_ultima_mov];
    }
    
    else
    {
        for (int i = 0; i < 3; i++)
        {
            fila_dados[i] = previous_fila_dados[i];
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

int intersec(struct dados_gerados fila[], struct celula matriz[5][5], struct dados_gerados previous_fila_dados[3], struct celula previous_matriz[5][5])
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


        if(encaixe_possivel == fila[a].qnt_dados && fila[a].ocupada == true && fila[a].animando == false)
        {
            salva_estado_dados(previous_fila_dados, previous_matriz, fila, matriz);
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

    for (int i = 0; i < 5; i++)
    {
        al_draw_filled_circle(INDICADORES_PTS_ANCORA_X, MATRIZ_ANCORA_Y+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*i, RAIO_INDICADOR_PTS, AZUL_CLARO);
        al_draw_textf(font_play_bold_24, BRANCO, INDICADORES_PTS_ANCORA_X, MATRIZ_ANCORA_Y+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*i-0.75*RAIO_INDICADOR_PTS, ALLEGRO_ALIGN_CENTER, "%d", soma_linha[i]);
    }

    for (int j = 0; j < 5; j++)
    {
        al_draw_filled_circle(MATRIZ_ANCORA_X+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*j, MATRIZ_ANCORA_Y-OFFSET_INTRA_DADO-RAIO_INDICADOR_PTS, RAIO_INDICADOR_PTS, AZUL_CLARO);
        al_draw_textf(font_play_bold_24, BRANCO, MATRIZ_ANCORA_X+LADO_DADO/2+(LADO_DADO+OFFSET_INTRA_DADO)*j, MATRIZ_ANCORA_Y-OFFSET_INTRA_DADO-1.75*RAIO_INDICADOR_PTS, ALLEGRO_ALIGN_CENTER, "%d", soma_coluna[j]);
    }
    
}

int checa_soma(ALLEGRO_DISPLAY* display, struct celula matriz[5][5], int soma_linha[5], int soma_coluna[5], struct controla_jogo *controlador, struct totais *controlador_bonus)
{
    controlador->change = false;
    controlador->multilinha = false;
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
                        (controlador_bonus->pts_rotacao)++;
                    }
                    
                    matriz[i][j].ocupada = false;
                    matriz[i][j].animando = true;
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
                        (controlador_bonus->pts_rotacao)++;
                    }
                    
                    matriz[i][j].ocupada = false;
                    matriz[i][j].animando = true;
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

        if (controlador->broken > 0)
        {
            controlador->change = true;
        }
        

        if (qnt_ocupadas == 0 && controlador->change && controlador->tab_concl == false)
        {
            controlador->tab_concl = true;
            controlador->pont += 10;
            controlador_bonus->pts_rotacao += 10;
            controlador_bonus->tabs_concl++;
        }

        else
        {
            controlador->tab_concl = false;
        }
        
        if (controlador->broken > 0 && cont > 0)
        {
            controlador->combo++;
            controlador->pont += 5;
            controlador_bonus->pts_rotacao += 5;
            controlador_bonus->combo_multi++;
        }
        

        if(controlador->broken > 1)
        {
            controlador->multilinha = true;
            controlador->pont += 7;
            controlador_bonus->pts_rotacao += 7;
            controlador_bonus->combo_multi++;
        }

        cont++;
        somatorios(matriz, soma_linha, soma_coluna);

    } while (controlador->broken != 0);
    
    
}

int tem_espaco(struct celula matriz[5][5], struct dados_gerados fila)
{
    switch (fila.qnt_dados)
    {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (!matriz[i][j].ocupada)
                    {
                        return true;
                    }
                    
                }
                
            }
            
            break;
        
        case 2:
            switch (fila.rotacao)
            {
                case 0: case 2:
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (!matriz[i][j].ocupada && !matriz[i][j+1].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }
                    
                    break;
                
                case 1: case 3:

                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            if (!matriz[i][j].ocupada && !matriz[i+1][j].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }
                    break;
            }
            break;

        case 3:

            switch (fila.rotacao)
            {
                case 0:
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (!matriz[i][j].ocupada && !matriz[i+1][j].ocupada && !matriz[i+1][j+1].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }
                    
                    break;
                
                case 1:
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (!matriz[i][j].ocupada && !matriz[i+1][j].ocupada && !matriz[i][j+1].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }
                    break;

                case 2:
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (!matriz[i][j].ocupada && !matriz[i][j+1].ocupada && !matriz[i+1][j+1].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }
                    break;

                case 3:
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (!matriz[i][j+1].ocupada && !matriz[i+1][j].ocupada && !matriz[i+1][j+1].ocupada)
                            {
                                return true;
                            }
                            
                        }
                        
                    }

                    break;
            }
            
            break;
    }

    return false;
}

int checa_game_over(struct celula matriz[5][5], struct dados_gerados fila[3], int rotacoes, int bombas, bool tem_undo)
{

    bool tem_jogada;

    if (tem_undo || bombas > 0)
    {
        return false;
    }  
    
    for (int a = 0; a < 3; a++)
    {
        if (fila[a].ocupada)
        {
            if((rotacoes > 0 || fila[a].foi_rotacionada) && fila[a].qnt_dados >= 2)
            {
                struct dados_gerados fila_copia = fila[a];
                for (int i = 0; i < 4; i++)
                {
                    fila_copia.rotacao = i;
                    tem_jogada = tem_espaco(matriz, fila_copia);
                    if (tem_jogada)
                    {
                        return false;
                    }
                }

            }

            else
            {
                tem_jogada = tem_espaco(matriz, fila[a]);
                if (tem_jogada)
                {
                    return false;
                }
            }
            
            
        }
        
    }

    return true;
    
}

void salva_jogo(struct celula matriz[5][5], struct celula previous_matriz[5][5], 
                struct dados_gerados fila_dados[3], struct dados_gerados previous_fila_dados[3],
                struct controla_jogo controlador, struct controla_jogo previous_controlador,
                struct totais controlador_bonus, struct totais previous_controlador_bonus,
                int soma_linha[5], int soma_coluna[5])
{

    FILE *save_file = fopen("save_files/last.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(save_file, "%d %d %d %f %f\n", matriz[i][j].ocupada, matriz[i][j].num_dado, matriz[i][j].cor, matriz[i][j].x, matriz[i][j].y);
        } 
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(save_file, "%d %d %d %f %f\n", previous_matriz[i][j].ocupada, previous_matriz[i][j].num_dado, previous_matriz[i][j].cor, previous_matriz[i][j].x, previous_matriz[i][j].y);
        } 
    }
    
    for (int a = 0; a < 3; a++)
    {
        
    }
    
    
    
    
}

void restaura_jogo_salvo()
{
    /*rotacoes = controlador_bonus.pts_rotacao/50;
    bombas = controlador_bonus.combo_multi/10;
    if(controlador_bonus.tabs_concl >= 5)
    {
        tem_undo = true;
    }*/
}

bool fora_do_lugar(struct dados_gerados fila)
{
    return (fabs(fila.x[0] - fila.x_origem[0]) >= 5 || fabs(fila.y[0] - fila.y_origem[0]) >= 5);
}

float distancia_atual(struct dados_gerados fila)
{
    return sqrt((double)((fila.x_origem[0] - fila.x[0])*(fila.x_origem[0] - fila.x[0]) + (fila.y_origem[0] - fila.y[0])*(fila.y_origem[0] - fila.y[0]))) ;
}
void jogo(ALLEGRO_DISPLAY* display, int restaura)
{
    ALLEGRO_FONT* font_2p_regular_18 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 18, 0);
    ALLEGRO_FONT* font_2p_regular_22 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 22, 0);
    ALLEGRO_FONT* font_2p_regular_36 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 36, 0);
    ALLEGRO_FONT* font_2p_regular_48 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 48, 0);
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
    ALLEGRO_BITMAP* cell_animation[30];
    load_cell_animation(cell_animation);
    
    ALLEGRO_BITMAP* botao_sair = al_load_bitmap("media/images/buttons/sair.png");
    ALLEGRO_BITMAP* botao_sair_peq = al_load_bitmap("media/images/buttons/sair_peq.png");
    ALLEGRO_BITMAP* botao_salvar_e_sair = al_load_bitmap("media/images/buttons/salvar_e_sair.png");
    ALLEGRO_BITMAP* botao_menu_peq = al_load_bitmap("media/images/buttons/menu_peq.png");
    ALLEGRO_BITMAP* botao_voltar = al_load_bitmap("media/images/buttons/voltar.png");
    ALLEGRO_BITMAP* botao_rotate = al_load_bitmap("media/images/buttons/placeholder_mini.png");
    ALLEGRO_BITMAP* botao_jogar = al_load_bitmap("media/images/buttons/jogar.png");

    ALLEGRO_BITMAP* progress_bar_blue = al_load_bitmap("media/images/progress_bars/light_blue.png");
    ALLEGRO_BITMAP* progress_bar_red = al_load_bitmap("media/images/progress_bars/red.png");
    ALLEGRO_BITMAP* progress_bar_green = al_load_bitmap("media/images/progress_bars/green.png");

    ALLEGRO_BITMAP* back_progress_bar_blue = al_load_bitmap("media/images/progress_bars/back_light_blue.png");
    ALLEGRO_BITMAP* back_progress_bar_red = al_load_bitmap("media/images/progress_bars/back_red.png");
    ALLEGRO_BITMAP* back_progress_bar_green = al_load_bitmap("media/images/progress_bars/back_green.png");

    ALLEGRO_BITMAP* rotate_icon = al_load_bitmap("media/images/icons/rotate.png");
    ALLEGRO_BITMAP* undo_icon = al_load_bitmap("media/images/icons/undo.png");

    ALLEGRO_BITMAP* back_game_over = al_load_bitmap("media/images/back_game_over.png");
    
    ALLEGRO_BITMAP *red[7], *blue[7], *yellow[7], *green[7], *purple[7];
    load_dice(red, blue, yellow, green, purple);

    float x_mouse = 0, y_mouse = 0;
    int click = 0, release = 0, held = 0;
    int ticks = 0;
    bool submenu_aberto = false;
    bool pause_click = false;
    bool update = true;
    bool game_over = false;

    bool sair_salvando, sair_sem_salvar, jogar_novamente = false;

    struct celula matriz[5][5];
    struct celula previous_matriz[5][5];

    struct dados_gerados fila_dados[3];
    struct dados_gerados previous_fila_dados[3];

    struct controla_jogo controlador;
    struct controla_jogo previous_controlador;

    controlador.pont = 0;
    controlador.tab_concl = true;

    struct totais controlador_bonus;
    struct totais previous_controlador_bonus;
    controlador_bonus.pts_rotacao = 0;
    controlador_bonus.combo_multi = 0;
    controlador_bonus.tabs_concl = 0;
    int rotacoes = 0, bombas = 0;
    bool tem_undo = false;

    int soma_linha[5] = {}, soma_coluna[5] = {};

    int max_pont, tempo_max_pont;
    bool reset_highscore = false;

    FILE *high_score;
    high_score = fopen("save_files/high_score.txt", "r");
    if (high_score == NULL)
    {
        max_pont = 0;
        tempo_max_pont = 0;
    }

    else
    {
        fscanf(high_score, "%d %d", &max_pont, &tempo_max_pont);
    }

    fclose(high_score);

    
    for (int i = 0; i < 3; i++)
    {
        fila_dados[i].animando = false;
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

        al_clear_to_color(AZUL_ESCURO);
        al_draw_filled_rectangle(LARGURA_TELA/2, 0, LARGURA_TELA, ALTURA_TELA, AZUL_MEDIO);
        al_draw_bitmap(background, 0, 0, 0);  
        al_draw_textf(font_2p_regular_72, BRANCO, MATRIZ_ANCORA_X+2.5*LADO_DADO+2*OFFSET_INTRA_DADO, MATRIZ_ANCORA_Y-165, ALLEGRO_ALIGN_CENTRE, "%d", controlador.pont);

        al_draw_filled_rounded_rectangle(LARGURA_TELA/2+50, 55-30, LARGURA_TELA/2+290+50, 55+70, 10, 10, AZUL_CLARO);
        al_draw_textf(font_2p_regular_48, BRANCO, LARGURA_TELA/2+50+25, 55, ALLEGRO_ALIGN_LEFT, "%02d:%02d", (ticks/60/60), (ticks/60)%60);

        display_somatorios(soma_linha, soma_coluna, font_play_bold_24);
              
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                al_draw_bitmap(matriz[i][j].bitmap, matriz[i][j].x, matriz[i][j].y, 0);
            }
            
        }

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

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER: 

                if(!submenu_aberto && !game_over)
                {
                    ticks++;
                }

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

                    else if (fila_dados[i].animando)
                    {
                        fila_dados[i].frames++;

                        if (fila_dados[i].frames >= 30)
                        {
                            fila_dados[i].animando = false;
                        }

                        float speed_x = (fila_dados[i].anim_diff_x)/30;
                        float speed_y = (fila_dados[i].anim_diff_y)/30;

                        for (int j = 0; j < fila_dados[i].qnt_dados; j++)
                        {
                            fila_dados[i].x[j] = fila_dados[i].x[j] + speed_x;
                            fila_dados[i].y[j] = fila_dados[i].y[j] + speed_y;

                        }
                        
                    }
                    
                }


                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (matriz[i][j].animando)
                        {
                            matriz[i][j].cell_animation_frames++;
                            if (matriz[i][j].cell_animation_frames >= 29)
                            {
                                matriz[i][j].animando = false;
                                matriz[i][j].cell_animation_frames = 0;
                            }

                            al_draw_bitmap(cell_animation[matriz[i][j].cell_animation_frames], matriz[i][j].x, matriz[i][j].y, 0);
                            
                        }
                        
                    }  
                }
                

                break;
            
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                x_mouse = state.x;
                y_mouse = state.y;
                click = 1;

                if (!submenu_aberto)
                {
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
                }
                
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                x_mouse = state.x;
                y_mouse = state.y;
                release = 1;

                for (int a = 0; a < 3; a++)
                {
                    fila_dados[a].puxada = 0;
                }

                previous_controlador = controlador;
                previous_controlador_bonus = controlador_bonus;

                if (intersec(fila_dados, matriz, previous_fila_dados, previous_matriz))
                {
                    somatorios(matriz, soma_linha, soma_coluna);
                    checa_soma(display, matriz, soma_linha, soma_coluna, &controlador, &controlador_bonus);
                    
                    rotacoes = controlador_bonus.pts_rotacao/50;
                    bombas = controlador_bonus.combo_multi/10;
                    if(controlador_bonus.tabs_concl >= 5)
                    {
                        tem_undo = true;
                    }

                    atualiza_matriz(matriz, cell, red, blue, yellow, green, purple);
                }

                else
                {
                    for (int i = 0; i < 3; i++)
                    {
                        if (fila_dados[i].ocupada && !fila_dados[i].animando && distancia_atual(fila_dados[i]) >= 5)
                        {
                            fila_dados[i].animando = true;
                            fila_dados[i].frames = 0;
                            fila_dados[i].anim_diff_x = fila_dados[i].x_origem[0] - fila_dados[i].x[0];
                            fila_dados[i].anim_diff_y = fila_dados[i].y_origem[0] - fila_dados[i].y[0];
                        }
                    }
                    
                }
                
                
                int ocupadas = 0;

                for (int a = 0; a < 3; a++)
                {
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
        
        al_draw_text(font_2p_regular_36, BRANCO, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y, 0, "Bônus");

        al_draw_bitmap(back_progress_bar_blue, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*2, 0);
        al_draw_filled_rectangle(LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20, 
                                MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*2+10, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20 + LARG_PROGRESS_BARS_INT*((controlador_bonus.pts_rotacao%50)/50.0), 
                                MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*2+ALTURA_PROGRESS_BARS-10, BRANCO);
        al_draw_bitmap(progress_bar_blue, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*2, 0);
        al_draw_textf(font_play_bold_24, BRANCO, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*1.25, 0, "Rotações: %d", rotacoes);

        al_draw_bitmap(back_progress_bar_red, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS+OFFSET_PROGRESS_BARS*3, 0);
        al_draw_filled_rectangle(LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20, 
                                MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS+OFFSET_PROGRESS_BARS*3+10, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20 + LARG_PROGRESS_BARS_INT*(controlador_bonus.combo_multi%10)/10, 
                                MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*3+ALTURA_PROGRESS_BARS*2-10, BRANCO);
        al_draw_bitmap(progress_bar_red, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS+OFFSET_PROGRESS_BARS*3, 0);
        al_draw_textf(font_play_bold_24, BRANCO, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS+OFFSET_PROGRESS_BARS*2.25, 0, "Bombas: %d", bombas);

        al_draw_bitmap(back_progress_bar_green, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS*2+OFFSET_PROGRESS_BARS*4, 0);
        al_draw_filled_rectangle(LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20, 
                                MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS*2+OFFSET_PROGRESS_BARS*4+10, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + 20 + LARG_PROGRESS_BARS_INT*(controlador_bonus.tabs_concl%5)/5, 
                                MATRIZ_ANCORA_Y+OFFSET_PROGRESS_BARS*4+ALTURA_PROGRESS_BARS*3-10, BRANCO);
        al_draw_bitmap(progress_bar_green, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS*2+OFFSET_PROGRESS_BARS*4, 0);
        char string_undo[64];
        if (tem_undo)
            sprintf(string_undo, "Undo: disponível", 0);
        else
            sprintf(string_undo, "Undo: indisponível", 0);
        al_draw_textf(font_play_bold_24, BRANCO, LARGURA_TELA/2 + OFFSET_PROGRESS_BARS, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS*2+OFFSET_PROGRESS_BARS*3.25, 0, string_undo);


        for (int i = 0; i < 3; i++)
        {
            if ((rotacoes >= 1 || fila_dados[i].foi_rotacionada) && fila_dados[i].qnt_dados >= 2 && fila_dados[i].ocupada)
            {
                bool rotacionou = botao_mini(FILA_ANCORA_ESQUERDA_X+LADO_DADO-LARG_BOTAO_MINI/2+FILA_OFFSET_X*i, FILA_ANCORA_Y-65, botao_rotate, x_mouse, y_mouse, click);
                if (rotacionou)
                {
                    if (!fila_dados[i].foi_rotacionada)
                    {
                        rotacoes--;
                        controlador_bonus.pts_rotacao -= 50;
                    }
                    
                    fila_dados[i].foi_rotacionada = true;
                    fila_dados[i].rotacao = (fila_dados[i].rotacao+1)%4;


                    posiciona_dados(fila_dados, red, blue, yellow, green, purple);
                }
            }
        }

        if (bombas >= 1)
        {
            bool usou_bomba = botao_mini(LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + LARG_PROGRESS_BARS_INT + LARG_BOTAO_MINI, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS+OFFSET_PROGRESS_BARS*3+10, botao_rotate, x_mouse, y_mouse, click);
            if (usou_bomba)
            {
                salva_estado_dados(previous_fila_dados, previous_matriz, fila_dados, matriz);
                previous_controlador = controlador;
                previous_controlador_bonus = controlador_bonus;


                int qnt_explodidas = rand() % 2 + 1;
                int prim_linha = rand() % 5;
                int prim_coluna = rand() % 5;
                int seg_linha, seg_coluna;

                for (int i = 0; i < 5; i++)
                {
                    matriz[prim_linha][i].ocupada = false;
                    matriz[i][prim_coluna].ocupada = false;
                    matriz[prim_linha][i].animando = true;
                    matriz[i][prim_coluna].animando = true;
                }
                

                if (qnt_explodidas >= 2)
                {
                    do
                    {
                        seg_linha = rand() % 5;
                        seg_coluna = rand() % 5;

                    } while (prim_linha == seg_linha || prim_coluna == seg_coluna);
                    
                    for (int i = 0; i < 5; i++)
                    {
                        matriz[seg_linha][i].ocupada = false;
                        matriz[i][seg_coluna].ocupada = false;
                        matriz[seg_linha][i].animando = true;
                        matriz[i][seg_coluna].animando = true;
                    }

                }    

                bombas--;
                controlador_bonus.combo_multi -= 10;
                atualiza_matriz(matriz, cell, red, blue, yellow, green, purple);
                somatorios(matriz, soma_linha, soma_coluna);
                checa_soma(display, matriz, soma_linha, soma_coluna, &controlador, &controlador_bonus);
            }
        }
        
        
        if (tem_undo && !controlador.change)
        {
            bool usou_undo = botao_mini(LARGURA_TELA/2 + OFFSET_PROGRESS_BARS + LARG_PROGRESS_BARS_INT + LARG_BOTAO_MINI, MATRIZ_ANCORA_Y+ALTURA_PROGRESS_BARS*2+OFFSET_PROGRESS_BARS*4+10, botao_rotate, x_mouse, y_mouse, click);
            if (usou_undo)
            {
                tem_undo = false;
                controlador_bonus.tabs_concl = 0;

                undo_estado_dados(previous_fila_dados, previous_matriz, fila_dados, matriz);
                controlador = previous_controlador;
                controlador_bonus = previous_controlador_bonus;

                posiciona_dados(fila_dados, red, blue, yellow, green, purple);
                atualiza_matriz(matriz, cell, red, blue, yellow, green, purple);
                somatorios(matriz, soma_linha, soma_coluna);
            }
        }
        
        pause_click = botao_pequeno(LARGURA_TELA-LARG_BOTAO_PEQ-OFFSET_BOTAO_PEQ_X, OFFSET_BOTAO_PEQ_Y, botao_menu_peq, x_mouse, y_mouse, click);

        if (pause_click)
        {
           submenu_aberto = true; 
        } 

        if (submenu_aberto && !game_over)
        {
            al_draw_filled_rectangle(0, 0, LARGURA_TELA, ALTURA_TELA, al_map_rgba(0, 0, 0, 220));
            al_draw_text(font_2p_regular_72, BRANCO, LARGURA_TELA/2, ALTURA_TELA/4, ALLEGRO_ALIGN_CENTER, "Paused");
            sair_salvando = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y, botao_salvar_e_sair, x_mouse, y_mouse, click);
            sair_sem_salvar = botao_padrao(LARGURA_TELA/2-LARG_BOTAO_PADRAO/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y*2+ALT_BOTAO_PADRAO, botao_sair, x_mouse, y_mouse, click);
            bool voltar = botao_pequeno(LARGURA_TELA/2-LARG_BOTAO_PEQ/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y*3+ALT_BOTAO_PADRAO*2, botao_voltar, x_mouse, y_mouse, click);
             
            if (sair_salvando)
            {
                break;
            }

            else if (sair_sem_salvar)
            {
                break;
            }
            
            else if(voltar)
            {
                submenu_aberto = false;
            }
              
        }


        game_over = checa_game_over(matriz, fila_dados, rotacoes, tem_undo, bombas);

        if(game_over)
        {
            if ((controlador.pont > max_pont || (controlador.pont == max_pont && ticks/60 < tempo_max_pont)) && reset_highscore == false)
            {
                reset_highscore = true;
                max_pont = controlador.pont;
                high_score = fopen("save_files/high_score.txt", "w");
                fprintf(high_score, "%d %d", max_pont, ticks/60);
                fclose(high_score);
            }
            
            al_draw_filled_rectangle(LARGURA_TELA/2, 0, LARGURA_TELA, ALTURA_TELA, AZUL_MUITO_ESCURO);
            al_draw_text(font_2p_regular_72, VERMELHO_ESCURO, 3*LARGURA_TELA/4, ALTURA_TELA/4, ALLEGRO_ALIGN_CENTER, "Game Over!");
            al_draw_text(font_2p_regular_72, VERMELHO, 3*LARGURA_TELA/4+5, ALTURA_TELA/4+5, ALLEGRO_ALIGN_CENTER, "Game Over!");

            al_draw_bitmap(back_game_over, 3*LARGURA_TELA/4-600/2, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y, 0);
            al_draw_text(font_2p_regular_22, BRANCO, 3*LARGURA_TELA/4-600/2+35, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y+30, 0, "Sua pontuação:");
            al_draw_textf(font_2p_regular_72, AZUL_CLARO, 3*LARGURA_TELA/4-600/2+35, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y+80, 0, "%d pts", controlador.pont);
            al_draw_textf(font_2p_regular_72, BRANCO, 3*LARGURA_TELA/4-600/2+35+5, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y+80+5, 0, "%d pts", controlador.pont);
            al_draw_textf(font_2p_regular_18, BRANCO, 3*LARGURA_TELA/4-600/2+35, ALTURA_TELA/3+OFFSET_BOTAO_PADRAO_Y+205, 0, "O recorde é de %d pts", max_pont);
            
            
            jogar_novamente = botao_padrao(3*LARGURA_TELA/4-LARG_BOTAO_PADRAO/2, 3.5*ALTURA_TELA/5+OFFSET_BOTAO_PADRAO_Y, botao_jogar, x_mouse, y_mouse, click);
            sair_sem_salvar = botao_pequeno(3*LARGURA_TELA/4-LARG_BOTAO_PEQ/2, 3.5*ALTURA_TELA/5+OFFSET_BOTAO_PADRAO_Y*2+ALT_BOTAO_PADRAO, botao_sair_peq, x_mouse, y_mouse, click);
            
            if (sair_sem_salvar || jogar_novamente)
            {
                break;
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

    destroy_dice(red, blue, yellow, green, purple);
    destroy_cell_animation(cell_animation);
    al_destroy_bitmap(background);
    al_destroy_bitmap(cell);
    al_destroy_bitmap(botao_menu_peq);
    al_destroy_bitmap(botao_sair);
    al_destroy_bitmap(botao_salvar_e_sair);
    al_destroy_bitmap(botao_voltar);
    al_destroy_bitmap(botao_rotate);


    al_destroy_bitmap(progress_bar_blue);
    al_destroy_bitmap(progress_bar_red);
    al_destroy_bitmap(progress_bar_green);
    al_destroy_event_queue(queue);
    al_destroy_font(font_2p_regular_72);
    al_destroy_font(font_play_bold_24);
    al_destroy_timer(timer_fps);

    if (jogar_novamente)
    {
        jogo(display, 0);
    }
    
    return;
}

void record(ALLEGRO_DISPLAY* display)
{
    bool foi_jogado;
    int max_pont, tempo;

    FILE *high_score;
    high_score = fopen("save_files/high_score.txt", "r");

    if (high_score == NULL)
    {
        foi_jogado = false;
    }

    else
    {
        foi_jogado = true;
        fscanf(high_score, "%d %d", &max_pont, &tempo);
    }

    fclose(high_score);

    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));
    ALLEGRO_EVENT event;
    ALLEGRO_MOUSE_STATE state;

    ALLEGRO_BITMAP* background_record = al_load_bitmap("media/images/background_record.png");
    ALLEGRO_BITMAP* botao_voltar = al_load_bitmap("media/images/buttons/voltar_laranja.png");
    ALLEGRO_FONT* font_2p_regular_36 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 36, 0);
    ALLEGRO_FONT* font_2p_regular_48 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 48, 0);
    ALLEGRO_FONT* font_2p_regular_72 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 72, 0);
    ALLEGRO_FONT* font_2p_regular_144 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 144, 0);

    bool update = false;
    float x_mouse, y_mouse;
    int click = 0;

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

        al_draw_bitmap(background_record, 0, 0, 0);
        al_draw_textf(font_2p_regular_36, LARANJA, LARGURA_TELA/3-100, ALTURA_TELA/3, ALLEGRO_ALIGN_LEFT, "A pontuação máxima foi de:");
        al_draw_textf(font_2p_regular_144, LARANJA, LARGURA_TELA/3-100, ALTURA_TELA/2-50, ALLEGRO_ALIGN_LEFT, "%d", max_pont);
        al_draw_text(font_2p_regular_72, LARANJA, LARGURA_TELA/3-100+150*digitos(max_pont)+10, ALTURA_TELA/2+5, ALLEGRO_ALIGN_LEFT, "pts");
        al_draw_textf(font_2p_regular_144, LARANJA_ESCURO, LARGURA_TELA/3-100+10, ALTURA_TELA/2-50+10, ALLEGRO_ALIGN_LEFT, "%d", max_pont);
        al_draw_text(font_2p_regular_72, LARANJA_ESCURO, LARGURA_TELA/3-100+150*digitos(max_pont)+10+5, ALTURA_TELA/2+5+5, ALLEGRO_ALIGN_LEFT, "pts");
        al_draw_textf(font_2p_regular_36, LARANJA, LARGURA_TELA/3-100, ALTURA_TELA/2+125, ALLEGRO_ALIGN_LEFT, "No tempo de %02d:%02d.", tempo/60, tempo%60);      

        bool voltar = botao_pequeno(0+OFFSET_BOTAO_PEQ_X, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y, botao_voltar, x_mouse, y_mouse, click);

        if(voltar)
        {
            break;
        }

        if (update)
        {
            al_flip_display();
            update = false;
        }
         
    }
    
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
            break;
        }

        if(voltar)
        {
            pagina--;
            if (pagina == 0)
            {
                break;
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

    al_destroy_bitmap(pag1);
    al_destroy_bitmap(pag2);
    al_destroy_bitmap(pag3);
    al_destroy_bitmap(pag4);
    al_destroy_bitmap(botao_voltar);
    al_destroy_bitmap(botao_menu);
    al_destroy_bitmap(prox_pag);
    al_destroy_font(font_2p_regular_24);
    al_destroy_timer(timer_fps);
    al_destroy_event_queue(queue);
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
            case 'd':
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