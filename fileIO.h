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

#ifndef FILEIO_H
#define FILEIO_H
#endif /* FILEIO_H */

#include "linkedlist.h"

void loadSetting(int *cPt, int *rPt , char* fileName,  LinkedList *shipData, int*errorPt);

void loadMissle(char* weaponFile, LinkedList * missleData);
void listMissle(LinkedList* missleData);
int isEqual(char string[], char consttring[]);
void saveSetting(char *fileName);
void saveMissle(char *fileName);
