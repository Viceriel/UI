#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"vykreslenie.h"
#include"game.h"

void user_input(void){
    int a[9][9]={(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),(SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA,SEA),};
    int x,y,i,j,z;
    srand(time(NULL));
    printf("Zadaj riadok a stlpec:\n");
    scanf("%d%d", &x,&y);
    if((x>8)||(x<0)||(y<0)||(y>4)){
        printf("Zli vstup. Opakujte prosim");
        system("cls");
        user_input();}
    int first_UI_position=(rand()%9);
    int second_UI_position=(rand()%5);
    while(first_UI_position==x){
        first_UI_position=(rand()%9);}
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(i==x && j==y){
                for(z=j; z<j+5; z++){
                    a[i][z]=SHIP_MINE;}}
            else if(i==first_UI_position && j==second_UI_position){
                for(z=second_UI_position; z<second_UI_position+5; z++){
                    a[i][z]=SHIP_UI;}}
            }}
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

