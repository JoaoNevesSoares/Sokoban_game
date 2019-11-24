#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

typedef struct{

    char coluna[100];
    
}posicao;
typedef struct{
    char logo[700];
    char logo1[700];
}menu;

// cabeçalho das funções em C
void desenha_mapa(posicao *linha);
void carrega_mapa(posicao *linha);
int verifica_ganhou(posicao *linha,int *x_pedra,int *y_pedra, menu *end_game);
void desenha_logo(menu *luego);
void end_jogo(menu *end_game);

int main(){

    initscr();                                      // inicia o segundo terminal do ncurses                      
    noecho();                                       // inputs pelo terminal não são mostradas no terminal
    curs_set(FALSE);                                // nao mostra o cursos do terminal
    posicao linha[100];
    menu luego[700];
    menu end_game[700];
    char player = 'P';
    int x_player =5,y_player =5;
    int x_pedra[2]= {3,4};
    int y_pedra[2]={5,5};
    int ganhou;
    char move;
    int i,j;
    carrega_mapa(linha);
    desenha_logo(luego);
    //desenha_mapa(linha);
    //mvprintw(x_player,y_player,"%c",player);
    refresh();
    while(1){

        for(i=0;i<30;i++){
            for(j=0;j<60;j++){
                mvprintw(i,j,"%c",linha[i].coluna[j]);
            }}
        mvprintw(x_pedra[0],y_pedra[0],"@");
        mvprintw(x_pedra[1],y_pedra[1],"@");
        move = getchar();
        if(move == 'l')break;
    switch (move){
        clear();
    case 'd':
        if(linha[x_player].coluna[y_player+1] == '#'){
            mvprintw(x_player,y_player,"%c",player);
            mvprintw(35,40,"estas andando em cima da linha");
        }
        else{
            //mvprintw(x_player,++y_player,"%c",player);
            if(x_player == x_pedra[0] && y_player+1 == y_pedra[0]){
                
                if(linha[x_pedra[0]].coluna[y_pedra[0]+1] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else if(x_pedra[0] == x_pedra[1] && y_pedra[0]+1 == y_pedra[1]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else{
                     mvprintw(x_player,++y_player,"%c",player);
                    mvprintw(x_pedra[0],++y_pedra[0],"@");
                }

                //mvprintw(x_pedra[0],++y_pedra[0],"@");
        }
            else if(x_player == x_pedra[1] && y_player+1 == y_pedra[1]){

                if(linha[x_pedra[1]].coluna[y_pedra[1]+1] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else if(x_pedra[1] == x_pedra[0] && y_pedra[1]+1 == y_pedra[0]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else{
                     mvprintw(x_player,++y_player,"%c",player);
                    mvprintw(x_pedra[1],++y_pedra[1],"@");
                }
             
        }
            else{ 
             mvprintw(x_player,++y_player,"%c",player); }
        }
        


        break;
    case 'a':
        if(linha[x_player].coluna[y_player-1] == '#'){
            mvprintw(x_player,y_player,"%c",player);
            mvprintw(35,40,"estas andando em cima da linha");
        }
        else{
            //mvprintw(x_player,++y_player,"%c",player);
            if(x_player == x_pedra[0] && y_player-1 == y_pedra[0]){
                
                if(linha[x_pedra[0]].coluna[y_pedra[0]-1] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else if(x_pedra[0] == x_pedra[1] && y_pedra[0]-1 == y_pedra[1]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else{
                     mvprintw(x_player,--y_player,"%c",player);
                    mvprintw(x_pedra[0],--y_pedra[0],"@");
                }

                //mvprintw(x_pedra[0],++y_pedra[0],"@");
            }   
            else if(x_player == x_pedra[1] && y_player-1 == y_pedra[1]){

                if(linha[x_pedra[1]].coluna[y_pedra[1]-1] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else if(x_pedra[1] == x_pedra[0] && y_pedra[1]-1 == y_pedra[0]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else{
                     mvprintw(x_player,--y_player,"%c",player);
                    mvprintw(x_pedra[1],--y_pedra[1],"@");
                }
             
            }
            else{ 
             mvprintw(x_player,--y_player,"%c",player); }
            }
        break;
    case 'w':
        if(linha[x_player-1].coluna[y_player] == '#'){
            mvprintw(x_player,y_player,"%c",player);
            mvprintw(35,40,"estas andando em cima da linha");
        }
        else{
            //mvprintw(x_player,++y_player,"%c",player);
            if(x_player-1 == x_pedra[0] && y_player == y_pedra[0]){
                
                if(linha[x_pedra[0]-1].coluna[y_pedra[0]] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else if(x_pedra[0]-1 == x_pedra[1] && y_pedra[0] == y_pedra[1]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else{
                     mvprintw(--x_player,y_player,"%c",player);
                    mvprintw(--x_pedra[0],y_pedra[0],"@");
                }

                //mvprintw(x_pedra[0],++y_pedra[0],"@");
        }
            else if(x_player-1 == x_pedra[1] && y_player == y_pedra[1]){

                if(linha[x_pedra[1]-1].coluna[y_pedra[1]] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else if(x_pedra[1]-1 == x_pedra[0] && y_pedra[1] == y_pedra[0]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else{
                     mvprintw(--x_player,y_player,"%c",player);
                    mvprintw(--x_pedra[1],y_pedra[1],"@");
                }
             
        }
            else{ 
             mvprintw(--x_player,y_player,"%c",player); }
        }
        break;
    case 's':
        if(linha[x_player+1].coluna[y_player] == '#'){
            mvprintw(x_player,y_player,"%c",player);
            mvprintw(35,40,"estas andando em cima da linha");
        }
        else{
            //mvprintw(x_player,++y_player,"%c",player);
            if(x_player+1 == x_pedra[0] && y_player == y_pedra[0]){
                
                if(linha[x_pedra[0]+1].coluna[y_pedra[0]] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else if(x_pedra[0]+1 == x_pedra[1] && y_pedra[0] == y_pedra[1]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[0],y_pedra[0],"@");
                }
                else{
                     mvprintw(++x_player,y_player,"%c",player);
                    mvprintw(++x_pedra[0],y_pedra[0],"@");
                }

                //mvprintw(x_pedra[0],++y_pedra[0],"@");
        }
            else if(x_player+1 == x_pedra[1] && y_player == y_pedra[1]){

                if(linha[x_pedra[1]+1].coluna[y_pedra[1]] == '#'){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else if(x_pedra[1]+1 == x_pedra[0] && y_pedra[1] == y_pedra[0]){
                    mvprintw(x_player,y_player,"%c",player);
                    mvprintw(x_pedra[1],y_pedra[1],"@");
                }
                else{
                     mvprintw(++x_player,y_player,"%c",player);
                    mvprintw(++x_pedra[1],y_pedra[1],"@");
                }
             
        }
            else{ 
             mvprintw(++x_player,y_player,"%c",player); }
        }
        break;
        


    }
    ganhou = verifica_ganhou(linha,x_pedra,y_pedra,end_game);
    if(ganhou == 1)break;
    
    refresh();
    }
    getch();

    endwin();



}
int verifica_ganhou(posicao *linha,int *x_pedra,int *y_pedra, menu *end_game){

    if(linha[x_pedra[0]].coluna[y_pedra[0]] == 'X' && linha[x_pedra[1]].coluna[y_pedra[1]] == 'X' ){
                clear();
                end_jogo(end_game);
                return 1;

    }
    return 0;
}
void carrega_mapa(posicao *linha){
    FILE *arquivos = NULL;
    int i=0,j=0;
    arquivos = fopen("mapa2.txt","r");
    while(fgets(linha[i].coluna, sizeof(linha[i].coluna), arquivos) != NULL){
        i++;
    }
    //while((fscanf(arquivos,"%s",linha[i].coluna))!=EOF){
        i++;
    
}
void desenha_mapa(posicao *linha){
    int i,j;
    for(i=0;i<30;i++){
            for(j=0;j<60;j++){
                mvprintw(i,j,"%c",linha[i].coluna[j]);
            }}
}
void desenha_logo(menu *luego){
    FILE *archi = NULL;
    int i=0,j=0,c=0,d=0;
    archi = fopen("logos.txt","r");
    while(fgets(luego[i].logo, sizeof(luego[i].logo), archi) != NULL){
        i++;
    }
    for(c=0;c<200;c++){
            for(d=0;d<200;d++){
                mvprintw(c,d,"%c",luego[c].logo[d]);
            }}

}
void end_jogo(menu *end_game){
    FILE *archi = NULL;
    int i=0,j=0,c=0,d=0;
    archi = fopen("end_game.txt","r");
    while(fgets(end_game[i].logo1, sizeof(end_game[i].logo1), archi) != NULL){
        i++;
    }
    for(c=0;c<200;c++){
            for(d=0;d<200;d++){
                mvprintw(c,d,"%c",end_game[c].logo1[d]);
            }}

} 