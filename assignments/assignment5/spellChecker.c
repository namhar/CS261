/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: Farrukh Rahman
 * Date: 3/12/17
 */

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char *currentWord;
    while ((currentWord = nextWord(file))){
        if (currentWord !=NULL){
        hashMapPut(map,currentWord,1);
        }
    }
}

// the levenshtein distance was taken from https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}




/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }

        int foundWord = 0;
        struct HashLink* temp;
        int distance, next = 0;
 

        for (int i = 0; i < map->capacity && foundWord == 0; i++){
            temp = map->table[i];
            while (temp != NULL){
                if (strcmp(temp->key,inputBuffer) == 0){
                    printf("word spelled correctly\n");
                    foundWord = 1;
                }
                else{
                    distance = levenshtein(temp->key,inputBuffer);
                    temp->value = distance;

                }  
                next = 0;
                temp = temp->next;
                
            }
        }

        if (foundWord == 0){
            int lowest[5] = {1000,1000,1000,1000,1000};
            char *sug[5];

            for (int i = 0; i < map->capacity && foundWord == 0; i++){
                temp = map->table[i];
                
                while (temp != NULL){
                    //printf("%d\n",temp->value); 
                    next = 0;
                    for (int c = 0; c < 5 && next == 0;c++){
                       // printf("test %d", lowest[c]);
                        if ( temp->value < lowest[c]){
                    
                            sug[c] = temp->key;
                            lowest[c] = temp->value;
                          //  printf("word: %s  Distance: %d\n", temp->key, temp->value);
                            next = 1;
                        }
                    }
                    temp = temp->next;
                }  
            }
            
            for (int c = 0; c < 5;c++){

                 printf("did you mean %s ? \n", sug[c]);
            }         
        }
    }
    
    hashMapDelete(map);
    return 0;
}