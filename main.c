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

int main(int argc, char* argv[]) {
    
    int choice;
  /*  int * choicePT; */   /*will set choice to 0 if end game*/
 /*   char ** field;*/
    int inputRow, realRow;
    int inputCol,i,j, realCol;
    
    int* rowPt, *colPt;
    char * settingFile, *missleFile;
    char ** field;
    
    
    shiplist * shipList;
    misslelist * missleList;
    
    shipList = createShipList();
    missleList = createMissleList();
    
    
    settingFile = (char*) malloc(sizeof(char)*100);
    missleFile = (char*) malloc(sizeof(char)*100);
    
    
    
   
  
    
    do {
        menu();
        scanf("%d",&choice);
       /* count = 1;
        charCol='A';*/
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
            printShip(shipList);
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
            
            
            showField(field, realCol, realRow);
            
        }
        if (choice == 2){
            /* show the missle */
            printf("Missle List\n");
            if (missleList->head == NULL){
                /* get the missle information */
                printf("enter the file name for the missle \n");
                scanf("%s",missleFile);
                manipulateMissle(missleFile,  missleList);
            }             
            showMissle(missleList);
        }
        if (choice == 3){
            /* create new ship file*/
            printf("enter a name to create new setting file\n");
            scanf("%s", settingFile);
            createNewFile(choice, settingFile);
            
        }
        if(choice == 4){
            /* create new missle file*/
             printf("enter a name to create new missle file\n");
            scanf("%s", missleFile);
             createNewFile(choice, missleFile);
        }
        
        
        
        
    }while (choice != 0);
    
    /* showing the menu */
    
    
    
    /* create the field*/
    
    
    
    return 0;
}

