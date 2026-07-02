//
// Created by bmsff on 4/15/2021.
//

#ifndef SUDOKUISH_SUDOKU_H
#define SUDOKUISH_SUDOKU_H

typedef struct{
    char **game;
    int SIZE;
    int SYMB;
    char EMPTY;
}config;


void mainFunc();

void newGameMain();
void loadGameMain();
void saveGameMain();
config readSavedOptions();
void writeSavedOptions();
config alocateGameSpace(int size,char empty,int symbol);
void freeGameSpace(config c);
void clearGame(config c );
void printMatrix();
int convertCords(char a);
void showTile(config c,int x,int y);
void changeVallue(config c,int x,int y,int v);
int checkX(config c,int ,int v,int check);
int checkY(config c,int y,int v,int check);
int checkGrid(config c,int y,int v,int check);
void checkGameInput(config c,int x, int y,int v,int check);
void randFill(config c);
void readLocked(config c);
int win(config c);
int lengthOfNumber(int size);//returns the length of a int
void printIntWithCorrectNumberofSpaces(int size,int caracter);
void printCharWithCorrectNumberofSpaces(int size,int caracter);

#endif //SUDOKUISH_SUDOKU_H
