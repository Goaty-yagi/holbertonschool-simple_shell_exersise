#include "main.h"
#include <dirent.h>

char **get_dir(char *path)
{
    struct dirent *entry;
    DIR *dp;
    int counter;
    char **ap;

    if (!path)
    {
        printf("Error path");
        exit(0);
    }
    counter = 0;
    ap = malloc(100);
    if (ap == NULL)
    {
        exit(0);
    }
    dp = opendir(path);

    if (dp == NULL)
    {
        free(ap);
        perror("Error opening directory");
        exit(0);
    }

    while ((entry = readdir(dp)) != NULL)
    {
        ap[counter] = entry->d_name;
        counter = counter + 1;
    }
    ap[counter + 1] = NULL;
    closedir(dp);
    return (ap);
}
