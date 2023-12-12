#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */

/*
    Child process may terminate due to any of these:

    It calls exit();
    It returns(an int) from main
    It receives a signal(from the OS or another process) whose default action is to terminate.
*/
int main(void)
{
    pid_t child_pid, return_pid, my_pid;
    int status;

    printf("The wait function returns %d because no child process.\n",wait(&status));
    // -1
    
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    if (child_pid == 0)
    {
        printf("(%d) Child process first!\n", my_pid);
        sleep(3);
    }
    else
    {
        return_pid = wait(&status);
        printf("(%d) Parent process waitng until child process ends.\n", my_pid);
        printf("STATUS:%d\n", status);
        printf("Child PID (%d) returned from the wait function\n", return_pid);
    }
    return (0);
}
