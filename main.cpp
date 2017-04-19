#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#include <C:\Users\Maciej\Dropbox\Polibuda\ProjektC\C\config.h>
#include <C:\Users\Maciej\Dropbox\Polibuda\ProjektC\C\gracz.h>
#include <C:\Users\Maciej\Dropbox\Polibuda\ProjektC\C\mysz.h>
#include <C:\Users\Maciej\Dropbox\Polibuda\ProjektC\C\menu.h>

int main(){
    //inicjalizacja allegro i obslugi grafiki */
    al_init();
    al_init_image_addon();


    //tworzenie okna
    if(fullscreen == 1)
    {
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    }

    ALLEGRO_DISPLAY *okno = al_create_display(szerokosc, wysokosc);
    al_set_window_title(okno, "More Angry Birds");

    //odpalanie muzyki
     al_install_audio();
    al_init_acodec_addon();
    ALLEGRO_SAMPLE *sample = al_load_sample( "sample1.ogg" );
    al_reserve_samples(1);
    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

    //inicjalizacja klawiatury
    al_install_keyboard();

    //instalacja myszki
    al_install_mouse();

    //menu
    while(!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))
    {
        //pobieranie zdarzen klawiatury
        al_get_keyboard_state(&klawiatura);
        if ( przycisk==1 && xMyszki>=530 && xMyszki<=686 && yMyszki>=180 && yMyszki<=254)
        {
            break;
        }
        if (al_key_down(&klawiatura, ALLEGRO_KEY_ENTER ) || ( przycisk==1 && xMyszki>=530 && xMyszki<=686 && yMyszki>=100 && yMyszki<=174) )
        {
            gra=1;

        }

        al_clear_to_color(podstawowyKolor);
        al_draw_bitmap(menu,0,0,0);
        al_draw_bitmap(nowagra,530,100,0);
        al_draw_bitmap(wyjscie,530,180,0);
        //al_get_keyboard_state(&klawiatura);
        al_flip_display();

        //opoznienie petli - timer
        al_rest(0.005);

        //petla gry
        while(gra==1)
        {

            //pobieranie zdarzen klawiatury
            al_get_keyboard_state(&klawiatura);
            //wychodzenie z petli gry
            if ( al_key_down(&klawiatura, ALLEGRO_KEY_Q ))
            {
                gra=0;
            }
            if ( al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT ))
            {
                skierowany = 1;
                if(x <= 350)
                    x ++;
                xKafelka++;
                xNiebo++;
            }

            if ( al_key_down(&klawiatura, ALLEGRO_KEY_LEFT  ) && x >= 0)
            {
                skierowany = 0;
                x --;
                xKafelka--;
                xNiebo--;
            }

            if ( al_key_down(&klawiatura, ALLEGRO_KEY_SPACE ) && jump == 0)
                jump = 80;

            //zdarzenia gracza
           /* if (sqrt(((xNPC-x)^2+(yNPC-y)^2))<=105)
            {
                gra=0;
            }
*/
           int distans = sqrt( ((x  - xNPC)*(x  - xNPC)) + ((y  - yNPC)*(y  - yNPC)) );
            if (distans <=60)
            {
                x=350;
                xNPC=800;
                gra=0;
            }

            //skok
            if(jump > 0 && jumpLong == 3)
            {
                if (jump > 40)
                    y-=5;
                else
                    y+=5;
                jump--;
                jumpLong = 0;
            }
            else if (jump > 0)
                jumpLong++;

            //czyszczenie ekranu
            al_clear_to_color(podstawowyKolor);

            //rysowanie nieba
            if(x == 351)
            {
                for(i=-1;i<2; i++)
                {
                    if(xNiebo >= 0)
                        xNiebo = -1*al_get_bitmap_width(tlo);
                    al_draw_bitmap(tlo,al_get_bitmap_width(tlo)*i -xNiebo,0,0);
                    statyczneNiebo = xNiebo;
                }
            }
            else
            {
                for(i=-1;i<2; i++)
                {
                    al_draw_bitmap(tlo,al_get_bitmap_width(tlo)*i - statyczneNiebo,0,0);
                }
            }

            //rysowanie gracza
            if(skierowany == 1)
                al_draw_bitmap(gracz,x,y,0);
            else
                al_draw_bitmap(gracz,x,y,ALLEGRO_FLIP_HORIZONTAL);
            //ruch NPC
            xNPC-=4;
            if(xNPC==0) xNPC=800;
            czestotliwoscObrotu++;
            if (czestotliwoscObrotu==5)
            {
                czestotliwoscObrotu=0;
                obrot-=2;
                if (obrot<0) obrot=360;
            }
            //rysowanie œwini


                al_draw_rotated_bitmap(swinia,30,30, xNPC, yNPC, obrot, 0);


            //rysowanie podlogi
            if(x == 351)
            {
                for(i=-1;i<2; i++)
                {
                    if(xKafelka >= 0)
                        xKafelka = -465;

                    al_draw_bitmap(kafelek,al_get_bitmap_width(kafelek)*i -xKafelka,352,0);
                    statycznaKafelka = xKafelka;
                }
            }
            else
            {
                for(i=-1;i<2; i++)
                {
                    al_draw_bitmap(kafelek,al_get_bitmap_width(kafelek)*i -statycznaKafelka,352,0);
                }
            }



            al_flip_display();

            //opoznienie petli - timer
            al_rest(0.005);
        }

    }
    //zwalnianie pamieci
    al_destroy_bitmap(gracz);
    al_destroy_bitmap(tlo);
    al_destroy_bitmap(kafelek);
    al_destroy_bitmap(menu);
    al_destroy_bitmap(nowagra);
    al_destroy_bitmap(wyjscie);
    al_destroy_bitmap(swinia);
    al_destroy_sample(sample);
    al_destroy_display(okno);
   return 0;
}


