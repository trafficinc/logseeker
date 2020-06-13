#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "logseeker.h"
#include "vec.h"


#define VERSION "1.1"

static struct option long_opts[] = {
        {"log_path",     required_argument, NULL, 'f'},
        {"word_search",  required_argument, NULL, 's'},
        {"regex_search", required_argument, NULL, 'r'},
        {"help",         no_argument,       NULL, 'h'},
        {"version",      no_argument,       NULL, 'v'},
        {NULL,           0,                 NULL, 0}
};

static void usage() {
    printf("Usage: logseeker <options>                             \n"
           "  Options:                                             \n"
           "    -f          <F>  Log file to scan                  \n"
           "    -s          <S>  Search with Word                  \n"
           "    -- OR --                                           \n"
           "    -r          <R>  Search with Regex                 \n"
           "                                                       \n"
           "    -v          Print version details                  \n"
           "    -h          Usage                                  \n"
           "                                                       \n"
           "                                                       \n"
           "                                                       \n");
}

void display_errors(vec_str_t errors) {
    int i;
    for (i = 0; i < errors.length; i++) {
        printf("%s", errors.data[i]);
    }
}

int main(int argc, char *argv[]) {
    char *fileLocation;
    char *searchWord;
    char *regexWord;
    int isRegex = 0;

    int c;
    while ((c = getopt_long(argc, argv, "f:s:r:vh?", long_opts, NULL)) != -1) {
        switch (c) {
            case 'f':
                fileLocation = optarg;
                break;
            case 's':
                searchWord = optarg;
                break;
            case 'r':
                isRegex = 1;
                regexWord = optarg;
                break;
            case 'v':
                printf("logseeker v%s\n", VERSION);
                printf("Copyright (C) 2019 Ronnie Bailey\n");
                exit(1);
                break;
            case 'h':
                usage();
                exit(1);
                break;
            default:
                return -1;
        }
    }

    vec_str_t errors;
    vec_init(&errors);

    if (NULL == searchWord && strlen(regexWord) == 0) {
        vec_push(&errors, "Error: -s [search word] is not specified");
    }
    if (NULL == fileLocation) {
        vec_push(&errors, "Error: -f [file] is not specified");
    }

    if (errors.length > 0) {
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