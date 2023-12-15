#include "main.h"

/**
 * _setenv - call _setenv
 * @name: key

 * Return: 0 success while -1 error
 */

int _unsetenv(const char *name)
{
    extern char **environ;
    int counter;
    int name_len;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        // Invalid name: null pointer, empty string, or contains '='
        return (-1);
    }

    counter = 0;
    name_len = strlen(name);

    while (environ[counter] != NULL)
    {
        if (strncmp(environ[counter], name, name_len) == 0 && environ[counter][name_len] == '=')
        {

            free(environ[counter]);
            return (0);
        }
        counter = counter + 1;
    }
    return (-1);
}
