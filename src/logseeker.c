#include <stdio.h>
#include <string.h>
#include <regex.h>

//Title:Vec, Author: https://github.com/rxi <https://github.com/rxi/vec>
#include "vec.h"
#include "vec.c"


void FindWord(char *word, char *file)
{
    char line[1024];
    FILE *fp = fopen(file, "r");
    while (fgets(line, sizeof(line), fp) != NULL){
        if (strstr(line, word) != NULL){
            printf("%s", line);
        }
    }
}

void FindWordRegEx(char *regeex, char *file)
{
    regex_t regexCompiled;
    char line[1024];

    if (regcomp(&regexCompiled, regeex, REG_EXTENDED)) {
        printf("Could not compile regular expression.\n");
    };

    FILE *fp = fopen(file, "r");
    while (fgets(line, sizeof(line), fp) != NULL){
        if (regexec(&regexCompiled, line, 0, NULL, 0) == 0){
            printf("%s", line);
        }
    }

}

void display_errors(vec_str_t errors)
{
    int i;
    for (i = 0; i < errors.length; i++) {
        printf("%s", errors.data[i]);
    }
}

int main(int argc, char *argv[])
{
    char * fileLocation;
    char * searchWord;
    char * regexWord;
    int isRegex = 0;
    int i;
    for (i = 0; i < argc; ++i)
    {
        if (strcmp("-f", argv[i]) == 0){
            fileLocation = argv[i + 1];
        }
        if (strcmp("-s", argv[i]) == 0){
            searchWord = argv[i + 1];
        }
        if (strcmp("-r", argv[i]) == 0)
        {
            isRegex = 1;
            regexWord = argv[i + 1];
        }
    }

    vec_str_t errors;
    vec_init(&errors);

    if (NULL == searchWord && strlen(regexWord) == 0)
    {
        vec_push(&errors, "Error: -s [search word] is not specified");
    }
    if (NULL == fileLocation){
        vec_push(&errors, "Error: -f [file] is not specified");
    }

    if (errors.length > 0){
        display_errors(errors);
        vec_deinit(&errors);
        return (0);
    }

    if (isRegex == 1) {
        FindWordRegEx(regexWord, fileLocation);
    } else {
        FindWord(searchWord, fileLocation);
    }

    return (0);
}