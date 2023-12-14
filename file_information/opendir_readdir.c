#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_FILENAME_LEN 256 // Maximum length of a filename

// opendir provides a way to access the contents of a directory return pointer of type DIR

// readdir read the next directory entry from a directory stream obtained by opening a directory using opendir
// readdir refers to each individual file, subdirectory, or other items within a directory.
// return pointer of type dirent

int opendir_readdir(void)
{
    struct dirent *entry;
    DIR *dp;
    int counter;

    counter = 1;

    dp = opendir("."); // Open current directory

    if (dp == NULL)
    {
        perror("Error opening directory");
        return (1);
    }

    while ((entry = readdir(dp)) != NULL)
    {
        printf("%u: %s\n",counter, entry->d_name);
        counter = counter + 1;

    }

    closedir(dp);
    return 0;
}
