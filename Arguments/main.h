#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void print_av(char **av);
int read_line(void);
char **command_line_to_av(void);

#endif
