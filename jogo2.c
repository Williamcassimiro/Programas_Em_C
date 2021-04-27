#include <stdio.h>
#include <windows.h>
#include <time.h>

char mapa [10][10]={{'*', 'P', '_', '_', 'I','_', '_', '_', '_','_'},
                   {'_', 'P', '_', '_', '_','_', '_', '_', '_', '_'},
                   {'_', '_', 'I', '_', '_','_', '_', '_', '_', '_'},
                   {'_', 'P', 'P', 'P', '_','_', '_', '_', '_', '_'},
                   {'_', 'P', '_', 'P', '_','_', '_', '_', '_', '_'},
                   {'_', 'P', '_', '_', '_','_', 'P', '_', '_', '_'},
                   {'_', '_', '_', '_', '_','_', 'P', '_', '_', '_'},
                   {'_', 'P', 'P', 'P', '_','_', '_', '_', '_', '_'},
                   {'_', 'P', 'B', 'P', '_','_', '_', '_', '_', '_'},
                   {'_', 'P', '_', '_', '_','_', 'P', '_', '_', '_'}};
struct tPosicao {
    int x,y;
};
int posx,posy;
struct tPosicao personagem;
struct tPosicao inimigos[INI];
int inix[INI], iniy[INI];

void gotoxy (int x, int y){
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void moldura (int ci, int cf){
    int l, c;
    for(c=ci+1;c<=cf-1;c++){
        gotoxy(c,14); printf("%c", 205);
        gotoxy(c,25); printf("%c", 205);
    }
    for(l=14;l<=25;l++){
        gotoxy(ci,l); printf("%c",186);
        gotoxy(cf,l); printf("%c", 186);
    }
    gotoxy(ci,14); printf("%c", 201);
    gotoxy(ci,25); printf("%c", 200);
    gotoxy(cf,14); printf("%c",187);
    gotoxy(cf,25); printf("%c",188);
}

void desenhamapa(){
    int l,c;
    moldura(14,25);
    for(l=0;l<10;l++){
        for(c=0;c<10;c++){
            gotoxy(15+c,15+l);
            switch(mapa[l][c]){
                case '*': printf("%c",1); break;
                case '_': printf(" "); break;
                case 'P': printf("%c", 177); break;
                default: printf("%c",mapa[l][c]);
            }
        }
    }
}
void movimentaInimigo(){
    int chute;
    for(int i=0;i<INI;i++){
        mapa[inimigos[i].x][inimigos[i].y] = '_';
        chute = rand()%4;
        switch(chute){
            case 0: inimigos[i].x--;break;
            case 1: inimigos[i].y++;break;
            case 2: inimigos[i].x++;break;
            case 3: inimigos[i].y--;break;
        }
        mapa[inimigos[i].x][inimigos[i].y] = 'I';
    }
}

main(){
    int l,c, chute;
    char tecla;
    srand(time(NULL));
    posx=posy=0;
    inix =2;
    iniy=2;
    do{
        //gotoxy(1,1);
        desenhamapa();
        tecla=getch();
        //printf("[%d]", tecla);
        mapa[posx][posy]='_';
        if (tecla==80){
            if(mapa[posx+1][posy]=='_'&& posx<9)
                posx++;
        }
        else
        if(tecla==72){
            if(mapa[posx-1][posy]=='_'&&posx>0)
                posx--;
        }
        else
        if(tecla==77){
            if(mapa[posx][posy+1]=='_'&&posy<9)
                posy++;
        }
        else
        if(tecla==75){
            if(mapa[posx][posy-1]=='_'&&posy>0)
                posy--;
        }
        mapa[posx][posy] = '*';
//fim da movimentacao do personagem;

    //mapa[inix][iniy]='_';
    //chute= rand()%4;
    //switch(chute){
      //  case 0: inix--;break;
        //case 1: iniy++;break;
        //case 2: inix++;break;
        //case 3: iniy--;break;
    }
    //mapa[inix][iniy] = 'I';



    while(tecla != 27);
    }



