#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funkcje.h"
void uruchom(GtkWidget *startprzycisk,struct okn *xd)
{
    GtkWidget *window = xd->windoww;
    GtkWidget *menuwindow = xd->menuwindoww;
    gtk_widget_destroy(menuwindow);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_resizable(GTK_WINDOW (window), FALSE);
    gtk_window_set_position(GTK_WINDOW (window),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_show_all(window);
}
void shutdown(GtkWidget *wyjdzprzycisk)
{
    gtk_main_quit();
}
void quit(GtkWidget *window,int x)
{
    GtkWidget *gmover = gtk_grid_new();
    GtkWidget *start = gtk_button_new();
    GtkWidget *koniec = gtk_button_new();
    GtkWidget *imageres = gtk_image_new_from_file("start2.png");
    GtkWidget *imagekon = gtk_image_new_from_file("koniec.png");
    gtk_button_set_image(GTK_BUTTON(koniec),imagekon);
    gtk_button_set_image(GTK_BUTTON(start),imageres);
    g_signal_connect(GTK_BUTTON(koniec),"clicked",G_CALLBACK(shutdown),NULL);
    gtk_grid_attach(GTK_GRID(gmover),start,1,1,1,1);
    gtk_grid_attach(GTK_GRID(gmover),koniec,1,2,1,1);
    GtkWidget *gameover = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    struct okn *okn2 = malloc(sizeof(struct okn));
    okn2->windoww = window;
    okn2->menuwindoww = gameover;
    g_signal_connect(GTK_BUTTON(start),"clicked",G_CALLBACK(restart),okn2);
    gtk_container_add(GTK_CONTAINER(gameover),gmover);
    gtk_window_set_title(GTK_WINDOW(gameover),"Koniec gry");
    gtk_window_set_default_size(GTK_WINDOW(gameover),600,240);
    gtk_widget_show_all(gameover);
    highscore(x);
    gtk_main();
}
void instr(GtkWidget *instrukcjeprzycisk)
{
    GtkWidget *instrwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *instrukt = gtk_image_new_from_file("pelnainstrukcja.png");
    gtk_container_add(GTK_CONTAINER(instrwindow),instrukt);
    gtk_widget_show_all(instrwindow);
}
void oknozwyborem(GtkWidget *window)
{
    GtkWidget *menuwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(menuwindow),"Kulki");
    gtk_window_set_position(GTK_WINDOW(menuwindow),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_default_size(GTK_WINDOW(menuwindow),600,360);

    struct okn *xd = malloc(sizeof(struct okn));
    xd->windoww = window;
    xd->menuwindoww = menuwindow;

    GtkWidget *menugrid = gtk_grid_new();
    GtkWidget *startprzycisk = gtk_button_new();
    GtkWidget *zbr = gtk_image_new_from_file("start2.png");
    gtk_button_set_image(GTK_BUTTON(startprzycisk),zbr);
    g_signal_connect(GTK_BUTTON(startprzycisk),"clicked",G_CALLBACK(uruchom),xd);
    GtkWidget *instrukcjeprzycisk = gtk_button_new();
    zbr = gtk_image_new_from_file("instrukcja.png");
    gtk_button_set_image(GTK_BUTTON(instrukcjeprzycisk),zbr);
    g_signal_connect(GTK_BUTTON(instrukcjeprzycisk),"clicked",G_CALLBACK(instr),NULL);
    zbr = gtk_image_new_from_file("koniec.png");
    GtkWidget *wyjdzprzycisk = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(wyjdzprzycisk),zbr);
    g_signal_connect(GTK_BUTTON(wyjdzprzycisk),"clicked",G_CALLBACK(shutdown),NULL);
    gtk_grid_attach(GTK_GRID(menugrid),startprzycisk,1,1,1,1);
    gtk_grid_attach(GTK_GRID(menugrid),instrukcjeprzycisk,1,2,1,1);
    gtk_grid_attach(GTK_GRID(menugrid),wyjdzprzycisk,1,3,1,1);
    gtk_container_add(GTK_CONTAINER(menuwindow),menugrid);
    gtk_widget_show_all(menuwindow);
}
int sprawdz(int x)
{
    FILE *fp;
    int z;
    fp = fopen("wynik1.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 1;
        }
    }
    fclose(fp);
    fp = fopen("wynik2.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 2;
        }
    }
    fclose(fp);
    fp = fopen("wynik3.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 3;
        }
    }
    fclose(fp);
    fp = fopen("wynik4.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 4;
        }
    }
    fclose(fp);
    fp = fopen("wynik5.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 5;
        }
    }
    fclose(fp);
    fp = fopen("wynik6.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 6;
        }
    }
    fclose(fp);
    fp = fopen("wynik7.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 7;
        }
    }
    fclose(fp);
    fp = fopen("wynik8.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 8;
        }
    }
    fclose(fp);
    fp = fopen("wynik9.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 9;
        }
    }
    fclose(fp);
    fp = fopen("wynik10.txt","r+");
    if(fp!= NULL)
    {
        fscanf(fp,"%d",&z);
        if(x>z)
        {
            return 10;
        }
    }
    fclose(fp);
    return 0;
}
void przydziel_wynik(GtkLabel *labell, int j)
{
    FILE *fp;
    if(j == 1)
    {
        fp = fopen("wynik1.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 2)
    {
        fp = fopen("wynik2.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 3)
    {
        fp = fopen("wynik3.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 4)
    {
        fp = fopen("wynik4.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 5)
    {
        fp = fopen("wynik5.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 6)
    {
        fp = fopen("wynik6.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 7)
    {
        fp = fopen("wynik7.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 8)
    {
        fp = fopen("wynik8.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 9)
    {
        fp = fopen("wynik9.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 10)
    {
        fp = fopen("wynik10.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
}
void przydziel_nazwe(GtkLabel *labell, int j)
{
    FILE *fp;
    if(j == 1)
    {
        fp = fopen("nazwa1.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 2)
    {
        fp = fopen("nazwa2.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 3)
    {
        fp = fopen("nazwa3.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 4)
    {
        fp = fopen("nazwa4.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 5)
    {
        fp = fopen("nazwa5.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 6)
    {
        fp = fopen("nazwa6.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 7)
    {
        fp = fopen("nazwa7.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 8)
    {
        fp = fopen("nazwa8.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 9)
    {
        fp = fopen("nazwa9.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
    if(j == 10)
    {
        fp = fopen("nazwa10.txt","r+");
        char x[256];
        while(fscanf(fp,"%s",x) != EOF);
        const gchar *str = x;
        gtk_label_set_text(GTK_LABEL(labell),str);
    }
}
void zmien_numer(GtkGrid *scoregrid,int x)
{
    for(int i = x+1; i<=10; i++)
    {
        GtkWidget *lb = gtk_grid_get_child_at(GTK_GRID(scoregrid),1,i);
        char nw[256];
        itoa(i,nw,10);
        const gchar *zmn = nw;
        gtk_label_set_text(GTK_LABEL(lb),zmn);
    }
}
void zapisz_wynik(GtkGrid *scoregrid,int x, int wyn)
{
    GtkWidget *lwin = gtk_label_new(NULL);
    char xwin[256];
    itoa(wyn,xwin,10);
    const gchar *wynwyn = xwin;
    gtk_label_set_text(GTK_LABEL(lwin),wynwyn);
    gtk_grid_attach(GTK_GRID(scoregrid),lwin,3,x,1,1);
}
void dziala(GtkWidget *yentry,struct ent *ent2)
{
    FILE *fp;
    FILE *fd;
    int x = ent2->z;
    int wyn = ent2->wynik;
    GtkWidget *yenter = ent2->yent;
    GtkWidget *windowsc = ent2->win;
    if(x == 1)
    {
        fp = fopen("nazwa1.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik1.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 2)
    {
        fp = fopen("nazwa2.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik2.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 3)
    {
        fp = fopen("nazwa3.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik3.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 4)
    {
        fp = fopen("nazwa4.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik4.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 5)
    {
        fp = fopen("nazwa5.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik5.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 6)
    {
        fp = fopen("nazwa6.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik6.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 7)
    {
        fp = fopen("nazwa7.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik7.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 8)
    {
        fp = fopen("nazwa8.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik8.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 9)
    {
        fp = fopen("nazwa9.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik9.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    if(x == 10)
    {
        fp = fopen("nazwa10.txt","r+");
        fprintf(fp,"%s\n",gtk_entry_get_text(GTK_ENTRY(yenter)));
        fd = fopen("wynik10.txt","r+");
        fprintf(fd,"%d",wyn);
    }
    gtk_window_close(GTK_WINDOW(windowsc));
}

void wpisz_siebie(GtkGrid *scoregrid,int x,int wyn,GtkWidget *hscore)
{
    GtkWidget *yentry = gtk_entry_new();
    struct ent *hey= malloc(sizeof(struct ent));
    hey->z = x;
    hey->wynik = wyn;
    hey->yent = yentry;
    hey->win = hscore;
    g_signal_connect(GTK_ENTRY(yentry),"activate",G_CALLBACK(dziala),hey);
    gtk_grid_attach(GTK_GRID(scoregrid),yentry,2,x,1,1);
}
void wpisz_dane(GtkWidget *newlab, GtkWidget *newint, int x)
{
    FILE *fp;
    FILE *fd; // char nazwap[100]; sprintf(nazwap,"nazwa%d.txt",x);
    if(x == 10)
    {
        fp = fopen("nazwa10.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik10.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 9)
    {
        fp = fopen("nazwa9.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik9.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 8)
    {
        fp = fopen("nazwa8.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik8.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 7)
    {
        fp = fopen("nazwa7.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik7.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 6)
    {
        fp = fopen("nazwa6.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik6.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 5)
    {
        fp = fopen("nazwa5.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik5.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 4)
    {
        fp = fopen("nazwa4.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik4.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 3)
    {
        fp = fopen("nazwa3.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik3.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
    if(x == 2)
    {
        fp = fopen("nazwa2.txt","r+");
        fprintf(fp,"%s\n",gtk_label_get_text(GTK_LABEL(newlab)));
        fd = fopen("wynik2.txt","r+");
        fprintf(fd,"%s\n",gtk_label_get_text(GTK_LABEL(newint)));
    }
}
void zmien_wszystko(GtkGrid *scoregrid,int x)
{
    for(int i = 10; i>x; i--)
    {
        GtkWidget *newlab = gtk_label_new(NULL);
        GtkWidget *newint = gtk_label_new(NULL);
        przydziel_nazwe(GTK_LABEL(newlab),i-1);
        przydziel_wynik(GTK_LABEL(newint),i-1);
        wpisz_dane(newlab,newint,i);
    }
}
void wpisz(GtkGrid *scoregrid,int x,int wyn,GtkWidget *hscore)
{
    //GtkWidget *entrance = gtk_entry_new();
    printf("MOJE MIEJSCE%d\n",x);
    gtk_grid_insert_row(GTK_GRID(scoregrid),x);
    GtkWidget *lbl = gtk_label_new(NULL);
    char xx[256];
    itoa(x,xx,10);
    const gchar *goth = xx;
    gtk_label_set_text(GTK_LABEL(lbl),goth);
    gtk_grid_attach(GTK_GRID(scoregrid),lbl,1,x,1,1);
    zmien_numer(GTK_GRID(scoregrid),x);
    zapisz_wynik(GTK_GRID(scoregrid),x,wyn);
    zmien_wszystko(GTK_GRID(scoregrid),x);
    wpisz_siebie(GTK_GRID(scoregrid),x,wyn,hscore);
    gtk_grid_remove_row(GTK_GRID(scoregrid),11);
    //gtk_widget_destroy(hscore);
}
void highscore(int x)
{
    GtkWidget *hscore = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(hscore),"HighScore");
    GtkWidget *scoregrid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(scoregrid),TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(scoregrid),TRUE);
    gtk_window_set_default_size(GTK_WINDOW(hscore),400,600);
    int miejsce = sprawdz(x);
    if(miejsce !=0)
    {
        for(int i = 1; i<=3; i++)
        {
            for(int j = 1; j<=10; j++)
            {
                GtkWidget *labell = gtk_label_new(NULL);
                char xh[256];
                itoa(j,xh,10);
                const gchar *xx = xh;
                if(i == 1)
                {
                    gtk_label_set_text(GTK_LABEL(labell),xx);
                }
                if(i == 2)
                {
                    /*GtkWidget *entrry = gtk_entry_new();
                    gtk_entry_set_text(GTK_ENTRY(entrry),"nazwa");
                    gtk_grid_attach(GTK_GRID(scoregrid),entrry,i,j,1,1);*/
                    przydziel_nazwe(GTK_LABEL(labell),j);
                }
                if(i == 3)
                {
                    przydziel_wynik(GTK_LABEL(labell),j);
                }
                gtk_grid_attach(GTK_GRID(scoregrid),labell,i,j,1,1);
            }
        }
    wpisz(GTK_GRID(scoregrid),miejsce,x,hscore);
    gtk_container_add(GTK_CONTAINER(hscore),scoregrid);
    gtk_widget_show_all(hscore);
    }
}
void pokaz_highscore()
{
    GtkWidget *hxscore = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(hxscore),"HighScore");
    GtkWidget *xscoregrid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(xscoregrid),TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(xscoregrid),TRUE);
    gtk_window_set_default_size(GTK_WINDOW(hxscore),400,600);
    for(int i = 1; i<=3; i++)
    {
        for(int j = 1; j<=10; j++)
        {
            GtkWidget *lxabell = gtk_label_new(NULL);
            char xh[256];
            itoa(j,xh,10);
            const gchar *xx = xh;
            if(i == 1)
            {
                gtk_label_set_text(GTK_LABEL(lxabell),xx);
            }
            if(i == 2)
            {
                /*GtkWidget *entrry = gtk_entry_new();
                gtk_entry_set_text(GTK_ENTRY(entrry),"nazwa");
                gtk_grid_attach(GTK_GRID(scoregrid),entrry,i,j,1,1);*/
                przydziel_nazwe(GTK_LABEL(lxabell),j);
            }
            if(i == 3)
            {
                przydziel_wynik(GTK_LABEL(lxabell),j);
            }
            gtk_grid_attach(GTK_GRID(xscoregrid),lxabell,i,j,1,1);
        }
    }
    gtk_container_add(GTK_CONTAINER(hxscore),xscoregrid);
    gtk_widget_show_all(hxscore);
}
