#include "../include/soomalHarkiratA2.h"

//function 1
char * readFile(char * filename){

    FILE * fptr;
    char * contents; //contents of file

    int num = 0; //count number of words in string

    fptr = fopen(filename, "r");
    //check if file is empty 
    if(fptr==NULL){
        printf("Error");
        return NULL;
    }
    else{ 
       //loop till fill empty
        while(!feof(fptr)){
            if(num==0){
                //initalize value to 0 using calloc
                contents = calloc(1, sizeof(char));
            }
            else{
                //keep adding more as the strings increase
                contents = realloc(contents, sizeof(char*)*(num+1));
            }
            fgets(contents+num, 2, fptr); //read strings after newline
            //contents+num is used so fgets reads next line of text and stores $
            num++; //add 1 for next line
        }
        //after reading file, subtract 1 since last character in contents is \0
        num = num - 1;
        return contents;
    }
}

