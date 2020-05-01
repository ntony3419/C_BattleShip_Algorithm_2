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
#include <ctype.h>
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
       
            /* get the missle information */
            manipulateMissle(missleFile,  missleList);
            findMissleAmount(missleList, singlePt, splashPt, vlinePt, hlinePt); /* showing the amount of missle collected from file */                             
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
            /* show the field*/
            showField(field, realCol, realRow,tileState);
            
            /* 
             * below is algorithm to play the game 
             */
            
            /* when end not true , true == 1*/
           
            missle = (char*) malloc(sizeof(char)*100);
            while (end==0){ /* end is false */                
                /* show and calculate amount of missle*/
              
               showMissleAmount(single,splash,vline, hline);
               /* choose missle for the attack */
               printf("enter name of missle\n");
               scanf("%s", missle);
              
               /* decrease the missle count for that type base on the input from user*/
               if (single >0 || splash >0 || vline>0 || hline>0){/* decrease by 1 after chosoe the missle */
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
               }
               printf("missle left\n");
               showMissleAmount(single,splash,vline, hline);
               printf("\n");
               /* check the missle count left to end the game at end of loop if all are used*/
               end = endCondition(missleList, single, splash,vline,hline); /* end is 1 if no more missle */
               
            /* get cordination from user to shoot*/
               printf("enter cordinate (columRow) ex. A1 \n");
               scanf("\n%c%d", &corCol, &corRow);
               corCol = toupper(corCol); /* convert the lower case to upper case for further calculation*/
               /* wrong cor*/
               if (corRow <1 || corRow > realRow || (corCol-16-'0') <1 || (corCol-16-'0') > realCol){
			printf("The cordinate is wrong \n");
		}
               
               /* fire base on missle name*/
               if (strcmp(missle,"single" ) == 0 ){
                    if (tileState[corRow][(corCol-16-'0')] == 1){ /* find in the state tile */
                        field[corRow][(corCol-16-'0')] = '0';/* change value of that tile*/
                    }
                    if ( tileState[corRow][(corCol-16-'0')] == 0) {
                        field[corRow][(corCol-16-'0')] = 'X'; /* tnothing there*/
                    }
                   /* show the field*/
                    showField(field, realCol, realRow,tileState);   
                }
               else if (strcmp(missle,"splash")==0){  
                   for (i = corRow-1 ; i <= corRow+1; i ++){ 
                       for (j = (corCol-16-'0')-1 ; j <= (corCol-16-'0')+1; j ++ ) {/* Letter  - 16 -'0' == numeric */ 
                           if (tileState[i][j] == 1){
                               field[i][j]='0';
                           }
                           if (tileState[i][j] == 0){
                               field[i][j]='X';
                           }
                           
                       }
                   }
                   
			 /* show the field*/
                    showField(field, realCol, realRow,tileState);   						
		} /* end of else if */
               
               		/*  vline missle*/
               else if (strcmp(missle,"v-line")==0 ){ 
				/* find in tile*/ 
			for (i=1; i < realRow; i ++) { /*loop through the row (vertically)*/
				if (tileState[i][(corCol-16-'0')] == 1){
					field[i][(corCol-16-'0')] = '0';					
				}
				if (tileState[i][(corCol-16-'0')] == 0){
					field[i][(corCol-16-'0')] = 'X';					
				}
			}
                    showField(field, realCol, realRow,tileState);				
		} /* end if of v line */
					
					/* user choose hline missle*/
               else if (strcmp(missle,"h-line")==0 ){ 
					
						/* mark the tile in column */ 
			for (i=1; i < realCol; i ++) { /*loop through the colum (horizontally)*/
				if (tileState[corRow][i] == 1){
					field[corRow][i] = '0'; 					
				}
				if (tileState[corRow][i] == 0){
					field[corRow][i] = 'X'; 					
				}
			}
                    showField(field, realCol, realRow,tileState);							
		}/* end if of h line */
              
            }
            if (end == 1 ){
                   printf("game finish \n");
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
            findMissleAmount(missleList, singlePt, splashPt, vlinePt, hlinePt); /* showing the amount of missle collected from file */
            showMissleAmount(single, splash, vline, hline);
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
        
        
        
        
    }while (choice != 0 );
    
    /* showing the menu */
    
    
    
    /* create the field*/
    
    
    
    return 0;
}

