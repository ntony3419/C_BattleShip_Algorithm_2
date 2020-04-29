/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileIO.h
 * Author: Navid
 *
 * Created on April 27, 2020, 6:11 AM
 */



#include "shiplist.h"
#include "misslelist.h"
void loadShipAndField(int *cPt, int *rPt , char* fileName,  shiplist *shiplist, int*errorPt);
void loadMissle(char* weaponFile, misslelist * missleList);
void printMissle(misslelist* missleData);
int isEqual(char string[], char consttring[]);
void saveSetting(char *fileName);
void saveMissle(char *fileName);
