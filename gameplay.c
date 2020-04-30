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
#include <string.h>
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
void createNewFile(int userChoice, char* fileName){
    
    FILE * fpt ;
    int col, row;
    char* stop;
    char* location;
    char direction;
    int length;
    char*shipName;
    char*missle;
    
    stop = (char*) malloc(sizeof(char)*100);
    location = (char*) malloc(sizeof(char)*2);
    shipName = (char*) malloc (sizeof(char)*100);
    
    
    if (userChoice == 3){ /* create setting */
        
        /* open a file*/
        fpt = fopen(fileName, "w");
        printf("enter dimension for the field (col,row)\n");
        scanf("%d,%d", &col, &row);
        fprintf(fpt, "%d,%d\n", col, row);
        
        /* loop for ship information and write to file*/
      
        do{
            printf("Enter ship information (format : location direction length shipname) \n Example: A1 E 3 shipone\n");
            
            scanf("%s %c %d %s", location, &direction, &length, shipName); /* get information */           
            printf("\n");
            /* write to the file*/
            fprintf(fpt, "%s %c %d %s\n", location, direction, length, shipName);
             /* continue prompt */
            printf("\nenter \"stop\" to exit\nOR enter anything ti continue\n");
            scanf("%s", stop);
        }while (strcmp(stop, "stop") != 0);
        /* reset the stop when return to menu*/
        stop = "nonestop";
        
        fclose(fpt);
    }
    if (userChoice == 4){/*create missle */
          /* open a file*/
        
        fpt = fopen(fileName, "w");
        
        
        missle = (char*) malloc(sizeof(char)*100);
        /* loop for missle information and write to file*/
      
        do{
            printf("Enter missle information\n");            
            scanf("%s", missle); /* get information */           
            printf("\n");
            /* write to the file*/
            fprintf(fpt, "%s\n", missle);
             /* continue prompt */
            printf("\nenter \"stop\" to exit\nOR enter anything ti continue\n");
            scanf("%s", stop);
        }while (strcmp(stop, "stop") != 0);
        /* reset the stop when return to menu*/
        stop = "nonestop";
        
        
        fclose(fpt);
    }
}
