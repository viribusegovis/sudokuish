//
// Created by bmsff on 4/15/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menu.h"
#include "sudoku.h"
//inicialização das constantes

void newGameMain(){
    config c = readSavedOptions();
    int sudoku,v;
    clearGame(c);
        randFill(c);
        printMatrix(c);
    char x,y,a;
    while (1){
        printf("Escolha as coordenadas para mudar o numero (Ex.: 4b )\n",c);
        scanf("%d%c",&x,&a);
        printf("%d",x);
        x=x-1; // This is here to fix showTile() 
        y=convertCords(a); 
        if (x<5&&x>=0 && y<5&&y>=0) break;
        printf("\nEntre 1-5\n");
    }

    showTile(c,x,y);
        while (1){
            printf("Escolha o valor para mudar ( De 1 a %d )\n",c.SIZE);
            scanf("%c",&v);
            if (v<c.SIZE&&v>0) break;
        }

        checkGameInput(c,x,y,v,1);
        sudoku=win(c);
    
}

void loadGameMain(){

}

void saveGameMain(){

}

config readSavedOptions(){
    char empty=' ';
    int size=0,symbol=0;
    FILE* fp;
    fp = fopen("options.txt","r");
    if(fp ==NULL){
        printf("VOID");
    }
    fscanf(fp, "%*[^\n]");     // Lê o cabeçalho e ignora-o ( * Qualquer tipo de dados ) ( [^ ] Exceção ) ( \n NewLine )
    fscanf(fp,"%d\t%c\t%d",&size,&empty,&symbol);
    //printf("%d\n%c\n%d",size,empty,symbol);
    fclose(fp);
    return alocateGameSpace(size,empty,symbol);
}

void writeNewOptions(int size,char empty,int symbol){
    //empty: ASCII caracter that represents the free spaces
    //size: Size of the game board (N x N)   
    //symbol: types of Symbols for the game (1- Numbers; 2-Caracters; 3-Weird Caracters ish)
    FILE* fp;
    fp = fopen("options.txt","w");
    if(fp ==NULL)return;
    fprintf (fp, "SIZE\tEMPTY\tTYPEOFSYMBOLS\n"); //Cabeçalho
    fprintf (fp, "%d\t\t%c\t\t%d",size,empty,symbol);
    fclose(fp);

}

config alocateGameSpace(int size,char empty,int symbol){
    config c;
    c.SIZE = size;
    c.EMPTY = empty;
    c.SYMB = symbol;

    c.game = (char **) malloc(c.SIZE * sizeof(char *));
    for (int i = 0; i < c.SIZE; ++i) {
        c.game[i]= (char *) malloc(c.SIZE * sizeof(char));
    }
    return c;
}

void FreeGameSpace(config c){
    for (size_t i = 0; i < c.SIZE; i++){
        free(c.game[i]);
    }
    free(c.game);
}

void printMatrix(config c ){
    int temp2=97;
    for (int i = -1; i < c.SIZE; ++i) {
        if(i+1>9) printf("%d",i+1); else printf("0%d",i+1);
        for (int j = 0; j < c.SIZE; ++j) {
            if (i==(-1)) {
                printCharWithCorrectNumberofSpaces(c.SIZE,temp2);
            }else{
                // printf("Ç%d%dÇ", i,j);
                printIntWithCorrectNumberofSpaces(c.SIZE,c.game[i][j]);

            }
            temp2++;
        }
        printf("|\n");

    }

}
void clearGame(config c ){
    for (int i = 0; i < c.SIZE; ++i) {
        for (int j = 0; j < c.SIZE; ++j) {
            c.game[i][j] =0;
        }
    }

}
int convertCords(char a){
    switch (a) {
        case 'a':return 0;
        case 'b':return 1;
        case 'c':return 2;
        case 'd':return 3;
        default :return -1;
    }
}

