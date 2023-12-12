#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
    // int length;
    // length = read_line();
    // printf("printed length:%d\n", length);

    char **ar;
    int counter;

    counter = 0;
    ar = command_line_to_av();
    while (*ar)
    {
        printf("%d:%s\n",counter, *ar);
        counter = counter + 1;
        ar++;
    }
    return (0);
}
