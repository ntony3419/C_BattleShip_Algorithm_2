/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Navid
 *
 * Created on April 27, 2020, 6:07 AM
 */

/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "misslelist.h"
#include "shiplist.h"
#include "menu.h"
#include "gameplay.h"
#include "Field.h"
#include <string.h>
int main(int argc, char* argv[]) {
    
    int choice;
  /*  int * choicePT; */   /*will set choice to 0 if end game*/
 /*   char ** field;*/
    int inputRow, realRow;
    
    int inputCol,i,j, realCol, single, splash, vline,hline;
    
    int* rowPt, *colPt, *singlePt, *splashPt, *vlinePt, *hlinePt;
    char * settingFile, *missleFile;
    char ** field;    
    int end; /* to stop the game */
    int*endPt; /* to change end value */
    int** tileState;
    char* missle; /* for user input missle name*/
    char corCol; /*cordinate to shoot */
    int corRow; /*cordinate to shoot */
    shiplist * shipList;
    misslelist * missleList;
   
    
    
    shipList = createShipList();
    missleList = createMissleList();
    
    
    settingFile = (char*) malloc(sizeof(char)*100);
    missleFile = (char*) malloc(sizeof(char)*100);
    
    /* init the missle amount*/
    single=0;
    splash=0; 
    vline=0;
    hline=0;
    singlePt = &single;    
    splashPt = &splash;
    vlinePt = &vline;
    hlinePt = &hline;  
  
       /* algorithm to play t he game*/
    do {
        menu();
        scanf("%d",&choice);
       /* count = 1;
        charCol='A';*/
        end = 0; /*0 is false  */
        endPt = &end;
   
        if (choice == 1){
            /* start game */
            
            /* get the file name*/
            printf("enter the file name for the ship\n");
            scanf("%s", settingFile);   
            printf("enter the file name for the missle \n");
            scanf("%s",missleFile);

            /* get the input for dimension from file */
            rowPt = &inputRow;
            colPt = &inputCol;     
            
            /* get the field and ship information from file*/
            manipulateSetting(rowPt, colPt, shipList , settingFile);               
            realRow = inputRow + 1; /* for the A B C D*/
            realCol = inputCol + 1; /* for the number 1 2 3 4*/
            printf("col %d row %d \n", realCol,realRow);
            /* get the missle information */
            manipulateMissle(missleFile,  missleList);
              /* create the field and initial to #*/
            field = (char**) malloc(sizeof(char*)*realRow);
            for (i=0; i < realRow; i++){
                field[i] = (char*)malloc(sizeof(char) * realCol);
            }
               /* initialize when i = 1 and j = 1*/       
            for (i = 1 ; i < realRow; i ++){
                for (j=1; j < realCol; j ++){
                    field[i][j]='#';                    
                }
            }       
            /* create a tile state array to store the location of all ship this will help enable DEBUG feature the field*/
            tileState = (int**)malloc(sizeof(int*)*realRow);
            for (i=1; i < realRow; i ++){
                tileState[i]= (int*)malloc(sizeof(int)*realCol);
                /* innitialize the state to 0*/
                for(j = 1; j < realCol; j++){
                    tileState[i][j]= 0; /* 0 mean nothing at this tile */
                }
            }
            /* use shiplist data to init the tile state*/            
            prepareTile(shipList, tileState, realCol, realRow,endPt);
            
            /* print test tile state*/
            for (i=1;i<realRow; i ++){
                for (j=1; j < realCol; j++){
                    printf("%d ", tileState[i][j]);
                }
                printf("\n");
            }
            
            /* show the field*/
            showField(field, realCol, realRow,tileState);
            
            /* 
             * below is algorithm to play the game 
             */
            
            /* when end not true , true == 1*/
           
            missle = (char*) malloc(sizeof(char)*100);
            while (end==0){ /* end is false */                
                /* show and calculate amount of missle*/
               showMissleAmount(missleList, singlePt, splashPt, vlinePt, hlinePt); /* showing the amount of missle collected from file */                             
               /* choose missle for the attack */
               printf("enter name of missle\n");
               scanf("%s", missle);
               printf("\n");
               /* decrease the missle count for that type base on the input from user*/
               if(strcmp(missle,"single")==0){
                   single--;
               }
               if(strcmp(missle,"splash")==0){
                   splash--;
               }
               if(strcmp(missle,"v-line")==0){
                   vline--;
               }
               if(strcmp(missle,"h-line")==0){
                   hline--;
               }
               /* check the missle count left to end the game at end of loop if all are used*/
               end = endCondition(missleList, single, splash,vline,hline); /* end is 1 if no more missle */
               
            /* get cordination from user to shoot*/
               printf("enter cordinate (columRow) ex. A1 \n");
               scanf("%c%d", &corCol, &corRow);
               
               
               
            }
        }
        /* menu 2*/
        if (choice == 2){
            /* show the missle */
            printf("Missle List\n");
            if (missleList->head == NULL){
                /* get the missle information */
                printf("enter the file name for the missle \n");
                scanf("%s",missleFile);
                manipulateMissle(missleFile,  missleList);
            }                         
            showMissleAmount(missleList, singlePt, splashPt, vlinePt, hlinePt); /* showing the amount of missle collected from file */
            
        }
        /*menu 3*/
        if (choice == 3){
            /* create new ship file*/
            printf("enter a name to create new setting file\n");
            scanf("%s", settingFile);
            createNewFile(choice, settingFile);
            
        }
        /* menu 4*/
        if(choice == 4){
            /* create new missle file*/
             printf("enter a name to create new missle file\n");
            scanf("%s", missleFile);
             createNewFile(choice, missleFile);
        }
        
        
        
        
    }while (choice != 0 && end==0);
    
    /* showing the menu */
    
    
    
    /* create the field*/
    
    
    
    return 0;
}

