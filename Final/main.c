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
#define OFFSET_EXTRA_DADO 25
#define OFFSET_INTRA_DADO 15

#define FILA_ANCORA_ESQUERDA_X 50
#define FILA_OFFSET_X 310
#define FILA_ANCORA_Y 850

#define BRANCO al_map_rgb(255, 255, 255)
#define PRETO al_map_rgb(0, 0, 0)
#define AZUL_ESCURO al_map_rgb(0, 15, 50)

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
    ALLEGRO_COLOR cor;
    float x, y;
};

struct dados_gerados
{
    bool ocupada;
    int qnt_dados;
    int numeros[3];
    int rotacao;

    float x[3], y[3];
    float x_origem[3], y_origem[3];

    float click_point_diff_x[3];
    float click_point_diff_y[3];
    bool puxada;
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

void posiciona_dados(struct dados_gerados fila_dados[])
{
    
    for (int i = 0; i < 3; i++)
    {
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

void jogo(ALLEGRO_DISPLAY* display, int restaura)
{
    ALLEGRO_FONT* font_2p_regular_72 = al_load_ttf_font("media/fonts/PressStart2P-regular.ttf", 72, 0);
    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));
    ALLEGRO_EVENT event;

    ALLEGRO_BITMAP* matriz_background = al_load_bitmap("media/images/matriz.png");
    ALLEGRO_BITMAP* botao_sair = al_load_bitmap("media/images/buttons/sair.png");
    ALLEGRO_BITMAP* botao_salvar_e_sair = al_load_bitmap("media/images/buttons/salvar_e_sair.png");
    ALLEGRO_BITMAP* botao_menu_peq = al_load_bitmap("media/images/buttons/menu_peq.png");
    ALLEGRO_BITMAP* botao_voltar = al_load_bitmap("media/images/buttons/voltar.png");

    ALLEGRO_BITMAP* red_0 = al_load_bitmap("media/images/dice/red_0.png");
    ALLEGRO_BITMAP* red_1 = al_load_bitmap("media/images/dice/red_1.png");
    ALLEGRO_BITMAP* red_2 = al_load_bitmap("media/images/dice/red_2.png");
    ALLEGRO_BITMAP* red_3 = al_load_bitmap("media/images/dice/red_3.png");
    ALLEGRO_BITMAP* red_4 = al_load_bitmap("media/images/dice/red_4.png");
    ALLEGRO_BITMAP* red_5 = al_load_bitmap("media/images/dice/red_5.png");
    ALLEGRO_BITMAP* red_6 = al_load_bitmap("media/images/dice/red_6.png");

    ALLEGRO_MOUSE_STATE state;

    float x_mouse = 0, y_mouse = 0;
    int click = 0, release = 0, held = 0;
    bool submenu_aberto = 0;

    bool update = true;
    al_start_timer(timer_fps);

    struct celula matriz[5][5];
    struct dados_gerados fila_dados[3];
    
    for (int i = 0; i < 3; i++)
    {
        fila_dados[i].ocupada = false;
        fila_dados[i].puxada = false;
    }

    gera_dados(fila_dados);
    posiciona_dados(fila_dados);


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
                
                for (int i = 0; i < 3; i++)
                {
                    fila_dados[i].puxada = 0;
                }
                
                break;
        }

        al_clear_to_color(AZUL_ESCURO);
        al_draw_bitmap(matriz_background, 0, 0, 0);

        for (int i = 0; i < 3; i++)
        {
            if (fila_dados[i].ocupada)
            {
            
                for (int j = 0; j < fila_dados[i].qnt_dados; j++)
                {
                    switch (fila_dados[i].numeros[j])
                    {
                        case 0:
                            al_draw_bitmap(red_0, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 1:
                            al_draw_bitmap(red_1, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 2:
                            al_draw_bitmap(red_2, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 3:
                            al_draw_bitmap(red_3, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 4:
                            al_draw_bitmap(red_4, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 5:
                            al_draw_bitmap(red_5, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                        case 6:
                            al_draw_bitmap(red_6, fila_dados[i].x[j], fila_dados[i].y[j], 0);
                            break;
                    }
                }
            
            }
        }
        

        bool pause_click = botao_pequeno(LARGURA_TELA-LARG_BOTAO_PEQ-OFFSET_BOTAO_PEQ_X, OFFSET_BOTAO_PEQ_Y, botao_menu_peq, x_mouse, y_mouse, click);

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

        bool voltar = botao_pequeno(OFFSET_BOTAO_PEQ_X, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y, botao_voltar, x_mouse, y_mouse, click);
        bool next_page = 0;
        if (pagina < 4)
            next_page = botao_pequeno(LARGURA_TELA-OFFSET_BOTAO_PEQ_X-LARG_BOTAO_PEQ, ALTURA_TELA-ALT_BOTAO_PEQ-OFFSET_BOTAO_PEQ_Y, prox_pag, x_mouse, y_mouse, click);

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

    /*ALLEGRO_FONT* font_play_regular_18 = al_load_ttf_font("media/fonts/Play-regular.ttf", 24, 0);
    ALLEGRO_FONT* font_play_regular_24 = al_load_ttf_font("media/fonts/Play-regular.ttf", 24, 0);
    ALLEGRO_FONT* font_play_regular_36 = al_load_ttf_font("media/fonts/Play-regular.ttf", 36, 0);
    ALLEGRO_FONT* font_play_regular_48 = al_load_ttf_font("media/fonts/Play-regular.ttf", 48, 0);
    ALLEGRO_FONT* font_play_regular_60 = al_load_ttf_font("media/fonts/Play-regular.ttf", 60, 0);
    ALLEGRO_FONT* font_play_regular_72 = al_load_ttf_font("media/fonts/Play-regular.ttf", 72, 0);

    ALLEGRO_FONT* font_play_bold_18 = al_load_ttf_font("media/fonts/Play-bold.ttf", 24, 0);
    ALLEGRO_FONT* font_play_bold_24 = al_load_ttf_font("media/fonts/Play-bold.ttf", 24, 0);
    ALLEGRO_FONT* font_play_bold_36 = al_load_ttf_font("media/fonts/Play-bold.ttf", 36, 0);
    ALLEGRO_FONT* font_play_bold_48 = al_load_ttf_font("media/fonts/Play-bold.ttf", 48, 0);
    ALLEGRO_FONT* font_play_bold_60 = al_load_ttf_font("media/fonts/Play-bold.ttf", 60, 0);
    ALLEGRO_FONT* font_play_bold_72 = al_load_ttf_font("media/fonts/Play-bold.ttf", 72, 0);*/

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
    

    
    
    ALLEGRO_EVENT event;
    bool update = true; 


    al_destroy_display(display);

    return 0;

}