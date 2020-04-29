/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "misslelist.h"
#include <string.h>
#include <ctype.h>
/*a. create linked list*/
misslelist *createMissleList(void)
{
    misslelist *list;
    list = (misslelist*) malloc(sizeof(misslelist));
    list->head = NULL;

    return list;
}

void addMissleStart(misslelist *misslelist ,char * missle){

	missleNode *newNode;
        
        newNode = (missleNode*)malloc(sizeof(missleNode));
        
        newNode->single = (char*) malloc (sizeof(char)*100);
        newNode->splash = (char*) malloc (sizeof(char)*100);
        newNode->vline = (char*) malloc (sizeof(char)*100);
        newNode->hline = (char*) malloc (sizeof(char)*100);
	/* add the data to the to missle list*/
        if ( strcmp(lowerconvert(missle), "single")==0){
             
            strcpy(newNode->single,"single");
            
        }
         if ( strcmp(lowerconvert(missle), "splash")==0){
           
              strcpy(newNode->splash,"splash");
        
        }
         if ( strcmp(lowerconvert(missle), "v-line")==0){
            
              strcpy(newNode->vline,"v-line");
        
        }
         if ( strcmp(lowerconvert(missle), "h-line")==0){
          
              strcpy(newNode-> hline,"h-line");
        
        }
        
	newNode->next = NULL;
	if (misslelist->head == NULL)
	{
		misslelist->head = newNode;
	}
	else
	{
		newNode-> next = misslelist->head;
		misslelist->head = newNode;
	}
     /*    free(newNode->single );
        free(newNode->splash );
        free(newNode->vline );
       free(newNode->hline );*/
/*	free(newNode);*/
         
}

void addMissle(misslelist *misslelist ,char * missle){

    missleNode *newNode, *cursor;
    
    cursor = (missleNode*)malloc(sizeof(missleNode));
    cursor = misslelist->head;
    /* loop untill the end of the linkedlist */
    if (cursor == NULL)
    {
         addMissleStart(misslelist,  missle);
    }
    else
    {
       while (cursor -> next != NULL)
        {
            cursor = cursor->next;
        }
        /* cursor is at the end of the linkedlist */
        /* create new Node */
        
        newNode = (missleNode*)malloc(sizeof(missleNode));
        newNode->single = (char*) malloc (sizeof(char)*100);
        newNode->splash = (char*) malloc (sizeof(char)*100);
        newNode->vline = (char*) malloc (sizeof(char)*100);
        newNode->hline = (char*) malloc (sizeof(char)*100);
	/* add the data to the to missle list*/
        if ( strcmp(lowerconvert(missle), "single")==0){
             
            strcpy(newNode->single,"single");
            
        }
         if ( strcmp(lowerconvert(missle), "splash")==0){
           
              strcpy(newNode->splash,"splash");
        
        }
         if ( strcmp(lowerconvert(missle), "v-line")==0){
            
              strcpy(newNode->vline,"v-line");
        
        }
         if ( strcmp(lowerconvert(missle), "h-line")==0){
          
              strcpy(newNode-> hline,"h-line");
        
        }
        
	
	           
        newNode -> next = NULL;

        /* set the cursor.next to newNode */
        cursor -> next = newNode;
    }
/*	  free(newNode->single );
        free(newNode->splash );
        free(newNode->vline );
       free(newNode->hline );*/
	/*free(newNode);
        free(cursor);*/
        
}

void showMissle(misslelist *misslelist)
{

    missleNode *cursor = (missleNode*)malloc(sizeof(missleNode));
    cursor = misslelist->head;/* cursor at the head */
    

    /* loop the cursor through the list and print every loop */
    if (cursor == NULL)
    {
        printf("list empty \n");
    }
    else /* when loop is not empty */
    {
        while (cursor !=NULL)
        {
            if (strcmp(cursor->single, "single") == 0){
                 printf("%s\n", cursor->single);
                
            }
             if (strcmp(cursor->splash, "splash") == 0){
                printf("%s\n", cursor->splash);
                
            }
             if (strcmp(cursor->vline, "v-line") == 0){
                printf("%s\n", cursor->vline);
                 
                
            }
         if (strcmp(cursor->hline, "h-line") == 0){
                 printf("%s\n", cursor->hline);
                 
                
            }
            
           
            
            cursor = cursor -> next;
        }

    }
 /*   free(cursor);*/

}
char * lowerconvert(char*missle){    
    int i;
    
    for (i=0; missle[i] !='\0'; i++){
		if (missle[i] >='A' && missle[i] <='Z'){
			missle[i]=tolower(missle[i]);			
		}
		missle[i]=tolower(missle[i]);	
	}
	
	
    
    return missle;
}