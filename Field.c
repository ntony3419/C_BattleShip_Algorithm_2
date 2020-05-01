/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Field.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define MAGENTA "\033[1;35m"

void field(char** field){
    
    

}
void showField(char**field, int realCol, int realRow, int** tileState){
    int i ,j;
     /* row number  1 2 3 4*/
    char charCol ; /* A B  C D */
    int rowCount;
    int numIte;
    int sIte; /* iterator for seperator row and column */
    char seperatorTwo[4]="===+";
    char seperatorOne[4]= "--++";
    
    i = 0;
    charCol = 'A';
    for (j = 0; j < realCol; j ++){             /* first row */
       /* row A B C D .... */                
                    if (j == 0) {  /* smily face */                        
                        field[i][j] = ')';    
                    }
                    else { /* ab  c d e f */
                        field[i][j]=charCol;
                        charCol++;
                    }
           
     
    }
    /* new line to for other row */
     /* number 1 2 3 4 5 for the row*/
   
    rowCount = 1;
    printf("\n"); /* from row 1 */
    for (numIte = 1 ; numIte < realRow ; numIte ++) { /* numbering the row */                 
        
        /* numbering the row */
        field[numIte][0] = (rowCount + '0');    /* convert the integer to char */
        rowCount++;            
        
    }
    printf(":");
    /* print all the tile */
    for (i = 0;i < realRow;i ++){
        for (j=0; j < realCol; j ++){
            if (i == 0 && j == 0) { /* the smiley face*/
                printf ("%c||",field[i][j]);
            }
            else if (j ==0){ /* location after the number */
                printf("%c ||", field[i][j]);
            }
            else if (i>9 && j >9){ /* field dimension is more than 9*/
                /* use the tile state to color the tile when the DEBUG enable*/
                #ifdef DEBUG         
                /* use tile state to determine color for ship tile on field*/
                    if(tileState[i][j]==1){ /* that tile has ship */
                        printf("%s %c %s|", MAGENTA, field[i][j], RESET); /* add color into this line */
                    }
                    else{
                        printf("%c |", field[i][j]); /* this line is normal*/
                    }
                #else   
                    printf("%c |", field[i][j]);
                #endif      
               
            }
            else{
                 #ifdef DEBUG         
                /* use tile state to determine color for ship tile on field*/
                    if(tileState[i][j]==1){ /* that tile has ship */
                         printf("%s %c %s|", MAGENTA,field[i][j], RESET); /* add color into this line */
                    }
                    else{
                         printf(" %c |", field[i][j]); /* this line is normal*/
                    }
                #else   
                     printf(" %c |", field[i][j]);
                #endif      
               
            }
          
          
        }
        printf("\n");
          /* line seperator between row*/
       
        for (sIte =0 ; sIte < realCol-1; sIte ++ ){
            if (sIte == 0){
               
                printf("%s",seperatorOne);
            }
            else{                
                printf("%s",seperatorTwo);
            }
            
            
        }
        
       
        printf("\n");
    }
    
    
    printf("\n");
        
        
    
}