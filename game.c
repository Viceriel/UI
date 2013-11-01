#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
        getchar();
        exit(EXIT_FAILURE);}
    else system("cls");
         printf("Organics machines are stronger than metal");
         getchar();
         getchar();
         exit(EXIT_FAILURE);}

void UI(int a[9][9]){
    int i,j,sp1=0,sp2=0,UI=0,counter=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(a[i][j]==COUNTER_UI){
                UI=1;
                sp1=i;
                sp2=j;}}}
    if((a[sp1][sp2+1]==CORUPTED_SEA && UI==1)){
        i=sp1;
        for(j=8;j>=0;j--){
            if(a[i][j]==COUNTER_UI){
                sp2=j;
                counter=1;}}
        if(a[sp1][sp2-1]==CORUPTED_SEA){
            counter=2;
            if(a[sp1+1][sp2]==CORUPTED_SEA){
                j=sp2;
                for(i=8; i>=0; i--){
                    if(a[i][j]==COUNTER_UI){
                        sp1=i;
                        counter=3;}}}}}
    
    if(UI==0){
        UI_random(a);}
    
    if(counter==0){
        if(a[sp1][sp2+1]==SHIP_MINE){
            a[sp1][sp2+1]=COUNTER_UI;
            vykreslovac(a);}
        else if(a[sp1][sp2+1]==SEA){
            a[sp1][sp2+1]=CORUPTED_SEA;
            vykreslovac(a);}}
    else if(counter==1){
        if(a[sp1][sp2-1]==SHIP_MINE){
            a[sp1][sp2-1]=COUNTER_UI;
            vykreslovac(a);}
        else if(a[sp1][sp2-1]==SEA){
            a[sp1][sp2-1]=CORUPTED_SEA;
            vykreslovac(a);}}
    else if(counter==2){
        if(a[sp1+1][sp2]==SHIP_MINE){
            a[sp1+1][sp2]=COUNTER_UI;
            vykreslovac(a);}
        else if(a[sp1+1][sp2]==SEA){
            a[sp1+1][sp2]=CORUPTED_SEA;
            vykreslovac(a);}}
    else if(counter==3){
        if(a[sp1-1][sp2]==SHIP_MINE){
            a[sp1-1][sp2]=COUNTER_UI;
            vykreslovac(a);}
        else if(a[sp1-1][sp2]==SEA){
            a[sp1-1][sp2]=CORUPTED_SEA;
            vykreslovac(a);}
    }
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

void UI_random(int a[9][9]){
    srand(time(NULL));
    int s1=(rand()%9);
    int s2=(rand()%9);
    while((a[s1][s2]==CORUPTED_SEA)||(a[s1][s2]==SHIP_UI)||(a[s1][s2]==COUNTER_MINE)){
            s1=(rand()%9);
            s2=(rand()%9);}
    if(a[s1][s2]==SEA){
            a[s1][s2]=CORUPTED_SEA;
            vykreslovac(a);}
    else if(a[s1][s2]==SHIP_MINE){
            a[s1][s2]=COUNTER_UI;
            vykreslovac(a);}}
    


