#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100

/**
 * main - fork - wait - execve
 *
 * Return: Always 0.
 */
int main(void)
{
    char **argv;
    char command[MAX_COMMAND_LENGTH];
    pid_t child_pid;
    // pid_t my_pid;
    // pid_t my_ppid;
    int status, counter;

    counter = 0;
    argv = malloc(2 * sizeof(char *));
    // my_ppid = getppid();
    // printf("(%d) PPID\n", my_ppid);
    if (argv == NULL)
    {
        perror("Memory allocation error");
        return (1);
    }

    while (1)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            free(argv);
            return (1);
        }
        // my_pid = getpid();
        // my_ppid = getppid();
        if (child_pid == 0)
        {
            // printf("My pid is %u\n", my_pid);
            // printf("My ppid is %u\n", my_ppid);
            printf("cisfun$ ");
            if (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
            {
                // Remove newline character from command
                command[strlen(command) - 1] = '\0';

                // Set up the argument array
                argv[0] = command; // Command is the first argument
                argv[1] = NULL;    // Ensure the array is properly terminated with NULL

                // Execute the command
                if (execvp(argv[0], argv) == -1)
                {
                    // wait(&status);
                    perror("Error_DESU");
                    return (1);
                }
            }
            else
            {
                return (1);
            }
        }
        else
        {
            // printf("Not child_pid == 0");
            wait(&status);
        }
        counter = counter + 1;
    }

    return (0);
}
