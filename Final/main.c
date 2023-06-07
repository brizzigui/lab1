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

void inicializar()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_image_addon();
    al_init_ttf_addon();
}

int main()
{
    inicializar();

    ALLEGRO_TIMER* timer_fps = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    ALLEGRO_DISPLAY* display = al_create_display(LARGURA_TELA, ALTURA_TELA);

    ALLEGRO_FONT* font_play_regular_18 = al_load_ttf_font("media/fonts/Play-regular.ttf", 24, 0);
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
    ALLEGRO_FONT* font_play_bold_72 = al_load_ttf_font("media/fonts/Play-bold.ttf", 72, 0);

    ALLEGRO_BITMAP* matriz_background = al_load_bitmap("media/images/matriz.png");
    

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer_fps));

    bool update = true; 
    ALLEGRO_EVENT event;

    al_start_timer(timer_fps);

    while (1)
    {
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            update = true;
        }       

        else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    break;
        }
                            

        al_wait_for_event(queue, &event);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(matriz_background, 0, 0, 0);


        if (update)
        {
            al_flip_display();
            update = false;
        }
            
    }
    

    
    al_destroy_font(font_play_regular_24);
    al_destroy_display(display);
    al_destroy_timer(timer_fps);
    al_destroy_event_queue(queue);

    return 0;

}