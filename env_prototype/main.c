#include "main.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    // printenv_with_environ();
    env_vs_environ(env);
    return (0);
}
