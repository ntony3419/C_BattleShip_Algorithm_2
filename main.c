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

int main(int argc, char* argv[]) {
    
    int choice;
  /*  int * choicePT; */   /*will set choice to 0 if end game*/
 /*   char ** field;*/
    int inputRow;
    int inputCol;
    
    int* rowPt, *colPt;
    char * settingFile, *missleFile;
   
    
    shiplist * shipList;
    misslelist * missleList;
    
    shipList = createShipList();
    missleList = createMissleList();
    
    
    settingFile = (char*) malloc(sizeof(char)*100);
    missleFile = (char*) malloc(sizeof(char)*100);
    
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
    
    
    printf("col %d row %d \n", inputCol,inputRow);
    
      
    
    printShip(shipList);
    
    
    /* get the missle information */
    manipulateMissle(missleFile,  missleList);
    
   
    /* create the field*/
/*    field = (char**) malloc(sizeof(char*));*/
    
    do {
        menu();
        scanf("%d",&choice);
        if (choice == 1){
            /* start game */
            
            
        }
        if (choice == 2){
            /* show the missle */
             printf("Missle List\n");
            showMissle(missleList);
        }
        if (choice == 3){
            /* create new ship file*/
        }
        if(choice == 4){
            /* create new missle file*/
            
        }
        
        
        
        
    }while (choice != 0);
    
    /* showing the menu */
    
    
    
    /* create the field*/
    
    
    
    return 0;
}

