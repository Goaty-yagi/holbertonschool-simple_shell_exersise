#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
    /*
    *** START 0-print_av function ***

    (void)ac;
    print_av(av);

    *** END 0-print_av function ***
    */


    /*
    *** START 1-read_line function

    (void)ac;
    (void)av;
    int length;
    length = read_line();
    printf("printed length:%d\n", length);

    *** END 1-read_line function
    */


    // *** START 2-command_line_to_av.c

    char **ar;
    int counter;

    (void)ac;
    (void)av;

    counter = 0;
    ar = command_line_to_av();
    while (*ar)
    {
        printf("%d:%s\n", counter, *ar);
        counter = counter + 1;
        ar++;
    }
    // *** END 2-command_line_to_av.c

    return (0);
}
