#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
typedef struct{

    char coluna[30];
}metrica;
//MOVIMENTO DO PLAYER USANDO <-(A) ->(D) FUNCIONANDO PERFEITAMENTE
/* ¦          +----------+
              ¦          ¦
              ¦          ¦
              ¦          ¦
              ¦          ¦
              +----------+
              */

void faz_mapa(metrica *mapa);
void menu_logo(void); //menu_logo não está implementada



int main(){
    int coluna=50, linha=1,pedra_linha=10,pedra_coluna=15;
    int i,j,controle =0;
    char ch = 'O';  //caractere do personagem
    char move;
    metrica mapa[30];   
    /*FUNÇÕES DA BIBLIOTECA N_CURSES */
    initscr();                      
    noecho();
    curs_set(FALSE);
    faz_mapa(mapa);

    
    //Main loop do jogo
    while(1){
        clear();
        
        move = getchar();
        
    if(move == 'l')break; //Pressionar tecla "l" para sair do jogo

        //desenha o mapa 30x30
        for(i=0;i<30;i++){
        for(j=0;j<30;j++){
            mvprintw(i,j+30,"%c",mapa[i].coluna[j]);
        }
    }
    //Movimentos do char
    if(move == 'd'){
        if(coluna >= 58){
        mvprintw(linha,coluna,"%c",ch);
    }else{
        

        if(linha == pedra_linha && coluna+1 == pedra_coluna){
            //COLISAO COM A PAREDE
            if(pedra_coluna >=58){
                mvprintw(pedra_linha,pedra_coluna,"@");
                mvprintw(linha,coluna,"%c",ch);
            }
            else{
                mvprintw(linha,++coluna,"%c",ch);
                mvprintw(pedra_linha,++pedra_coluna,"@");
            }
            //
        }
        else{
            mvprintw(linha,++coluna,"%c",ch);
        }
     }
    controle++;
    

    }
    else if(move == 'a'){
        mvprintw(linha,--coluna,"%c",ch);
        controle++;
        if(linha == pedra_linha && coluna == pedra_coluna){
            mvprintw(pedra_linha,--pedra_coluna,"@");
        }
        if(coluna == 0){
            ++coluna;
        }
        
    }
    else if(move == 'w'){
        mvprintw(--linha,coluna,"%c",ch);
        controle++;
        if(linha == pedra_linha && coluna == pedra_coluna){
            mvprintw(--pedra_linha,pedra_coluna,"@");
        }
    }
    else if(move == 's'){
        mvprintw(++linha,coluna,"%c",ch);
        controle++;
        if(linha == pedra_linha && coluna == pedra_coluna){
            mvprintw(++pedra_linha,pedra_coluna,"@");
        }
    }
    //mostrador dos passos do personagem
    mvprintw(35,35,"CONTROLE DO JUEGO: %d",controle);

    //Objeto(pedra) no mapa
    mvprintw(pedra_linha,pedra_coluna,"@");
    refresh();
    }
    getch();
    endwin();
}
// Cria um Mapa 30/30
void faz_mapa(metrica *mapa){

    int i;
    int j;
    for(i=0;i<30;i++){
        for(j=0;j<30;j++){
            if((i == 0 && (j==0|| j==29)) ||(i == 29 && (j==0 || j==29))){
                mapa[i].coluna[j]= '+';
            }
            else if(i == 0 || i == 29){
                mapa[i].coluna[j] = '-';
            }
            else if((j==0 && i >0)){
                mapa[i].coluna[j] = 'b';
            }
            else if((j==29 && i>0)){
                mapa[i].coluna[j] = 'a';
            }
            else{
                mapa[i].coluna[j]= ' ';
            }
        }
    }

}
//função não implementada !!! Função nao funciona!!!
void menu_logo(void){
   /*
    FILE *mapa = NULL;
    int j=0,i=0;
    char matriz[1000][1000];
    mapa = fopen("logo.txt","r");
    while((fscanf(mapa,"%c",matriz[i][j]))!=EOF){
        if((fscanf(mapa,"%c",matriz[i][j])) == '\n'){
            i=0;
            j++;
        }
    }
    while(matriz[i][j] !='\0'){
        printf("%c",matriz[i++][j++]);
    }
*/


}