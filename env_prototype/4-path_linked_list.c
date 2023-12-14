#include "main.h"
#include <unistd.h>


list_t *path_linked_list(void)
{
    list_t *head;
    char *delimiter = "/";
    char *token;
    const char *key = "PATH";
    char *PATH;

    PATH = _getenv(key);
    token = strtok(PATH, delimiter);

	
    while (token != NULL)
    {
        add_node_end(&head, token);
        token = strtok(NULL, delimiter);
    }
    return (head);
}
