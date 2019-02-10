#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funkcje.h"

void zbudujplansze(GtkGrid *grid,GtkWidget *window)
{
    for(int i = 1; i<=9; i++)
    {
        for(int j = 1; j<=9; j++)
        {
            GtkWidget *image = gtk_image_new_from_file("0tlo2.png");
            GtkWidget *button = gtk_button_new();
            gtk_button_set_image(GTK_BUTTON(button),image);
            gtk_grid_attach(GTK_GRID(grid),button,i,j,1,1);

            //tr *nn;
            struct tr *nn=malloc(sizeof(struct tr));
            nn->a = i;
            nn->b = j;
            nn->gridd = grid;
            nn->windowek = window;
            g_signal_connect(GTK_BUTTON(button),"clicked",G_CALLBACK(ready),nn);//////////////////////////////////////////////////

        }
    }
    GtkWidget *buttonek = gtk_button_new_with_label(" New\nGame");
    gtk_grid_attach(GTK_GRID(grid),buttonek,1,0,1,1);
    struct okn *pr = malloc(sizeof(struct okn));
    pr->windoww = window;
    pr->menuwindoww = NULL;
    g_signal_connect(GTK_BUTTON(buttonek),"clicked",G_CALLBACK(restart),pr);
        //kolejne elementy planszy
    GtkWidget *punkty = gtk_label_new("0");
    GtkWidget *score = gtk_label_new("\nYour Score: \n");
    GtkWidget *highbutton = gtk_button_new_with_label("  Top\nScores");
    gtk_grid_attach(GTK_GRID(grid),highbutton,2,0,1,1);
    g_signal_connect(GTK_BUTTON(highbutton),"clicked",G_CALLBACK(pokaz_highscore),NULL);
    gtk_grid_attach(GTK_GRID(grid),score,3,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),punkty,4,0,1,1);
    GtkWidget *balls = gtk_label_new("Next balls:");
    gtk_grid_attach(GTK_GRID(grid),balls,6,0,1,1);
}
