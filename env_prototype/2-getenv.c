#include "main.h"
#include <unistd.h>


char *_getenv(const char *name)
{
    char *delimiter = "=";
    extern char **environ;
    char *token;

    while (*environ != NULL)
    {
        token = strtok(*environ, delimiter);
        if (strcmp(token, name) == 0)
        {
            token = strtok(NULL, delimiter);
            return (token);
        }
        environ++;
        token = strtok(NULL, delimiter);
    }
    return ("(nul)");
    
}
