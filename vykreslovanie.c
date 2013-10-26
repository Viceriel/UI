#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"vykreslenie.h"

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
    int first_UI_position=(rand()%9)+1;
    int second_UI_position=(rand()%4)+1;
    while(first_UI_position==x){
        first_UI_position=(rand()%9)+1;}
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(i==x && j==y){
                for(z=j; z<j+5; z++){
                    a[i][z]=SHIP;}}
            else if(i==first_UI_position && j==second_UI_position){
                for(z=second_UI_position; z<second_UI_position+5; z++){
                    a[i][z]=SHIP;}}
            }}
    vykreslovac(a);}

int vykreslovac(int a[9][9]){
    int i, j;
    for(i=0; i<9; i++){
        printf("\n");
        for(j=0; j<9; j++){
            if(a[i][j]==SHIP){
                printf("<");}
            else{
            printf(".");}}}
    return a;}
