#include "allegro5/allegro.h"
int xMyszki;
    int yMyszki;
    int przycisk;
    ALLEGRO_MOUSE_STATE mouse_state;
int mysz()
{
    al_get_mouse_state(&mouse_state);
        xMyszki = mouse_state.x;
        yMyszki = mouse_state.y;
        przycisk = mouse_state.buttons;
return 0;
}
