/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist.h
 * Author: Navid
 *
 * Created on April 27, 2020, 7:18 AM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#endif

typedef struct JNode
{    
    char *shipName;
    char direction ;
    char *location;
    int length;	   
    
    int singleCount;    
    int splashCount;    
    int vCount;
    int hCount;

	
    struct JNode *next;
} JNode;

typedef struct LinkedList
{
    JNode * head;


}LinkedList;


/*create linked list*/
LinkedList *createLL(void); /* this is function pointer*/

/* b. insert at start*/
void insertStart(LinkedList *list,  char *shipName, char direction, char* location, int length);
/* c. remove from start*/
void removeStart(LinkedList *list);
/*d. retrive */
JNode *retrieveElement(LinkedList * list, int index);
/*e print content */
void printShip(LinkedList *list);
/* f quest 3*/
void insertEnd(LinkedList *list , char *shipName, char direction, char *location, int length);
/*missle list */
void insertMissleStart(LinkedList *list,  int singleCount, int splashCount, int vCount, int hCount);
void insertMissleEnd(LinkedList *list , int singleCount, int splashCount, int vCount, int hCount);
void printMissle(LinkedList *list);





