#include <stdio.h>
#include <string.h>
#include <regex.h>


void FindWord(char *word, char *file)
{
    char line[1024];
    FILE *fp = fopen(file, "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, word) != NULL)
        {
            printf("%s", line);
        }
    }
}

void FindWordRegEx(char *regeex, char *file)
{
    regex_t regexCompiled;
    char line[1024];

    if (regcomp(&regexCompiled, regeex, REG_EXTENDED))
    {
        printf("Could not compile regular expression.\n");
    };

    FILE *fp = fopen(file, "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (regexec(&regexCompiled, line, 0, NULL, 0) == 0)
        {
            printf("%s", line);
        }
    }
}