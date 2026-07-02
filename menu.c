//
// Created by bmsff on 4/15/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sudoku.h"

void choiceMainMenu(){
    int choice=0;
    printMainMenu();
    while (1){
        printf("\noption: ");
        scanf("%d",&choice);
        if (choice>=0 && choice<=3) break;
    }
    switch (choice) {
        case 1:
            printf("LOAD GAME\n"); break;
        case 2:
            printf("NEW GAME\n");newGameMain(); break;
        case 3:
            printf("SETTINGS MENU\n");break;
        case 4:
        printCredits();break;
        case 0:
            printf("QUIT  Y/N ?\n");break;
        default:
            printf("HOW DID YOU GET HERE ??\n");break;
    }
}

void printMainMenu(){
    printf("##############################################\n");
    printf("#                   C-UDOKU                  #\n");
    printf("##############################################\n");
    printf("# 1)-----LOAD GAME---------------------------#\n");
    printf("# 2)-----NEW GAME----------------------------#\n");
    printf("# 3)-----SETTINGS----------------------------#\n");
    printf("# 3)-----CREDITS-----------------------------#\n");
    printf("##############################################\n");
    printf("# 0)-----QUIT--------------------------------#\n");
    printf("##############################################\n");
}
void printCredits(){
    printf("##############################################\n");
    printf("#                   CREDITS                  #\n");
    printf("##############################################\n");
    printf("#  C-UDOKU was made by \"Bruno Freitas\" as  a  #\n");
    printf("#  school project.                           #\n");
    printf("#                                            #\n");
    printf("#  Some ideas were taken from other sources  #\n");
    printf("#  but ALL THE CODE WAS MADE BY ME.          #\n");
    printf("##############################################\n");
}
void printSettings(){
    char spaces;
    printf("##############################################\n");
    printf("#                  SETTINGS                  #\n");
    printf("##############################################\n");
    printf("#  Game size (N x N): %c  #\n");
    printf("#  school project.                           #\n");
    printf("#                                            #\n");
    printf("#  Some ideas were taken from other sources  #\n");
    printf("#  but ALL THE CODE WAS MADE BY ME.          #\n");
    printf("##############################################\n");
}