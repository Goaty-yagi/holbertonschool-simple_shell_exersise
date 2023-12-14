#include "main.h"
#include <unistd.h>


void *print_dirs_path(void)
{
    char *delimiter = "/";
    char *token;
    const char *key = "PATH";
    char *PATH;

    PATH = _getenv(key);
    token = strtok(PATH, delimiter);
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
    return 0;
}
