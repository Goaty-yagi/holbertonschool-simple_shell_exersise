#include "main.h"

#define MAX_FILENAME_LEN 256 // Maximum length of a filename

// opendir provides a way to access the contents of a directory return pointer of type DIR

int file_info_exercise(int ac, char **av)
{
    int counter, ap_counter, found;
    char **ap;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
    }
    counter = 1;
    ap_counter = found = 0;
    ap = get_dir(".");
    while (counter < ac)
    {
        while (ap[ap_counter])
        {
            if (strcmp(av[counter], ap[ap_counter]) == 0)
            {
                printf("%s is found in PWD\n", av[counter]);
                found = 1;
            }

            ap_counter = ap_counter + 1;
        }
        ap_counter = 0;
        if (!found)
        {
            printf("%s is not found in PWD\n", av[counter]);
        }
        found = 0;
        counter = counter + 1;
    }
    return (0);
}
