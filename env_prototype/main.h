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

typedef struct list_path
{
	char *path_name;
	unsigned int len;
	struct list_path *next;
} list_p;

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
void *print_dirs_path(void);
void printenv_with_environ(void);
void env_vs_environ(char **env);
char *_getenv(const char *name);
list_t *add_node_end(list_t **head, const char *str);
list_t *path_linked_list(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
