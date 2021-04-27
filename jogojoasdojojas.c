#include <stdio.h>
#include <windows.h>
#include <time.h>
#define INI 2

char mapa [10][10] =
                    {{'*', '_', '_', '_', '_','_', '_', '_', '_', '_'},
                     {'_', '_', '_', '_', '_','P', '_', '_', '_', 'P'},
                     {'_', '_', '_', '_', '_','_', '_', '_', '_', '_'},
                     {'I', '_', 'P', 'P', '_','_', '_', 'P', '_', '_'},
                     {'_', '_', '_', 'P', 'P','_', '_', 'P', '_', '_'},
                     {'_', '_', '_', 'I', '_','_', 'P', '_', '_', '_'},
                     {'_', 'P', '_', '_', '_','_', '_', '_', 'P', '_'},
                     {'_', '_', 'P', 'P', '_','_', '_', '_', '_', '_'},
                     {'P', '_', '_', 'P', '_','P', '_', '_', '_', '_'},
                     {'_', '_', 'B', 'P', '_','P', '_', '_', 'P', '_'}};

struct tPosicao {
    int x,y;
    int sentido;
    int morto;
};
int posx,posy;
struct tPosicao personagem;
struct tPosicao inimigos[INI];
struct tPosicao tiro;
int tTiro = 0;
int inix[INI], iniy[INI];
int morreu = 0;

void gotoxy (int x, int y){
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void moldura (int ci, int cf, int li, int lf){
    int l, c;
    for(c=ci+1;c<=cf-1;c++){
        gotoxy(c,li); printf("%c", 205);
        gotoxy(c,lf); printf("%c", 205);
    }
    for(l=li+1;l<=lf-1;l++){
        gotoxy(ci,l); printf("%c",186);
        gotoxy(cf,l); printf("%c", 186);
    }
    gotoxy(ci,li); printf("%c", 201);
    gotoxy(ci,lf); printf("%c", 200);
    gotoxy(cf,li); printf("%c",187);
    gotoxy(cf,lf); printf("%c",188);
}

void desenhamapa(){
    int l,c;
    moldura(9,20,9,20);
    for(l=0;l<10;l++){
        for(c=0;c<10;c++){
            gotoxy(10+c,10+l);
            switch(mapa[l][c]){
                case '*': printf("%c",1); break;
                case '_': printf(" "); break;
                case 'P': printf("%c", 177); break;
                default: printf("%c",mapa[l][c]);
            }
        }
    }
}
void movimentaPersonagem(char tecla){
    mapa[posx][posy] = '_';
    if (tecla==97)
        morreu=1;
    if(tecla==80){
        if (mapa[posx+1][posy]=='_'&& posx<4)
            posx++;
    }
    else
        if(tecla==72){
            if(mapa[posx-1][posy]=='_'&&posx>0)
                posx--;
        }
    else
        if(tecla==77){
            if(mapa[posx][posy+1]=='_'&&posy<4)
                posy++;
        }
    else
    if(tecla==75){
        if(mapa[posx][posy-1]=='_'&&posy>0)
            posy--;
    }
    else
        if(tecla=='t'){
        tTiro=1;
        tiro.x=posx+1;
        tiro.y=posy;
        tiro.sentido=2;
        mapa[tiro.x][tiro.y]='-';
        }
    mapa[posx][posy]=='*';

}
void movimentaInimigo(){
    int chute, mortes=0;
    for(int i=0;i<INI;i++){
      if(inimigos[i].morto==0){
        mapa[inimigos[i].x][inimigos[i].y] = '_';
        chute = rand()%4;
        switch(chute){
            case 0: if(inimigos[i].x>0)
                inimigos[i].x--;break;
            case 1: if(inimigos[i].y<9)
                inimigos[i].y++;break;
            case 2: if (inimigos[i].x<9)
                inimigos[i].x++;break;
            case 3: if(inimigos[i].y>0)
                inimigos[i].y--;break;
        }
        mapa[inimigos[i].x][inimigos[i].y] = 'I';
      }
      else
        mortes++;
    }
    if(mortes==INI)
        printf("morreu tudo!");
}
void movimentaTiro(){
    mapa[tiro.x][tiro.y]='_';
    switch(tiro.sentido){
        case 0: if(tiro.x > 0)
            tiro.x--;break;
        case 1: tiro.y++;break;
        case 2: if(tiro.x<9)
            tiro.x++;
            else{
                tTiro=0;
            }
            break;
        case 3: tiro.y--;break;
    }
    if (mapa[tiro.x][tiro.y] == 'I'){
        for(int i=0;i<INI;i++){
            if(inimigos[i].x==tiro.x && inimigos[i].y==tiro.y){
                printf("inimigo morto!");
                tTiro=0;
                mapa[tiro.x][tiro.y]='_';
                inimigos[i].morto=1;
            }
        }
    }
    else
    if(mapa[tiro.x][tiro.y]=='*'){
        printf("faleceu!");
        morreu=1;
    }
    if(tTiro==1)
        mapa[tiro.x][tiro.y]='-';

}

main(){
    int l,c, chute;
    int retarda=0;
    int retardaTiro =0;
    char tecla;
    srand(time(NULL));
    posx=posy=0;
    inimigos[0].x=2;
    inimigos[0].y=2;
    inimigos[0].morto=0;
    inimigos[1].morto=0;
    inimigos[1].x=1;
    inimigos[1].y=4;
    do{
        desenhamapa();
        if(kbhit()){
            tecla=getch();
            movimentaPersonagem(tecla);
        }
        else
            Sleep(500);
    if(retarda%100==0){
        movimentaInimigo();
        retarda=0;
    }
        retarda++;

    if(tTiro==1){
        if(retardaTiro%50==0){
            movimentaTiro();
            retardaTiro=0;
        }
        retardaTiro++;
    }

    }while(tecla != 27 && morreu ==0);

    }




