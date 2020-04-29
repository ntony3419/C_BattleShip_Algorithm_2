/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   shiplist.h
 * Author: Navid
 *
 * Created on April 27, 2020, 7:18 AM
 */

#ifndef SHIPLIST_H
#define SHIPLIST_H
typedef struct shipNode{    
    char *shipName;
    char direction ;
    char locationCol;
    int locationRow;
    int length;	   
    
    int singleCount;    
    int splashCount;    
    int vCount;
    int hCount;

	
    struct shipNode *next;
} shipNode;


typedef struct shiplist{
    shipNode * head;
}shiplist;


/*create shiplist*/
shiplist *createShipList(void); /* this is function pointer*/

/* addship at start*/
void addShipFront(shiplist *shiplist,  char *shipName, char direction, char locationCol, int locationRow, int length);
void addShip(shiplist *shiplist , char *shipName, char direction, char locationCol, int locationRow, int length);

/*print ship */
void printShip(shiplist *shiplist);

#endif