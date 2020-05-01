/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gameplay.h
 * Author: Navid
 *
 * Created on April 28, 2020, 12:18 AM
 */


void manipulateSetting(int * rowPt, int *colPt, shiplist * shipList, char* settingFile);

void manipulateMissle(char* missleFile, misslelist * missleList);
void createNewFile(int userChoice, char* fileName);
void play(char** field, int realCol, int realRow, int end);
int endCondition(misslelist * missleList, int single, int splash, int vline,int hline);
void findMissleAmount(misslelist * missleList, int * singlePt, int *splashPt,int * vlinePt, int*hlinePt);
void prepareTile(shiplist * shipList,int** tileState, int realCol,int realRow, int*endPt);
void showMissleAmount(int single, int splash, int vline, int hline);