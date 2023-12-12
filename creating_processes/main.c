#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    // pid_t my_pid;
    // pid_t pid;

    // printf("Before fork\n");
    // pid = fork();
    // if (pid == -1)
    // {
    //     perror("Error:");
    //     return (1);
    // }
    // printf("After fork\n");
    // my_pid = getpid();
    // printf("My pid is %u\n", my_pid);
    // return (0);

    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    if (child_pid == 0)
    {
        printf("(%u) This is a proccess from fork!\n", my_pid);
    }
    else
    {
        printf("(%u) This is a parent process.\n", my_pid);
        printf("(%u) %u is a child PID returned from fork.\n", child_pid, child_pid);
    }
    return (0);
}
