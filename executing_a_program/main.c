#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {
    struct dirent *entry;
    DIR *directory = opendir("."); // Open the current directory

    if (directory == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(directory);
    return 0;
}
