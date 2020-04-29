/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"
#include <ctype.h>

void loadShipAndField(int *cPt, int *rPt, char* fileName, shiplist * shipData, int *errorPt){
	FILE *fpt;
	char locationCol;	
        int locationRow;
	char direction;
	int length;
	char *shipName;



	shipName = (char*)malloc(sizeof(char)*100);
        
	fpt = fopen(fileName, "r");
	
	if (fpt == NULL){
		perror ("file not found\n");
	}
		/* scane the first line to get the width and height*/
	fscanf(fpt,"%d,%d",cPt,rPt); 
	/* validate out of bound */
	if(*cPt <1 || *cPt > 12 || *rPt <1 || *rPt > 12 ){
            printf("dimension of the battlefield is wrong \n ");
            *errorPt = 1;
	}
	
	/* scan other line for ship data */
        while (fscanf(fpt,"%c%d %c %d %[^\n]",&locationCol, &locationRow , &direction, &length, shipName) != EOF){
        /* initial check if the ship length value is correct and out of  bound of battle field*/
            switch (toupper(direction)){
                            case 'W':
                            if (length < 1 || length > *rPt ){ /* head to west body to east */
                                            *errorPt = 1;
                                }


                            break;
                            case 'E':
                                    if (length < 1 || length > *rPt ){ /* head to west body to east */
                                            *errorPt = 1;
                                }
                            break;
                            case 'S':
                                    if (length < 1 || length > *cPt ){ /* head to west body to east */
                                            *errorPt = 1;
                                }
                            break;
                            case 'N':
                                    if (length < 1 || length > *cPt ){ /* head to west body to east */
                                            *errorPt = 1;
                                }
                            break;
                            default :
                                    *errorPt = 1;
                            break;
            }
        /* add ship information into shipdata list */
            addShip(shipData, shipName, direction, locationCol, locationRow,  length);
		
	}     
      
	fclose(fpt);
	/*
	free(location);
	free(shipName);*/

}

void loadMissle(char* weaponFile, misslelist * missleData ){
	FILE *weapFpt;
	char missleName[100];
	int singleCount,splashCount,vCount,hCount;  

	
	weapFpt = fopen(weaponFile,"r");
	if (weapFpt == NULL){
		perror ("missle file is invalid\n");
	}
     

	/*scan the missle data */
	singleCount =0;
	splashCount=0;
	vCount=0;
	hCount=0;

		
		while (fscanf(weapFpt,"%s\n", missleName) != EOF ){		
		
			if (isEqual(missleName,"SINGLE")==1){
				singleCount++;
			}
			else if (isEqual(missleName,"SPLASH")==1){
				splashCount++;
			}
			else if (isEqual(missleName,"V-LINE")==1){
				vCount++;
			}
			else if (isEqual(missleName,"H-LINE")==1){
				hCount++;
			}
			else {
				
				printf("----------------------------\nthere are incorrect missle inside the missle file please check the invalid missle file\n. Only loaded correct missle\n-----------------------------\n");
		
			}
			
		}		
		addMissle(missleData, singleCount, splashCount, vCount,hCount);
		
		fclose(weapFpt);
			
}
/*this function compare 2 string to determine equal for case - insensitive*/
int isEqual(char string[], char constring[]){
	int result ;/*equal 0 mean not equal */
	int i;
	result =0;	
	for (i=0; string[i] !='\0'; i++){
		if (string[i] >='a' && string[i] <='z'){
			string[i]=toupper(string[i]);			
		}
		string[i]=toupper(string[i]);	
	}
	
	if (strcmp(string,constring) ==0){
		result = 1;
	}
	return result;
}


void saveSetting(char* fileName){
	 FILE *fpt;
    int  col, row,length;	
   	int finish = 0;      
    char answer;
    char *shipName;
  	char *location;
	char  	direction;

	shipName = (char*) malloc(sizeof(char)*100);
	location = (char*) malloc(sizeof(char)*3);
	

    /* end create file */
    fpt = fopen(fileName,"w");/* FILE pointer */
    
    /* ask user input the data */
    printf("enter column size\n");
    scanf("%d",&col);
    printf("enter row size\n");
	 scanf("%d",&row);
	fprintf(fpt, "%d,%d\n",col,row);/* save the colum and row */
	 printf("enter ship data \n");
	/*ask for ship data */ 	
	while (finish ==0){	 
		
		printf("enter location\n");
		 scanf("%s",  location);
		 printf("enter direction\n");
	    scanf("\n%c",  &direction);  
	    printf("enter length\n");   
		scanf("\n%d", &length);  	        
		printf("enter ship name\n");
	 	scanf("%s", shipName);    
		/*write to ship */
		fprintf(fpt, "%s %c %d %s\n", location, direction, length, shipName);/* save the setting to */
		printf("Enter another one ? Y or Press any key to exit\n");
		scanf("\n%c", &answer);
		if (toupper(answer) == 'Y'){
			printf("Continue enter ship data\n\n");	
		}
		else {
			finish = 1; /* 1 mean get out of loop and finish */
				
		}
	}
/*
	free(shipName);
	free(location);*/
	
	fclose(fpt);

}

void saveMissle(char* fileName){
	FILE *fpt;   

    
    char *missleName;
 

	missleName = (char*) malloc(sizeof(char)*100);

    /* end create file */
    fpt = fopen(fileName,"w");/* FILE pointer */
    
  
	
	/*ask for missle data */ 	
	while (isEqual(missleName,"STOP") != 1){	 
		
		printf("enter missle name OR enter stop to finish\n");
		 scanf("%s",  missleName);
		if (   isEqual(missleName,"STOP") !=1 ){
		
		/*write to missle file */
			fprintf(fpt, "%s\n", missleName);/* save the setting to */
		}
		
	}
	/*free(missleName);*/

       fclose(fpt);

}

void printMissle(misslelist *missleList){
    showMissle(missleList);

}
