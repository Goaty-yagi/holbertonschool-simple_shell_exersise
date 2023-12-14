#include "main.h"

int _setenv(const char *name, const char *value, int overwrite) {
    extern char **environ;
    int i, counter;
    int name_len;
    char *new_env;
    char *new_env2;
    int env_count;
    char **new_environ;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        // Invalid name: null pointer, empty string, or contains '='
        return (-1);
    }

    counter = 0;
    // Check if the variable already exists
    name_len = strlen(name);
    for (i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=') {
            if (overwrite == 0) {
                // Variable exists and overwrite is disabled
                return 0;
            } else {
                // Variable exists, overwrite is enabled - update its value
                new_env = malloc(name_len + strlen(value) + 2); // +2 for '=' and '\0'
                if (new_env == NULL) {
                    return -1; // Memory allocation error
                }
                sprintf(new_env, "%s=%s", name, value);
                free(environ[i]); // Free the old value
                environ[i] = new_env; // Set the new value
                return 0;
            }
        }
    }

    // Variable doesn't exist, create a new one
    new_env2 = malloc(name_len + strlen(value) + 2); // +2 for '=' and '\0'
    if (new_env2 == NULL) {
        return -1; // Memory allocation error
    }
    sprintf(new_env2, "%s=%s", name, value);
    // format a string and store the resulting formatted string into a character array
    // ex) name:value 

    // Count the number of existing environment variables
    env_count = 0;
    while (environ[env_count] != NULL) {
        env_count++;
    }

    // Allocate memory for the new environment with an additional entry for the new variable
    new_environ = malloc((env_count + 2) * sizeof(char *));
    if (new_environ == NULL) {
        free(new_env2);
        return (-1); // Memory allocation error
    }

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

    return 0;
}
