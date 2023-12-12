#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-la", "../arguments", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    // in this case, execve call the ls command with -la flags in ../arguments dir.
    {
        perror("Error:");
    }
    printf("After execve\n"); // this system will be overwritten.
    return (0);
}
