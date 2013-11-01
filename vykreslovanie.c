#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"vykreslenie.h"
#include"game.h"

void user_input(void){
    char c;
    int a[9][9]={(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),};
    int x,y,i,j,z,first_UI_position,second_UI_position,UI_location;
    srand(time(NULL));
    printf("Zadaj natocenie lode, v pre vertikalne, h pre horizontalne:\n");
    scanf("%c", &c);
    
    if(c=='h'){
        printf("Zadaj riadok a stlpec:\n");
        scanf("%d%d", &x,&y);
        if((x>8)||(x<0)||(y<0)||(y>4)){
                printf("Zli vstup. Opakujte prosim");
                system("cls");
                user_input();}
        i=x;
        for(z=y; z<y+5; z++){
            a[i][z]=SHIP_MINE;}}
    else if(c=='v'){
        printf("Zadaj riadok a stlpec:\n");
        scanf("%d%d", &x,&y);
        if((y>8)||(y<0)||(x<0)||(x>4)){
                printf("Zli vstup. Opakujte prosim");
                system("cls");
                user_input();}
        j=y;
        for(z=x; z<x+5; z++){
            a[z][j]=SHIP_MINE;}}
    else{
        printf("Zli vstup. Opakujte prosim %c", c);
        system("cls");
        user_input();}
    
    UI_location=(rand()%2);
    if(UI_location==0){
        first_UI_position=(rand()%9);
        second_UI_position=(rand()%5);
        while(a[first_UI_position][second_UI_position]==SHIP_MINE || a[first_UI_position][second_UI_position+1]==SHIP_MINE || a[first_UI_position][second_UI_position+2]==SHIP_MINE || a[first_UI_position][second_UI_position+3]==SHIP_MINE || a[first_UI_position][second_UI_position+5]==SHIP_MINE){
                first_UI_position=(rand()%9);
                second_UI_position=(rand()%5);}
        i=first_UI_position;
        for(z=second_UI_position; z<second_UI_position+5; z++){
                a[i][z]=SHIP_UI;}}
    else{
        first_UI_position=(rand()%5);
        second_UI_position=(rand()%9);
        while(a[first_UI_position][second_UI_position]==SHIP_MINE || a[first_UI_position+1][second_UI_position]==SHIP_MINE || a[first_UI_position+2][second_UI_position]==SHIP_MINE || a[first_UI_position+3][second_UI_position]==SHIP_MINE || a[first_UI_position+4][second_UI_position]==SHIP_MINE){
               first_UI_position=(rand()%5);
               second_UI_position=(rand()%9);}
        j=second_UI_position;
        for(z=first_UI_position; z<first_UI_position+5; z++){
            a[z][j]=SHIP_UI;}}
        
    vykreslovac(a);}

void vykreslovac(int a[9][9]){
    int i, j;
    system("cls");
    for(i=0; i<9; i++){
        printf("\n");
        for(j=0; j<9; j++){
            if(a[i][j]==SHIP_MINE){
                printf("<");}
            else if(a[i][j]==SHIP_UI){
                printf(".");}
            else if(a[i][j]==CORUPTED_SEA){
                printf("x");}
            else if(a[i][j]==COUNTER_MINE){
                printf(">");}
            else if(a[i][j]==COUNTER_UI){
                printf("x");}
            else{
            printf(".");}}}
     game(a);}

