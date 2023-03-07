#include "../include/soomalHarkiratA2.h"

/*
Main function is used to test various functions implemented for stringMe company
*/

int main(int agrc, char * argv[]){
  
    /* function 1 */
    printf("***** Function 1 *****\n");
    char * contents = readFile(argv[1]);         
    printf("Contents of %s:\n%s", argv[1], contents);
    printf("\n\n");

    /* function 2 */
    printf("***** Function 2 *****\n");
    int numWords, numSentences;
    //call the dejaVu function to count the number of words and sentences
    dejaVu(contents, &numWords, &numSentences);
    //print the results
    printf("Number of words = %d\n", numWords);
    printf("Number of sentences = %d\n", numSentences);
    printf("\n");

    /* function 3 */
    printf("***** Function 3 *****\n");
    char string[100];
    //read a string from standard input using fgets()
    printf("Enter a string: ");
    if (fgets(string, sizeof(string), stdin) == NULL) {
        printf("Error: Failed to read input string.\n");
    }
    //call the goBig function to create the stretched string
    char * stretched = goBig(string);
    //print the stretched string
    printf("Stretched string: %s\n", stretched);
    //free the memory allocated for the stretched string
    printf("\n");
    
    /* function 4 */
    printf("***** Function 4 *****\n");
    char str4[] = "Oh , it was red!.";
    int numWordsReturned = 0;
    char ** words = goAway(str4, &numWordsReturned);
    if (words == NULL) {
        printf("Error: Failed to split string into words.\n");
    }
    printf("The string has %d words:\n", numWordsReturned);
    for (int i = 0; i < numWordsReturned; i++) {
        printf("%s ", words[i]);
    }   
    printf("\n\n");
    
    /* function 5 */
    printf("***** Function 5 *****\n");
    char input[] = "What was the colour of the dress? Oh, it was red!";
    printf("Before: %s\n", input);
    char * new = breathless(input);
    printf("After: %s\n", new);
    printf("\n");

    /* function 6 */
    printf("***** Function 6 *****\n");
    char * aString = "Now is the winter of our discontent Made glorious summer by this Sun of York.";
    int whichWord = 15;
    char * desiredSuffix = "otter";
    tail(aString, whichWord, desiredSuffix);
    printf("\n");

    return 0;
}
