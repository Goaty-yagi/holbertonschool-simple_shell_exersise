#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

void file_info_ex(int ac, char **av);
int file_info_exercise(int ac, char **av);
void opendir_readdir(void);
char **get_dir(char *path);

#endif
