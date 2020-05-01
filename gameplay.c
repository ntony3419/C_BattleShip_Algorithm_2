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
#include <ctype.h>
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
void play(char** field, int realCol, int realRow, int end){
    
}

void showMissleAmount(int single, int splash, int vline, int hline){
    printf("Single %d\nSplash %d\nV-line %d\nH-line %d\n", single, splash, vline, hline );
}
void findMissleAmount(misslelist * missleList, int * singlePt, int *splashPt,int * vlinePt, int*hlinePt){
    /* this function will show the amount of missle each type and also return the count of each type to the main function*/
    /* calculate the amount*/
    /* loop through the missle list to calculate each type of missle and return to main function*/
    missleNode *cursor; 
    cursor = (missleNode*)malloc(sizeof(missleNode));
    cursor = missleList->head; /* starting*/
    while (cursor != NULL){ /* loop each one*/
        /* count each data*/
        if (strcmp(cursor->single, "single") == 0 ) {
            (*singlePt)++; /* increace the value of pointer single */            
        }
         if (strcmp(cursor->splash, "splash") == 0 ) {
            (*splashPt)++; /* increace the value of pointer single */            
        }
         if (strcmp(cursor->vline, "v-line") == 0 ) {
            (*vlinePt)++; /* increace the value of pointer single */            
        }
         if (strcmp(cursor->hline, "h-line") == 0 ) {
            (*hlinePt)++; /* increace the value of pointer single */            
        }    
        cursor = cursor->next;
    }
 
 
}

/* winning condition is when no mor missle and no more ship*/
int endCondition(misslelist * missleList, int single, int splash, int vline,int hline){
    int end;
    end = 0;
    if (single == 0 && splash == 0 && vline == 0 && hline ==0 ){
        end = 1; /* end is true*/
    
    }
    return end;
}

void prepareTile(shiplist * shipList,int** tileState, int realCol,int realRow, int*endPt){
    shipNode * cursor;
    int i,j, count;
    
    cursor = (shipNode*) malloc(sizeof(shipNode));
    
    
    cursor = shipList->head;
    while (cursor != NULL){ /* loop each node to get data */
       
        for (i = 1; i < realRow; i ++){
            for (j=1; j < realCol; j ++){
                if (tolower(cursor -> direction) == 'w'){ /* body to the east set state as lenth to the east*/
                    if ( (cursor -> locationCol - 16 -'0') == j && (cursor -> locationRow )==i){ /* found the head */
                        /* change the state accorting to length*/
                        for (count =0; count < cursor->length; count++){
                            if (tileState[i][j+count] == 1) {/*ship tile colision*/
                                printf("there are collision in ship information check the file\n");                                 
                                *endPt=1; /*quit the game */
                            }       
                            
                            if ((j+count) > realRow){ 
                              *endPt = 1; /* out of bound end game*/
                               printf("Check the file again. out of bound detected \n");
					
                            }
                            tileState[i][j+count] = 1; /* switch state to true (has ship )*/
                        }
                    }
                }
                if (tolower(cursor -> direction) == 'e'){/* body to the west*/
                    if ( (cursor -> locationCol - 16 -'0') == j && (cursor -> locationRow )==i){ /* found the head */
                        /* change the state accorting to length*/
                        for (count =0; count < cursor->length; count++){
                             if ( tileState[i][j-count] == 1) {/*ship tile colision*/
                                printf("\nthere are collision in ship information check the file\n");                                 
                                *endPt=1; /*quit the game */
                            }  
                             if (i-count < 0){ 
					*endPt = 1; /*out of bound detected*/
					printf("\nship out of bound\n");
					
				}
                            tileState[i][j-count] = 1; /* switch state to true (has ship )*/
                        }
                    }
                }
                if (tolower(cursor -> direction) == 's'){/* body to the north*/
                    if ( (cursor -> locationCol - 16 -'0') == j && (cursor -> locationRow)==i){ /* found the head */
                        /* change the state accorting to length*/
                        for (count =0; count < cursor->length; count++){
                             if ( tileState[i-count][j] == 1) {/*ship tile colision*/
                                printf("\nthere are collision in ship information check the file\n");                                 
                                *endPt=1; /*quit the game */
                            }        
                             if ((i-count) < 0){ /*can't go further than upper bound */
					*endPt = 1; /*out of bound is true. this will stop this function and end the program*/
					printf("\nout of bound detected\n");
									
				}
                            tileState[i-count][j] = 1; /* switch state to true (has ship )*/
                        }
                    }
                }
                if (tolower(cursor -> direction) == 'n'){/* body to the south*/
                    if ( (cursor -> locationCol - 16 -'0') == j && (cursor -> locationRow )==i){ /* found the head */
                        /* change the state accorting to length*/
                        for (count =0; count < cursor->length; count++){
                             if (tileState[i+count][j] == 1) {/*ship tile colision*/
                                printf("\nthere are collision in ship information check the file\n");                                 
                                *endPt=1; /*quit the game */
                            }       
                             if ((i - count) >= realRow){ /*can't go further than bottom bound */
					*endPt = 1; /*out of bound is true. this will stop this function and end the program*/
					printf("\na out of bound detected\n");
					
				}
                            tileState[i+count][j] = 1; /* switch state to true (has ship )*/
                        }
                    }
                }
        
            }
        }
        cursor = cursor->next;
   
    }
    
    
}