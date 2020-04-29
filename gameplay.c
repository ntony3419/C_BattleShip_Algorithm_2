/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gameplay.c
 * Author: kali
 *
 * Created on April 27, 2020, 7:16 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "shiplist.h"
#include "misslelist.h"

/*
 * 
 */
void manipulateSetting(int * rowPt, int *colPt, shiplist* shipList, char* settingFile){
    FILE* fpt; 
    char locationCol;
    int locationRow;
    char direction;
    int length;
    char * shipName;
    
    
    shipName = (char*)malloc(sizeof(char)*100);
    /* get row and colum setting for field*/
    fpt = fopen(settingFile,"r");
    fscanf(fpt,"%d,%d\n",  colPt, rowPt);
    /* get ship data*/
    while(fscanf(fpt,"%c%d %c %d %[^\n]\n",&locationCol, &locationRow , &direction, &length, shipName) != EOF){        
        addShip(shipList , shipName, direction, locationCol, locationRow, length);        
    }
    fclose(fpt);
}

void manipulateMissle(char* missleFile, misslelist * missleList){
    
    FILE *fpt;
    char * missle;
    
    fpt = fopen(missleFile, "r");
    missle = (char*)malloc(sizeof(char)*100);
    while(fscanf(fpt, "%s\n", missle) != EOF){
        addMissle(missleList, missle);
        
    }
    free(missle);
    fclose(fpt);
}