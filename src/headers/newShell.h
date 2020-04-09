#ifndef H_NEWSHELL
#define H_NEWSHELL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <signal.h>
#include "read.h"
#include "parse.h"
#include "execute.h"


typedef struct read_data_s
{
    int readStatus;
    char *line;
    size_t len;
} read_data_t;

typedef struct parse_data_s
{
    int ac;
    char **av;

} parse_data_t;

typedef struct execute_data_s
{
    int execveCode;
    int returnCode;
    int statusCode;
} execute_data_t;

typedef struct data_s
{
    int argc;
    char **argv;
    char **env;
    bool interactive;
    read_data_t readData;
    parse_data_t parseData;
    execute_data_t executeData;
} data_t;

extern data_t shellData;



void setMode();
void prompt();

#endif /* H_NEWSHELL */