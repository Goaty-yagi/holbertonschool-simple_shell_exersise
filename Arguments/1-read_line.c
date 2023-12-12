#include <stdio.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 100
/**
 * read_line - call read_line
 *
 * Return: the number of characters written, excluding the terminating NUL character.The value -1 is returned if an error occurs, or if end-of-file is reached.
 */

int read_line(void)
{
    char command[MAX_COMMAND_LENGTH];

    // Print "$ " and wait for user input
    printf("$ ");

    // Read the command entered by the user
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
    {
        // Print the entered command on the next line
        printf("Entered command: %s", command);
        return (strlen(command) - 1);
    }
    return (-1);
}
