/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shiplist.c
 * Author: Navid
 *
 * Created on April 27, 2020, 7:17 AM
 */



/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shiplist.h"
#include <ctype.h>
shiplist *createShipList(void)
{
    shiplist *list;
    list = (shiplist*) malloc(sizeof(shiplist));
    list->head = NULL;

    return list;
}


void addShipFront(shiplist *shiplist,  char *shipName, char direction, char locationCol, int locationRow, int length ){

	shipNode *newNode = (shipNode * ) malloc(sizeof(shipNode));
	
	newNode -> shipName = (char*)malloc(sizeof(char)*100);
        strcpy(newNode->shipName, shipName);
	newNode -> direction = tolower(direction);
	newNode -> locationCol = locationCol;
        newNode -> locationRow = locationRow;
	newNode -> length = length;
	
	
	newNode->next = NULL;
	if (shiplist->head == NULL)
	{
		shiplist->head = newNode;
	}
	else
	{
		newNode-> next = shiplist->head;
		shiplist->head = newNode;
	}
        
	
}


/*e print content */
void printShip(shiplist *shiplist)
{

    shipNode *cursor = (shipNode*)malloc(sizeof(shipNode));
    cursor = shiplist->head;/* cursor at the head */
    

    /* loop the cursor through the shiplist and print every loop */
    if (cursor == NULL)
    {
        printf("shiplist empty \n");
    }
    else /* when loop is not empty */
    {
        while (cursor !=NULL)
        {
            printf("shipname %s\ndirection %c\nlocation %c%d\n length %d\n\n", cursor->shipName, cursor->direction, cursor->locationCol, cursor -> locationRow, cursor->length);            
            cursor = cursor -> next;
        }

    }
  /*  free(cursor);*/

}

void addShip(shiplist *shiplist,  char *shipName, char direction, char locationCol, int locationRow, int length )
{
    shipNode *newNode, *cursor;
    cursor = (shipNode*)malloc(sizeof(shipNode));
    cursor = shiplist->head;
    /* loop untill the end of the linkedlist */
    if (cursor == NULL)
    {
         addShipFront(shiplist,   shipName, direction,locationCol, locationRow, length);
    }
    else
    {
       while (cursor -> next != NULL)
        {
            cursor = cursor->next;
        }
        /* cursor is at the end of the linkedlist */
        /* create new Node */
        
        newNode = (shipNode*)malloc(sizeof(shipNode));
		
	newNode -> shipName = (char*)malloc(sizeof(char)*100);
        strcpy(newNode->shipName, shipName);
	newNode -> direction = tolower(direction);
	newNode -> locationCol = locationCol;
        newNode -> locationRow = locationRow;
	newNode -> length = length;    
	
	
	           
        newNode -> next = NULL;

        /* set the cursor.next to newNode */
        cursor -> next = newNode;
    }


}
