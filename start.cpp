#include <C:\Users\Maciej\Dropbox\Polibuda\ProjektC\C\start.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>

int start()
{
    ALLEGRO_BITMAP  *menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP  *nowagra = al_load_bitmap("nowagra.png");
    ALLEGRO_BITMAP  *wyjscie = al_load_bitmap("wyjscie.png");

}
int destroy(){
    al_destroy_bitmap(menu);
    al_destroy_bitmap(nowagra);
    al_destroy_bitmap(wyjscie);
}



