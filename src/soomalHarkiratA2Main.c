#include "../include/soomalHarkiratA2.h"

/*
Main function is used to test various functions implemented for stringMe company
*/

int main(int agrc, char * argv[]){
  
    /* function 1 */
    printf("***** Function 1 *****\n");
    char * contents = readFile(argv[1]);         
    printf("Contents of %s:\n%s", argv[1], contents);
    free(contents);
    printf("\n\n");

    /* function 2 */
    printf("***** Function 2 *****\n");
    char str[] = "The red readymade dress was made for you! It was going to be ready tomorrow. What was the colour of the dress? Oh, it was red!";
    int numWords, numSentences;
    //call the dejaVu function to count the number of words and sentences
    dejaVu(str, &numWords, &numSentences);
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
        return 1;
    }
    //remove the trailing newline character from the input string
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    if (len > 0 && string[len-1] == '\n') {
        string[len-1] = '\0';
    }
    //call the goBig function to create the stretched string
    char * stretched = goBig(string);
    //print the stretched string
    printf("Stretched string: %s\n", stretched);
    //free the memory allocated for the stretched string
    free(stretched);
    printf("\n");

    /* function 4 */
    printf("***** Function 4 *****\n");
    char str4[] = "This is a sample string , with some punctuation! And new\nlines.";
    int numWords4 = 0;
    char ** words = goAway(str4, &numWords4);
    if (words == NULL) {
        printf("Error: Failed to split string into words.\n");
        return 1;
    }
    printf("The string has %d words:\n", numWords4);
    for (int i = 0; i < numWords4; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
    //free memory
    for (int i = 0; i < numWords4; i++) {
        free(words[i]);
    }
    free(words);
    printf("\n");

    /* function 5 */
    printf("***** Function 5 *****\n");
    char input[] = "What was the colour of the dress? Oh, it was red!";
    printf("Before: %s\n", input);
    breathless(input);
    printf("After: %s\n", input);
    printf("\n");

    /* function 6 */
    printf("***** Function 6 *****\n");
    char *aString = "Now is the winter of our discontent Made glorious summer by this Sun of York.";
    int whichWord = 8;
    char *desiredSuffix = "otter";
    tail(aString, whichWord, desiredSuffix);

    printf("\n");

    return 0;
}
