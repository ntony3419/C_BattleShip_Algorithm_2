/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist.c
 * Author: Navid
 *
 * Created on April 27, 2020, 7:17 AM
 */



/*
 * 
 */
#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

/*a. create linked list*/
LinkedList *createLL(void)
{
    LinkedList *list;
    list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

/* b. insert at start*/
void insertStart(LinkedList *list,  char *shipName, char direction, char *location, int length ){

	JNode *newNode = (JNode * ) malloc(sizeof(JNode));
	
	newNode -> shipName = (char*)malloc(sizeof(char)*100);
        strcpy(newNode->shipName, shipName);
	newNode -> direction = direction;
	newNode -> location = (char*)malloc(sizeof(char)*3);
        strcpy(newNode->location, location);
	newNode -> length = length;
	
	
	newNode->next = NULL;
	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		newNode-> next = list->head;
		list->head = newNode;
	}
	/*
	free(newNode -> shipName);
	free(newNode -> location);
*/
}
/* c. remove from start*/


void removeStart(LinkedList *list)
{
   /* JNode *newNode = (JNode*) malloc(sizeof(JNode));*/  /* should use NewNode to free the memory when removing head */
    if (list->head == NULL)
    {
        printf("empty linkedlist \n");
    }
    else
    {
	    /* point the head to next node */
	    list->head = list->head-> next;
    }
  /*  free(newNode);*/

}
/*d. retrive */


JNode * retrieveElement(LinkedList * list, int index)
{
    JNode *newNode = (JNode*) malloc(sizeof(JNode));
    int counter=0;
    if (list->head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        newNode = list->head;
        counter = 1;
        if (counter == index)
        {
            printf("found the node\n");
        }
        else
        {
            while (newNode-> next !=NULL )
            {
                newNode = newNode-> next;
                counter ++;
                if (counter == index)
                {
                    printf ("found the node \n");

                }
            }
        }
    }

    return newNode;
}

/* print game setting 
void printSetting(LinkedList *list)
{
    printf("Setting : \n\tM: %d\n\tN: %d\n  \tK: %d\n", list->head->height, list->head->width, list->head->win);
*/


/*e print content */
void printShip(LinkedList *list)
{

    JNode *cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;/* cursor at the head */
    

    /* loop the cursor through the list and print every loop */
    if (cursor == NULL)
    {
        printf("list empty \n");
    }
    else /* when loop is not empty */
    {
        while (cursor !=NULL)
        {
            printf("shipname %s\ndirection %c\n location %s\n length %d\n", cursor->shipName, cursor->direction, cursor->location, cursor->length);
            
            cursor = cursor -> next;
        }

    }
  /*  free(cursor);*/

}
/* f quest 3*/
void insertEnd(LinkedList *list,  char *shipName, char direction, char *location, int length )
{
	JNode *newNode, *cursor;
    cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;
    /* loop untill the end of the linkedlist */
    if (cursor == NULL)
    {
         insertStart(list,   shipName, direction,location, length);
    }
    else
    {
       while (cursor -> next != NULL)
        {
            cursor = cursor->next;
        }
        /* cursor is at the end of the linkedlist */
        /* create new Node */
        
        newNode = (JNode*)malloc(sizeof(JNode));
		
	newNode -> shipName = (char*)malloc(sizeof(char)*100);
        strcpy(newNode->shipName, shipName);
	newNode -> direction = direction;
	newNode -> location = (char*)malloc(sizeof(char)*3);
        strcpy(newNode->location, location);
	newNode -> length = length;    
	
	
	           
        newNode -> next = NULL;

        /* set the cursor.next to newNode */
        cursor -> next = newNode;
    }
/*	free(newNode->shipName);
	free(newNode-> location);
    free(cursor);*/


}

void insertMissleStart(LinkedList *list, int singleCount, int splashCount, int vCount, int hCount ){

	JNode *newNode = (JNode * ) malloc(sizeof(JNode));
	
	newNode -> singleCount = singleCount;
	newNode -> splashCount = splashCount;
	newNode -> vCount = vCount;
	newNode -> hCount = hCount;
	
	newNode->next = NULL;
	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		newNode-> next = list->head;
		list->head = newNode;
	}

/*	free(newNode);*/
}

void insertMissleEnd(LinkedList *list, int singleCount, int splashCount, int vCount, int hCount )
{
	JNode *newNode, *cursor;
    cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;
    /* loop untill the end of the linkedlist */
    if (cursor == NULL)
    {
         insertMissleStart(list,   singleCount, splashCount,vCount, hCount);
    }
    else
    {
       while (cursor -> next != NULL)
        {
            cursor = cursor->next;
        }
        /* cursor is at the end of the linkedlist */
        /* create new Node */
        
        newNode = (JNode*)malloc(sizeof(JNode));
		
	newNode -> singleCount = singleCount;
	newNode -> splashCount = splashCount;
	newNode -> vCount = vCount;
	newNode -> hCount = hCount;
	
	
	           
        newNode -> next = NULL;

        /* set the cursor.next to newNode */
        cursor -> next = newNode;
    }
	/*free(newNode);*/
}

void printMissle(LinkedList *list)
{

    JNode *cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;/* cursor at the head */
    

    /* loop the cursor through the list and print every loop */
    if (cursor == NULL)
    {
        printf("list empty \n");
    }
    else /* when loop is not empty */
    {
        while (cursor !=NULL)
        {
            printf("Single %d\nSplash : %d\nV-line : %d\nH-Line %d\n", cursor->singleCount, cursor->splashCount, cursor->vCount, cursor->hCount);
            
            cursor = cursor -> next;
        }

    }
 /*   free(cursor);*/

}

/*

int main(int argc, char* argv[])
{

    LinkedList *listPtr;
    JNode *cursor;
    listPtr = createLL();
   
   insertEnd(listPtr, "hohoho",'E',"d1",5);
   
   insertEnd(listPtr, "hihi",'E',"d1",5);
   insertEnd(listPtr, "haha",'E',"d1",5);
    printLL(listPtr);
printf("\n\n");
	LinkedList *WeaponList;
	WeaponList = createLL();


	insertWeapStart(WeaponList, "boom");
	insertWeapEnd(WeaponList, "kkkkkkaaa boom " );
	insertWeapEnd(WeaponList, " boom " );

	insertWeapEnd(WeaponList, "chiiu  boom " );

	printMissle(WeaponList);



    cursor = listPtr-> head;
    while (cursor!= NULL)
    {
        listPtr-> head = cursor->next;
        free(cursor);
        cursor = listPtr-> head;


    }
    free(listPtr);
	return 0;
}
*/
