#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
struct okn
{
    GtkWidget *windoww;
    GtkWidget *menuwindoww;
};
struct tr
{
    int a;
    int b;
    GtkGrid *gridd;
    GtkWidget *windowek;
};
struct ent
{
    int z;
    int wynik;
    GtkWidget *yent;
    GtkWidget *win;
};
void oknozwyborem(GtkWidget *window);
void zbudujplansze(GtkGrid *grid,GtkWidget *win);
void clean(GtkGrid *grid);
void zamien_kulke_klik(GtkGrid *grid,int i,int j);
void dfs(GtkGrid *grid,int i,int j);
void przenies_kulke(int i,int j,GtkGrid *grid);
void ready(GtkWidget *button,struct tr *nn);
void zamien_kulke(int bal,GtkGrid *grid,int gdzie, int gdzie2);
void kulka_do_buta(GtkGrid *grid,int i,int j,int bal);
void wrzuc_kulke(GtkGrid *grid,int kolor);
void wypisz_kulke(int bal,GtkGrid *grid,int gdzie,int gdzie2,int *tab);
void ustaw_kulki(GtkGrid *grid);
void wylosuj_kulki(GtkGrid *grid,int *tab);
int czyusunac(GtkGrid *grid, int i, int j);
void usunkulki(GtkGrid *grid, int i, int j, int wo);
void trzykulki(GtkGrid *grid, GtkWidget *window);
void shutdown(GtkWidget *przycisk);
void restart(GtkWidget *przyciskrest,struct okn *okn2);
void quit(GtkWidget *windowm,int x);
void highscore(int x);
void pokaz_highscore();
