#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include"vykreslenie.h"

void game(int a[9][9]){
    int w1=0,w2=0,i,j;
    char c='U', b='H';
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        if(a[i][j]==COUNTER_UI){
            w1++;}
        else if(a[i][j]==COUNTER_MINE){
            w2++;}}}
    if(w1==5){
        winner(c);}
    else if(w2==5){
        winner(b);}
    else My_Turn(a);}

void winner(char a){
    if(a=='U'){
        system("cls");
        printf("Human inteligent loose. Mankind is lost");
        getchar();
        exit(EXIT_FAILURE);}
    else system("cls");
         printf("Organics machines are stronger than metal");
         getchar();
         getchar();
         exit(EXIT_FAILURE);}

void UI(int a[9][9]){
    printf("sewas");
    vykreslovac(a);
    }

void My_Turn(int a[9][9]){
    int s1,s2;
    printf("Zadaj suradnice:\n");
    scanf("%d%d", &s1,&s2);
    if((s1>8)||(s1<0)||(s2>8)||(s2<0)||(a[s1][s2]==SHIP_MINE)||(a[s1][s2]==CORUPTED_SEA)||(a[s1][s2]==COUNTER_MINE)||(a[s1][s2]==COUNTER_UI)){
       system("cls");
       printf("Inteligent");
       My_Turn(a);}
    else if(a[s1][s2]==SHIP_UI){
       a[s1][s2]=COUNTER_MINE;
       UI(a);}
    else{
       a[s1][s2]=CORUPTED_SEA;
       UI(a);}}

