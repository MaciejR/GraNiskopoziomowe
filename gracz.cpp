#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <math.h>
int x=350, y=295, xKafelka =-465, statycznaKafelka =-465, xNiebo =-465, statyczneNiebo =-465,xNPC=800,yNPC=325,obrot=360,czestotliwoscObrotu=0;
int jump = 0;
int jumpLong = 0;
int gra=0;
int i,n;
int skierowany = 1; //na prawo
ALLEGRO_KEYBOARD_STATE klawiatura;
ALLEGRO_COLOR podstawowyKolor = al_map_rgb(255, 255, 255);
ALLEGRO_BITMAP  *gracz = al_load_bitmap("gracz.png");
ALLEGRO_BITMAP  *tlo = al_load_bitmap("tlo.png");
ALLEGRO_BITMAP  *kafelek = al_load_bitmap("kafelek.png");
ALLEGRO_BITMAP  *swinia = al_load_bitmap("swinia.png");
int graj(){



return 0;

}
