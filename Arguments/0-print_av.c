#include <stdio.h>
#include "main.h"
/**
 * print_av - call print_av
 *
 * description:  prints all the arguments, without using ac.
 * Return: void
 */

void print_av(char **av)
{

    while(*av)
    {
        printf("%s\n", *av);
        av++;
    }
}
