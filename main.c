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

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linkedlist.h"
/*
 * 
 */

int main(int argc, char* argv[]) {
    FILE *fpt;
    int choice;
  /*  int * choicePT; */   /*will set choice to 0 if end game*/
    char ** field;
    int inputRow;
    int inputCol;
    char * settingFile, *missleFile;
    char locationCol;
    int locationRow;
    char direction;
    int length;
    char * shipName;
    
    LinkedList * shipList;
    LinkedList * missleList;
    
    shipList = createLL();
    missleList = createLL();
    
    
    settingFile = (char*) malloc(sizeof(char)*100);
    missleFile = (char*) malloc(sizeof(char)*100);
    
    /* get the file name*/
    printf("enter the file name for the ship\n");
    scanf("%s", settingFile);   
    printf("enter the file name for the missle \n");
    scanf("%s",missleFile);
   
    /* get the input for dimension from file */
    fpt = fopen(settingFile,"r");
    fscanf("%d,%d", &inputRow, &inputCol);
    /* get the ship information from file*/
    printf("row %d col %d \n", inputRow, inputCol);
    printShip(shipList);
    printMissle(missleList);
    
    while(!EOF){
        fscanf("%c%d %c %d %[^]\n", &locationCol, &locationRow, &direction, &length, shipName );
        
    }
    
    
    /* get the missle information */
    fpt = fopen(missleFile, "r");
    
    
    
    /* create the field*/
    field = (char**) malloc(sizeof(char*));
    
    do {
        menu();
        scanf("%d",&choice);
        if (choice == 1){
            /* start game */
            
            
        }
        if (choice == 2){
            /* show the missle */
            
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

