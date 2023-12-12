#include <stdio.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 100
/**
 * command_line_to_av - call command_line_to_av
 *
 * Return: an array of each word of the string.
 */

char **command_line_to_av(void)
{
    char command[MAX_COMMAND_LENGTH];
    char *token, *temp;
    char **st_array;
    int counter;

    counter = 0;
    st_array = malloc(sizeof(8));
    // Print "$ " and wait for user input
    printf("$ ");

    // Read the command entered by the user
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
    {
        command[strlen(command) - 1] = '\0';
        token = strtok(command, " ");
        while (token != NULL)
        {
            temp = token;
            st_array[counter] = malloc(sizeof(temp));
            st_array[counter] = temp;
            token = strtok(NULL, " ");
            counter = counter + 1;
        }
        st_array[counter] = malloc(8);
        st_array[counter] = NULL;
        return (st_array);
    }
    else 
    {
        return (st_array);
    }
}
