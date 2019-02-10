#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funkcje.h"

void wylosuj_kulki(GtkGrid *grid,int *tab)
{
    int bal1,bal2,bal3;
    bal1 = rand()%7 +1;
    bal2 = rand()%7 +1;
    bal3 = rand()%7 +1;
    wypisz_kulke(bal1,grid,7,0,(int *)tab);
    wypisz_kulke(bal2,grid,8,0,(int *)tab);
    wypisz_kulke(bal3,grid,9,0,(int *)tab);
}
void wypisz_kulke(int bal,GtkGrid *grid,int gdzie,int gdzie2,int *tab)
{
    GtkWidget *ball;
    if(bal == 1)
    {
        ball = gtk_image_new_from_file("0czerwony.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=1;
    }
    if(bal == 2)
    {
        ball = gtk_image_new_from_file("0zielony.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=2;
    }
    if(bal == 3)
    {
        ball = gtk_image_new_from_file("0bialy.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=3;
    }
    if(bal == 4)
    {
        ball = gtk_image_new_from_file("0fioletowy.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=4;
    }
    if(bal == 5)
    {
        ball = gtk_image_new_from_file("0niebieski.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=5;
    }
    if(bal == 6)
    {
        ball = gtk_image_new_from_file("0czarny.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=6;
    }
    if(bal == 7)
    {
        ball = gtk_image_new_from_file("0pomaranczowy.png");
        gtk_grid_attach(grid,ball,gdzie,gdzie2,1,1);
        *(tab+gdzie)=7;
    }
    return;
}
