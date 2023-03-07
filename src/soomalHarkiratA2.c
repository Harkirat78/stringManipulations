/*
this program is made for a company called stringMe and there are six functions
that can be used for many specific things prodominantly as a library of string functions for the company
*/
#include "../include/soomalHarkiratA2.h"
/*
function 1
This function takes a filename of a text file as input, opens and reads the contents of the
file and returns the contents as a string (char *)

Function name: readFile
Inputs: string pointer
Returns: char *
*/
char * readFile(char * filename){

    FILE * fptr; //file pointer that points to file
    char * contents; //string pointer hold contents of file points to first element
    int num = 0; //count number of words in string

    fptr = fopen(filename, "r"); //open the file for reading
    //check if file is empty, if so return NULL
    if(fptr==NULL){
        printf("Error opening the file\n");
        return NULL;
    }
    else{ 
        //loop will iterate till the file is fully read
        while(!feof(fptr)){
            //check if num is 0 which indicates whether the dynamic string has been initialized or not
            if(num==0){
                //initalize value to 0 using calloc, memory has been allocated on the heap for only 1 char value
                contents = calloc(1, sizeof(char)); //allocate for only 1 char so 1 bye has been allocated
            }
            //if num is not 0 then the dynamic string has been initialized and this condition only occurs if there is more than 1 char in the file
            else{
                //use realloc to resize the previously allocated block of memory to a larger size to allow more bytes
                contents = realloc(contents, sizeof(char*)*(num+1)); //multiplying by (num+1) gives total size of memory needed to store the file contents including the \0
            }
            fgets(contents+num, 2, fptr); //read strings after newline
            //contents+num is used so fgets reads next line of text and stores it in the num value position of contents
            num++; //increment to keep track of characters read so far
        }
        //after reading file, subtract 1 since last character in contents is \0
        num = num - 1;
        return contents; //return dynamic string
    }
}
/*
function 2
This function takes a string as input, and outputs the number of words and number of
sentences in it. A word is any sequence of characters delimited by white space or the
end of a sentence, whether or not it is an actual English word. A sentence is a group of
words terminated by a period, colon, semicolon, question mark, or exclamation mark

Function name: dejaVu
Input: string pointer, two int pointers
Returns: void
*/
void dejaVu(char *aString, int *numWords, int *numSentences){

    int numChars = 0; //keeps track of number of chars in the current word that are being proccessed
    //initialize both to 0 to ensure file read from beginning
    *numWords = 0; 
    *numSentences = 0;

    //loop will run till the string ends
    for (int i = 0; aString[i] != '\0'; i++){
        char current = aString[i]; //char variable willused to store the current char value within string
        numChars++; //increment the number of characters

        //check for end of the sentence which can be a those punctuations
        if (current == '.' || current == ':' || current == ';' || current == '?' || current == '!'){
            (*numSentences)++; //add 1 to the number of sentences
        }
        //check for whitespace
        if (current == ' ' || current == '\t' || current == '\n' || current == '\r'){
            //if there are non-space characters before this whitespace, it's the end of a word
            if (numChars > 1){
                (*numWords)++; //add 1 to the number of words in string
            }
            //reset the number of characters
            numChars = 0;
        }
    }
    //if there are non-space characters after the last whitespace, it's the end of a word
    if (numChars > 0){
        (*numWords)++; //add 1 to the number of words in string
    }
}
/*
function 3
This function takes a string as its only parameter. It prompts the user to enter exactly n
valid positive integers, where n is the length of aString. Entering a 0 or negative is
considered invalid. The function then creates a new string that consists of the letters in
aString (in the same order) – each letter repeated by the number of times indicated by
the user for that corresponding position

Function name: goBig
Inputs: string pointer
Returns: char *
*/
char * goBig(char * aString){
    
    //determine the length of the input string
    int length = strlen(aString)-1; //subtract 1 for the NULL character
    //allocate memory for the stretched string (initially empty)
    char * stretched = calloc(1, sizeof(char)); //allocate for only 1 byte

    stretched[0] = '\0'; //initialize first element to the null character, equivalent to an empty string

    //prompt the user for a number of valid positive integers, where num is the length of aString
    printf("Enter %d positive integers separated by spaces: ", length);
   
    //loop will iterate for the length of the string provided
    for (int i = 0; i < length; i++){
        int num = 0;
        //keep asking for input until a positive integer is provided
        int validInput = 0; //variable to check if input is valid or invalid(<=0)
        //loop will iterate till input is >0
        while (validInput==0){
            scanf("%d", &num); 
            //check if the input is a valid positive integer
            if (num > 0){
                validInput = 1;
            }
            //display an invalid input message
            else{
                printf("Invalid input. Please enter a positive integer.\n");
            }
        }
        //reallocate memory for the stretched string to accommodate the new letters
        stretched = realloc(stretched, sizeof(char) * (strlen(stretched) + num + 1)); //num+1 is added as num represents amount each string in original aString must be repeated

        //append the letters from aString to the stretched string, each repeated num times
        for (int j = 0; j < num; j++){
            strncat(stretched, &aString[i], 1); //function will append a single character from aString to end of strecthed string one at a time
        }
    }
    return stretched; //return the newly formed dynamic string 
}
/*
function 4
This function takes a string aString, splits it into n words, stores the words in a
dynamic 2D array and returns it. The function also outputs the total number of words
stored in the given input aString.

Function name: goAway
Inputs: string pointer, int pointer
Returns: char **
*/
char ** goAway (char * aString, int * numWordsReturned){

   char ** wordAmount; //this char pointer points to an array of strings that have words in the input strings
   int length; //pointer to number of words found in input string set as 0
   *numWordsReturned = 0; //variable used to store length of each word being processed

   //loop will iterate through every character in given input string
   for(int i = 0; i < strlen(aString); i++){
       //check if curret character is a space or newline
       if(aString[i] == '\n' || aString[i] == ' ' || i == strlen(aString)-1){
           //check if there are any consecutive spaces or newlines and if true go back to outer if statement
           if(aString[i-1] == '\n' || aString[i-1] == ' '){
           }
           else{
               //allocate memory for words array based on number of words found
               if(*numWordsReturned == 0){
                   wordAmount = calloc(1, sizeof(char*)); //initiallize words to 1 single char
               }
               //if words returned is not 0 reallocate enough new memory
               else {
                   wordAmount = realloc(wordAmount, sizeof(char*)*(*numWordsReturned+1)); //reallocate for 2d string
               }
               length = 0; //set length back to 0 because the word has been fully comprehended

               //iterate over the characters of the string, starting from i - 1 and moving backwards until the beginning of the string (index 0)
               for (int j = i - 1; j >= 0; j--) {
                    //if the current character is a space or a newline character, it means we have reached the beginning of the word
                    if (aString[j] == ' ' || aString[j] == '\n') {
                        //we break out of the loop because we have found the beginning of the word
                        break;
                    } else {
                        //if the current character is not a space or a newline character, we increment the length of the word
                        length++;
                    }
                }
                //if the current character is the end of the string, add one more character to length.
                if(i == strlen(aString)-1){ 
                    length++;
                }
                //allocate memory for the current word and add it to the words array
                wordAmount[*numWordsReturned] = calloc(length, sizeof(char)); 

                //loop will iterate for total length
                for(int j = 0; j < length; j++){ 
                    //check if index is the same
                    if(i == strlen(aString)-1){ //check if the current character is the last character of the input string
                        wordAmount[*numWordsReturned][length-j-1] = aString[i-j]; //copy the current character to the last position of the allocated memory block
                    }
                    else{
                        wordAmount[*numWordsReturned][length-j-1] = aString[i-j-1]; //copy the current character to the current position in the allocated memory block
                    }
                }
                *numWordsReturned = *numWordsReturned + 1; //increment the number of words found
            }
        }
    }
    return wordAmount; //return the array of words
}
/*
function 5
This function takes a string aString, finds all punctuations in the given string and
removes them from aString. The function returns the string with punctuation removed.
For this function pointer arithmetic is utilized.

Function name: breathless 
Inputs: string pointer
Returns: char *
*/
char * breathless(char * aString){

    //initialize two pointers p and q to point at beginning of the input string
    char * p = aString; //iterate over all characters in the string
    char * q = aString; //will be used to point to modified version of string that lacks punctuations
    
    //loop will iterate till end of string
    while (*p != '\0'){
        //check for all non-punctuations in the input string and make q point to p if true
        if (*p != '.' && *p != ':' && *p != ';' && *p != '?' && *p != '!'){
            *q = *p; //the pointer q points to current positon in output string where the next non-puncuation character is copied
            q++; //point to next position
        }
        //if current char is a punctuation character do not copy it to the output string
        p++; //change position of pointer
    }
    *q = '\0'; //terminate the output string with a null character
    return aString; //return the newly modifiied input string
}
/*
function 6
This function takes a string as a parameter, finds the word given in position whichWord
and prints n number of words on the standard output, where n is the length of the word
at position whichWord. Each word printed on the screen starts with a letter in the word at
position whichWord and is suffixed by desiredSuffix.

Function name: tail
Inputs: 2 string pointers, int
Returns: void
*/
void tail(char * aString, int whichWord, char * desiredSuffix){

    int wordCount = 1; //variable will be a counter for the current word, start at 1 since first word doesnt need space at beginning
    char *p = aString; //pointer to beginning of string
    char *start = NULL; //pointer to the start of the current word

    //loop will iterate till end of string and examine each char 
    while (*p != '\0'){
        //check if current char is a space or period
        if (*p == ' ' || *p == '.'){
            wordCount++; //increment word 
            //if this is the target word that we are searching for, mark the start position
            if (wordCount == whichWord){
                start = p + 1; //point to first char of that word
            }
            //if word is before target word, calculate the length of the target and add the desired suffix
            else if (wordCount == whichWord + 1){
                //computer length of target word
                int wordLen; //will calculate length of target word
                if (*(p-1) == '.'){ //if last character is a period, subtract 1 from word length
                    wordLen = p - start - 1; //subtract the two pointers to get length since p points to the end and start points to first character
                }
                else {
                    wordLen = p - start; //subtract the two pointers to get length since p points to the end and start points to first character
                }
                //iterate through each character in the target word
                for (int i = 0; i < wordLen; i++){
                    //putchar function is used to output each character of target word and is easier to use than mutliple printf
                    putchar(*start);
                    start++; //move to next position
                    //iterates length of inputted desiredSuffix times and outputs the desired suffix after the target word
                    for (int j = 0; j < strlen(desiredSuffix); j++){
                        putchar(desiredSuffix[j]);
                    }
                    putchar('\n'); //output a newline after each word for each letter of that word
                }
                return; //exit the function after modifying and outputting the target word
            }
        }
        p++; //move pointer to next char in the string
    }
}