void showTile(config c,int x, int y){
    int temp1=48,temp2=97;
    printf("\n");
    for (int i = -1; i < c.SIZE; ++i) {
        if(i+1>9) printf("%d",i+1); else printf("0%d",i+1);
        for (int j = 0; j < c.SIZE; ++j) {
            if (i==(-1)) {
                printCharWithCorrectNumberofSpaces(c.SIZE,temp2);
            }else if (i==x && j==y){
                printCharWithCorrectNumberofSpaces(c.SIZE,'#');
            }else{
                printIntWithCorrectNumberofSpaces(c.SIZE,c.game[i][j]);
            }
            temp2++;
        }
        printf("|\n");
        temp1++;
    }
}
void changeVallue(config c,int x,int y,int v){
    for (int i = 0; i < c.SIZE; ++i) {
        for (int j = 0; j < c.SIZE; ++j) {
            if (i==x && j==y){
                c.game[i][j]=v;
            }
        }

    }
}
int checkX(config c,int x,int v,int check){
    for (int j = 0; j < c.SIZE; ++j) {
        if (c.game[x][j] ==v){
            if (check==1){
                printf("\n\n#%d Existe X\n",v);
            }
            return 1;
        }
    }
    return 0;
}
int checkY(config c, int y,int v,int check){
    for (int i = 0; i < c.SIZE; ++i) {
        if (c.game[i][y]==v){
            if (check==1){
                printf("\n\n#%d Existe Y\n",v);
            }
            return 1;
        }
    }
    return 0;
}
int checkGrid(config c, int y,int v,int check){
    int grids = sqrt(c.SIZE);
    for (int l = 0; l < grids; l++) {
        for (int k = 0; k < grids; k++) {
            for (int i = l*grids; i < l* grids +grids; ++i) {
                for (int j = k*grids; j < k* grids +grids; ++j) {
                    if (c.game[i][j]==v){
                        return 1;
                    }
                }
            }
        }

    }
    return 0;
}
void checkGameInput(config c,int x, int y,int v,int check){
    if (checkX(c,x,v,check) == 1 || checkY(c,y,v,check)==1 || checkGrid(c,y,v,check)==1){
    }else{
        changeVallue(c,x,y,v);
    }
}
void randFill(config c){
    int v;
    for (int i = 0; i < c.SIZE; ++i) {
        for (int j = 0; j < c.SIZE; ++j) {
            v=(rand())%c.SIZE+1;
            checkGameInput(c,i,j,v,0);
        }
    }
}
void checkLocked(config c,int x, int y,int v){

}
void readLocked(config c){
    for (int i = 0; i < c.SIZE; ++i) {
        for (int j = 0; j < c.SIZE; ++j) {
            if (c.game[i][j]==0){
            }
        }
    }
}
int win(config c){
    for (int i = 0; i < c.SIZE; ++i) {
        for (int j = 0; j < c.SIZE; ++j) {
            if (c.game[i][j]==0){
                return 0;
            }
        }
    }
    printf("WIIIIIN");
}
int lengthOfNumber(int size){ //returns the length of a int
    int k=1,out;
    while (size >=10){
        k++;
        size = size/10;
        if (k>20)break;
    } 
    return k;
}
void printIntWithCorrectNumberofSpaces(int size,int caracter){ //returns the length of a int
    int sides=2; //Sides = 2 because we need to divide the spaces equaly
    int spaces= ceil(lengthOfNumber(size)/sides);
    printf("|  ");

    for (int k = 0; k < spaces; k++){
       printf(" ");
    }
    if(caracter>9) printf("%d",caracter); else printf("0%d",caracter);

    for (int k = 0; k < spaces; k++){
       printf(" ");
    }
     printf("  ");

}
void printCharWithCorrectNumberofSpaces(int size,int caracter){ //returns the length of a int
    char parse=caracter;
    int sides=2; //Sides = 2 because we need to divide the spaces equaly
    int spaces= ceil(lengthOfNumber(size)/sides);
    printf("|  ");

    for (int k = 0; k < spaces; k++){
       printf(" ");
    }
    printf("%c%c", caracter,caracter);

    for (int k = 0; k < spaces; k++){
       printf(" ");
    }
     printf("  ");

}