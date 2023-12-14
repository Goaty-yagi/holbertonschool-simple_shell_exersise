#include "main.h"
#include <unistd.h>


void env_vs_environ(char **env)
{
    extern char **environ;
    (void)env;
    while (*environ != NULL)
    {
        printf("Environ: %p ", (void *)*environ);
        printf("Env: %p ", (void *)*env);
        if (*env == *environ)
        {
            printf("SAME \n");
        }
        environ++;
        env++;
    }
}
