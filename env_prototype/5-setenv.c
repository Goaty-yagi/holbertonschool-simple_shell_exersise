#include "main.h"

/**
 * _setenv - call _setenv
 * @name: key
 * @value: value
 * @overwrite: 1 means override while 0 doesn't.
 *
 * description: the same as setenv function. the idea is that make key-value paire as a string from the arguments
 * by sprintf, then set it to original environ to update, or append it to a new_environ variable copied all pointer of
 * current env, and reassign it to the original environ.
 *
 * Return: 0 success while -1 error.
 */

// strncmp compare two strings until number of char
// strncmp(char *str1, char *str2, int i)

// sprintf
// format a string and store the resulting formatted string into a character array
// ex) name:value
int _setenv(const char *name, const char *value, int overwrite)
{
    extern char **environ;
    int counter;
    int name_len;
    char *new_env;
    char *new_env2;
    int env_count;
    char **new_environ;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        // Invalid name: null pointer, empty string, or contains '='
        return (-1);
    }

    counter = 0;
    name_len = strlen(name);
    // Check if the variable already exists
    while (environ[counter] != NULL)
    {
        if (strncmp(environ[counter], name, name_len) == 0 && environ[counter][name_len] == '=')
        {
            if (overwrite == 0)
            {
                // Variable exists and overwrite is disabled
                return (0);
            }
            else
            {
                // Variable exists, overwrite is enabled - update its value
                new_env = malloc(name_len + strlen(value) + 2); // + 2 for '=' and '\0'
                if (new_env == NULL)
                {
                    return (-1);
                }
                sprintf(new_env, "%s=%s", name, value);
                free(environ[counter]);     // Free the old value
                environ[counter] = new_env; // Set the new value
                return (0);
            }
        }
        counter = counter + 1;
    }

    // Variable doesn't exist, create a new one
    new_env2 = malloc(name_len + strlen(value) + 2); // +2 for '=' and '\0'
    if (new_env2 == NULL)
    {
        return (-1);
    }
    sprintf(new_env2, "%s=%s", name, value);

    // Count the number of existing environment variables
    env_count = 0;
    while (environ[env_count] != NULL)
    {
        env_count++;
    }

    // Allocate memory for the new environment with an additional entry for the new variable
    new_environ = malloc((env_count + 2) * sizeof(char *));
    if (new_environ == NULL)
    {
        free(new_env2);
        return (-1); // Memory allocation error
    }
    counter = 0;
    // Copy existing environment to the new one
    while (counter < env_count)
    {
        new_environ[counter] = environ[counter];
        counter = counter + 1;
    }

    // Add the new variable to the end
    new_environ[env_count] = new_env2;
    new_environ[env_count + 1] = NULL;

    // Update the environ pointer to the new environment
    environ = new_environ;

    return (0);
}
