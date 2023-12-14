#include "main.h"

int main(int ac, char **av, char **env)
{
    char *en;
    list_t *head;
    extern char **environ;
    int i;

    (void)ac;
    (void)av;
    (void)env;
    (void)en;
    (void)head;
    (void)i;

    // printenv_with_environ();
    // env_vs_environ(env);

    // ** 2-getenf **
    // en = _getenv("PATH");
    // printf("%s\n", en);

    // ** 3-print-dirs-path **
    // print_dirs_path();

    // ** 4-path_linked_list **
    // head = path_linked_list();
    // print_list(head);

    // ** 5-setenv **
    _setenv("MY_VARIABLE", "value1", 1); // Add or modify MY_VARIABLE
    _setenv("ANOTHER_VARIABLE", "value2", 0); // Add ANOTHER_VARIABLE if not exists
    _setenv("MY_VARIABLE", "new_value", 1); // Don't overwrite MY_VARIABLE
    // Print the modified environment
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
    return (0);
}
