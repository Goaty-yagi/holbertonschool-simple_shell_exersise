#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void diff_path(void)
{
    char *args[] = {"/usr/bin/printenv", "PATH", NULL};
    char *envp[] = {"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", NULL};
    printf("SYSTEM\n");
    system("/usr/bin/printenv PATH");
    printf("\nEXECVE\n");
    execve(args[0], args, envp);
}

void diff_order(void)
{
    char *args[] = {"/bin/ls", "-l", NULL};
    char *envp[] = { "LC_COLLATE=C", NULL };
    printf("SYSTEM\n");
    system("ls -l");
    printf("\nEXECVE\n");
    execve(args[0], args, envp);
}
