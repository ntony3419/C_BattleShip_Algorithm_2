/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   misslelist.h
 * Author: kali
 *
 * Created on April 28, 2020, 1:00 AM
 */

#ifndef MISSLELIST_H
#define MISSLELIST_H
typedef struct missleNode{    
      
    char* single;
    char* splash;
    char* vline;
    char* hline;
    

	
    struct missleNode *next;
} missleNode;


typedef struct misslelist{
    missleNode * head;
}misslelist;


/*create misslelist*/
misslelist *createMissleList(void); /* this is function pointer*/



/*show missle */
void addMissleStart(misslelist *misslelist ,char * missle);
void addMissle(misslelist *list ,char * missle);
void showMissle(misslelist *list);
char * lowerconvert(char*missle);

#endif

