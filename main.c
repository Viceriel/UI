/* 
 * File:   main.c
 * Author: JLD
 *
 * Created on Utorok, 2013, október 22, 6:33
 */

#include <stdio.h>
#include <stdlib.h>
#include"vykreslenie.h"

/*
 * 
 */
int main() {
    int **b;
    b=user_input();
    printf("%d", b[5][1]);
    getchar();
    getchar();
    return (EXIT_SUCCESS);}

