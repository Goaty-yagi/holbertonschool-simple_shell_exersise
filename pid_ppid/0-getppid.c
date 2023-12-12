#include <stdio.h>
#include <unistd.h>

/**
 * _getppid - call _getppid
 *
 * Return: void.
 */
void _getppid(void)
{
    pid_t my_pid, my_pid2;

    my_pid = getppid();
    my_pid2 = getpid();
    printf("PPID:%u\n", my_pid);
    printf("PID:%u\n", my_pid2);
}
