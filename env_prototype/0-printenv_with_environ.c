#include "main.h"
#include <unistd.h>

// environ:

// is defined in the unistd.h header file.
// is often declared as an external variable.

// extern is a keyword used to declare a variable or a
// function that is defined in another source file or in an external scope.
void printenv_with_environ(void)
{
    extern char **environ;

    while (*environ != NULL)
    {
        printf("%s\n", *environ);
        environ++;
    }
}
