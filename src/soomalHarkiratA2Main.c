#include "../include/soomalHarkiratA2.h"

int main(int agrc, char * argv[]){
  
    //function 1
    char * contents = readFile(argv[1]);         
    printf("Contents of %s:\n%s", argv[1], contents);
    free(contents);
    printf("\n");

    return 0;
}


