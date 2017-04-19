#ifndef GRACZ_H
#define GRACZ_H
extern int i,n,x, y, xKafelka, statycznaKafelka, xNiebo, statyczneNiebo,xNPC,yNPC,obrot,czestotliwoscObrotu,jump,jumpLong,gra,skierowany,dystans;
extern ALLEGRO_KEYBOARD_STATE klawiatura;
extern ALLEGRO_COLOR podstawowyKolor;
extern ALLEGRO_BITMAP *gracz,*tlo,*kafelek,*swinia;
int graj();
#endif
