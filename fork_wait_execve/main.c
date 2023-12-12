#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork - wait - execve
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-la", "/tmp", NULL};
	pid_t my_pid;
	pid_t child_pid;
	pid_t my_ppid;
	int status, counter;

	my_pid = getpid();
	counter = status = 0;
	printf("(%d) PPID\n", my_pid);

	while (counter < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		my_pid = getpid();
		my_ppid = getppid();
		if (child_pid == 0)
		{
			printf("My pid is %u\n", my_pid);
			printf("My ppid is %u\n", my_ppid);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			sleep(2);
			if (WIFEXITED(status))
			{
				printf("Child %d terminated with status: %d\n\n", counter + 1, WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				/*
				A child process can be terminated by a signal due to
				various reasons, such as encountering an error or receiving
				 a signal from the operating system or another process.
				*/
				printf("Child %d terminated by signal %d\n\n", counter + 1, WTERMSIG(status));
			}
		}
		counter = counter + 1;
	}
	return (0);
}
