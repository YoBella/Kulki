#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funkcje.h"
static int tab[15][15];
static int vis[15][15];
static int can[15][15];
static int aktx,akty;
static int check;
static int wart = 0;

void clean(GtkGrid *grid)
{

    GtkWidget *stand;
    GtkWidget *guzik;
    for(int i = 1; i<=9; i++)
    {
        for(int j = 1; j<=9; j++)
        {
            int jaki = tab[i][j];
            //printf("%d ",jaki);
            guzik = gtk_grid_get_child_at(GTK_GRID(grid),i,j);
            if(jaki == 0)
            {
                stand = gtk_image_new_from_file("0tlo2.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 1)
            {
                stand = gtk_image_new_from_file("0czerwonytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 2)
            {
                stand = gtk_image_new_from_file("0zielonytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 3)
            {
                stand = gtk_image_new_from_file("0bialytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 4)
            {
                stand = gtk_image_new_from_file("0fioletowytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 5)
            {
                stand = gtk_image_new_from_file("0niebieskitlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 6)
            {
                stand = gtk_image_new_from_file("0czarnytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
            if(jaki == 7)
            {
                stand = gtk_image_new_from_file("0pomaranczowytlo.png");
                gtk_button_set_image(GTK_BUTTON(guzik),stand);
            }
        }
    }
    for(int z = 1; z<=9; z++)
    {
        for(int x = 1; x<=9; x++)
        {
            vis[z][x]=0;
            can[z][x]=0;
        }
    }
}
void zamien_kulke_klik(GtkGrid *grid,int i,int j)
{
    GtkWidget *klik = gtk_grid_get_child_at(GTK_GRID(grid),i,j);
    GtkWidget *kik;
    int jaki = tab[i][j];
    printf("%d\n",jaki);
    if(jaki == 1)//czerwony
    {
        kik = gtk_image_new_from_file("0czerwonytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 2)//zielony
    {
        kik = gtk_image_new_from_file("0zielonytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 3)//bialy
    {
        kik = gtk_image_new_from_file("0bialytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 4)//fioletowy
    {
        kik = gtk_image_new_from_file("0fioletowytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 5)//niebieski
    {
        kik = gtk_image_new_from_file("0niebieskitloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 6)//czarny
    {
        kik = gtk_image_new_from_file("0czarnytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
    if(jaki == 7)//pomarañczowy
    {
        kik = gtk_image_new_from_file("0pomaranczowytloklik.png");
        gtk_button_set_image(GTK_BUTTON(klik),kik);
    }
}
void dfs(GtkGrid *grid,int i,int j)
{
    vis[i][j]=1;//widoczny
    int tp1[5] = {-1,0,0,1};
    int tp2[5] = {0,-1,1,0};
    for(int z = 0; z<4; z++)//w ka¿d¹ strone
    {
        int k,l;
        k = i + tp1[z];
        l = j + tp2[z];
        if(k>0 && l >0 && k<10 && l<10)//jezeli nie jest poza tablic¹
        {
            if(tab[k][l]==0 && vis[k][l]==0)//jezeli nie ma tu kulki i jest nieodwiedzony
            {
                GtkWidget *pole = gtk_grid_get_child_at(GTK_GRID(grid),k,l);
                GtkWidget *zolty = gtk_image_new_from_file("0tlo2klik.png");
                gtk_button_set_image(GTK_BUTTON(pole),zolty);
                can[k][l]=1;
                dfs(GTK_GRID(grid),k,l);
            }
        }

    }
}
void przenies_kulke(int i,int j,GtkGrid *grid)
{
    GtkWidget *old = gtk_grid_get_child_at(GTK_GRID(grid),aktx,akty);
    GtkWidget *neww = gtk_grid_get_child_at(GTK_GRID(grid),i,j);
    GtkWidget *backg = gtk_image_new_from_file("0tlo2.png");
    GtkWidget *im;
    if(tab[aktx][akty]==1)
    {
        tab[i][j]=1;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0czerwonytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==2)
    {
        tab[i][j]=2;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0zielonytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==3)
    {
        tab[i][j]=3;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0bialytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==4)
    {
        tab[i][j]=4;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0fioletowytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==5)
    {
        tab[i][j]=5;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0niebieskitlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==6)
    {
        tab[i][j]=6;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0czarnytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
    if(tab[aktx][akty]==7)
    {
        tab[i][j]=7;
        tab[aktx][akty]=0;
        im = gtk_image_new_from_file("0pomaranczowytlo.png");
        gtk_button_set_image(GTK_BUTTON(old),backg);
        gtk_button_set_image(GTK_BUTTON(neww),im);
    }
}
int czyusunac(GtkGrid *grid, int x, int y)
{
    int ile = 0;
    int t = tab[x][y];
    int i = x;
    int j = y;
    //Z LEWEJ W DÓŁ PO SKOSIE
    while(tab[i][j]==t)
    {
        i--;
        j--;
        ile++;
    }
    i = x+1;
    j = y+1;
    while(tab[i][j]==t)
    {
        i++;
        j++;
        ile++;
    }
    if(ile>=5)
    {
        return 1;
    }
    //Z LEWEJ DO GÓRY PO SKOSIE
    ile = 0;
    i = x;
    j = y;
    while(tab[i][j]==t)
    {
        i++;
        j--;
        ile++;
    }
    i = x-1;
    j = y+1;
    while(tab[i][j]==t)
    {
        i--;
        j++;
        ile++;
    }
    if(ile>=5)
    {
        return 2;
    }
    //POZIOMO
    ile = 0;
    i = x;
    j = y;
    while(tab[i][j]==t)
    {
        i--;
        ile++;
    }
    i = x+1;
    j = y;
    while(tab[i][j]==t)
    {
        i++;
        ile++;
    }
    if(ile>=5)
    {
        return 3;
    }
    //PIONOWO
    ile = 0;
    i = x;
    j = y;
    while(tab[i][j]==t)
    {
        j--;
        ile++;
    }
    i = x;
    j = y+1;
    while(tab[i][j]==t)
    {
        j++;
        ile++;
    }
    if(ile>=5)
    {
        return 4;
    }
    return 0;
}
void dodaj_punkt(GtkGrid *grid,int buff)
{
    GtkWidget *punkt = gtk_grid_get_child_at(GTK_GRID(grid),4,0);
    wart++;
    wart = wart + buff;
    char sl2[256];
    itoa(wart,sl2,10);
    printf("MOJA LICZBA: %d\n\n\n\n",wart);
    const gchar *sl3 = sl2;
    gtk_label_set_text(GTK_LABEL(punkt),sl3);
}
void usun_kulke(GtkGrid *grid, int x, int y,int buff)
{
    printf("Usuwam: %d %d\n",x,y);
    printf("tablica??? : %d",tab[x][y]);
    tab[x][y] = 0;
    check--;
    GtkWidget *dous = gtk_grid_get_child_at(GTK_GRID(grid),x,y);
    GtkWidget *backg = gtk_image_new_from_file("0tlo2.png");
    gtk_button_set_image(GTK_BUTTON(dous),backg);
    dodaj_punkt(GTK_GRID(grid),buff);
}
void usunkulki(GtkGrid *grid, int x, int y, int wo)
{
    int t = tab[x][y];
    int i = x;
    int j = y;
    int ile = 0;
    int buff = 0;
    if(wo == 1)//SKOS Z LEWEJ W DÓŁ
    {
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i--;
            j--;
        }
        i = x+1;
        j = y+1;
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i++;
            j++;
        }
    }
    if(wo == 2)//SKOS Z LEWWJ W GÓRE
    {
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i++;
            j--;
        }
        i = x-1;
        j = y+1;
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i--;
            j++;
        }
    }
    if(wo == 3)//POZIOMO
    {
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i--;
        }
        i = x+1;
        j = y;
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            i++;
        }
    }
    if(wo == 4)//PIONOWO
    {
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            j--;
        }
        i = x;
        j = y+1;
        while(tab[i][j]==t && i>0 && i<10 && j<10 && j>0)
        {
            ile++;
            if(ile>5)
                buff = buff +5;
            usun_kulke(GTK_GRID(grid),i,j,buff);
            j++;
        }
    }
}
void trzykulki(GtkGrid *grid,GtkWidget *window)
{
    int wyk = 0;
    int kolor1 = tab[0][7];
    int kolor2 = tab[0][8];
    int kolor3 = tab[0][9];
    if(check<81)
    {
        wrzuc_kulke(GTK_GRID(grid),kolor1);
        check++;
    }
    else if(wyk == 0)
    {
        wyk = 1;
        quit(window,wart);
    }
    if(check<81)
    {
        wrzuc_kulke(GTK_GRID(grid),kolor2);
        check++;
    }
    else if(wyk == 0)
    {
        wyk = 1;
        quit(window,wart);
    }
    if(check<81)
    {
        wrzuc_kulke(GTK_GRID(grid),kolor3);
        check++;
    }
    else if(wyk == 0)
    {
        wyk = 1;
        quit(window,wart);
    }
    ustaw_kulki(GTK_GRID(grid));
    if(check == 81 && wyk == 0)
    {
        quit(window,wart);
    }
    if(check>=81)
    {
        gtk_main_quit();
    }
}
void ready(GtkWidget *button,struct tr *nn)
{
    int i = nn->a;
    int j = nn->b;
    GtkGrid *grid = nn->gridd;
    GtkWidget *window = nn->windowek;
    if(tab[i][j]==0)
    {
        if(can[i][j]==1)
        {
            printf("%d %d\n",aktx,akty);
            przenies_kulke(i,j,GTK_GRID(grid));
            int xp = czyusunac(GTK_GRID(grid),i,j);
            if(xp > 0)
            {
                printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
                usunkulki(GTK_GRID(grid),i,j,xp);
            }
            else
            {
                trzykulki(GTK_GRID(grid),window);
            }
        }
        clean(GTK_GRID(grid));
    }
    else
    {
        clean(GTK_GRID(grid));
        zamien_kulke_klik(GTK_GRID(grid),i,j);//NA POMARAÑCZOWY
        dfs(GTK_GRID(grid),i,j);
        aktx=i;
        akty=j;
    }
}
void zamien_kulke(int bal,GtkGrid *grid,int gdzie, int gdzie2)
{
    GtkWidget *kulk = gtk_grid_get_child_at(GTK_GRID(grid),gdzie,gdzie2);
    if(bal == 1)
    {
        tab[gdzie][gdzie2]=1;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0czerwony.png");
    }
    if(bal == 2)
    {
        tab[gdzie][gdzie2]=2;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0zielony.png");
    }
    if(bal == 3)
    {
        tab[gdzie][gdzie2]=3;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0bialy.png");
    }
    if(bal == 4)
    {
        tab[gdzie][gdzie2]=4;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0fioletowy.png");
    }
    if(bal == 5)
    {
        tab[gdzie][gdzie2]=5;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0niebieski.png");
    }
    if(bal == 6)
    {
        tab[gdzie][gdzie2]=6;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0czarny.png");
    }
    if(bal == 7)
    {
        tab[gdzie][gdzie2]=7;
        gtk_image_set_from_file(GTK_IMAGE(kulk),"0pomaranczowy.png");
    }
}
void kulka_do_buta(GtkGrid *grid,int i,int j,int bal)
{
    GtkWidget *imgbut = gtk_grid_get_child_at(GTK_GRID(grid),i,j);
    GtkWidget *kk;
    if(bal == 1)
    {
        kk = gtk_image_new_from_file("0czerwonytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 2)
    {
        kk = gtk_image_new_from_file("0zielonytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 3)
    {
        kk = gtk_image_new_from_file("0bialytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 4)
    {
        kk = gtk_image_new_from_file("0fioletowytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 5)
    {
        kk = gtk_image_new_from_file("0niebieskitlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 6)
    {
        kk = gtk_image_new_from_file("0czarnytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
    if(bal == 7)
    {
        kk = gtk_image_new_from_file("0pomaranczowytlo.png");
        gtk_button_set_image(GTK_BUTTON(imgbut),kk);
        int xp = czyusunac(GTK_GRID(grid),i,j);
        if(xp > 0)
        {
            printf("\n\nUsuwamy kulki tak: %d\n\n",xp);
            usunkulki(GTK_GRID(grid),i,j,xp);
        }
    }
}
void wrzuc_kulke(GtkGrid *grid, int kolor)
{
    int i = rand()%10;
    int j = rand()%10;
    while(tab[i][j] != 0 || i == 0 || j == 0)
    {
        i = rand()%10;
        j = rand()%10;
    }
    tab[i][j]=kolor;
    kulka_do_buta(GTK_GRID(grid),i,j,kolor);
}
void ustaw_kulki(GtkGrid *grid)
{
    int bal1,bal2,bal3;
    bal1 = rand()%7+1;
    bal2 = rand()%7+1;
    bal3 = rand()%7+1;
    zamien_kulke(bal1,grid,7,0);
    tab[0][7]=bal1;
    zamien_kulke(bal2,grid,8,0);
    tab[0][8]=bal2;
    zamien_kulke(bal3,grid,9,0);
    tab[0][9]=bal3;
}
void restart(GtkWidget *przycisk2, struct okn *okn2)
{
    GtkWidget *win = okn2->windoww;
    GtkWidget *win2 = okn2->menuwindoww;
    wart = 0;
    check = 0;
    for(int z = 1; z<=9; z++)
    {
        for(int x = 1; x<=9; x++)
        {
            vis[z][x]=0;
            can[z][x]=0;
            tab[z][x]=0;
        }
    }
    gtk_widget_destroy(win);
    if(win2 != NULL)
        gtk_widget_destroy(win2);
    gtk_main_quit();
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Kulki");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
    GtkWidget *grid = gtk_grid_new();
    zbudujplansze(GTK_GRID(grid),window);
    clean(GTK_GRID(grid));
    gtk_container_add(GTK_CONTAINER(window),grid);
    wylosuj_kulki(GTK_GRID(grid),(int*)tab);
    for(int i = 1; i<=5; i++)
    {
        int kolor = rand()%7;
        kolor++;
        wrzuc_kulke(GTK_GRID(grid),kolor);
        check++;
    }
    gtk_widget_show_all(window);
    gtk_main();
}
int main(int argc,char *argv[])
{
    //inicjacja
    gtk_init(&argc, &argv);
    srand(time(NULL));
    //okno
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Kulki");

    //gtk_window_set_default_size(GTK_WINDOW(window),600,500);

    //zbudowanie planszy
    GtkWidget *grid = gtk_grid_new();
    zbudujplansze(GTK_GRID(grid),window);
    gtk_container_add(GTK_CONTAINER(window),grid);
    // TU BY£Y NASTÊPNE ELEMENTY

    //nastêpne kulki
    wylosuj_kulki(GTK_GRID(grid),(int*)tab);

    //dodawanie kulek
    for(int i = 1; i<=5; i++)
    {
        int kolor = rand()%7;
        kolor++;
        wrzuc_kulke(GTK_GRID(grid),kolor);
        check++;
    }
    oknozwyborem(window);
    gtk_main();
    return 0;
}
