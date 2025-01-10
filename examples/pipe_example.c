/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:30:06 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 19:08:24 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
*	Executes the command "cat infile | grep Lausanne".
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int		main(int argc, char **argv, char *env[])
{
	(void)argc;
	(void)argv;
	int	pipefd[2];
	int	status;
	int	pid;

	char	*cat_args[] = {"/bin/cat", "in", NULL};
	char	*grep_args[] = {"/usr/bin/grep", "Lausanne", NULL};

	//make a pipe
	// fds go in pipefd[0] (read) and pipefd[1] (write).
	pipe(pipefd);

	//create fork.
	pid = fork();
	if (pid == -1)
	{
		//handle fork error.
		perror("fork");
		exit(1);
	}

	//if (!pid)
	if (pid == 0)
	{
		// child process gets here and handles "grep Lausanne"
		// replace standard input with input part of the pipe.
		dup2(pipefd[0], 0);

		//close unused half of the pipe.
		close(pipefd[1]);

		//execute grep
		printf("child process complete.\n");
		execve("/usr/bin/grep", grep_args, env);
	}
	else 
	{
		//parent process gets here and handles "cat scores"
		// replace standard output with output part of pipe (pipefd[1]).
		dup2(pipefd[1], 1);

		//close unused half of the piipe.
		close(pipefd[0]);

		// execute cat
		printf("parent process complete\n");
		execve("/bin/cat", cat_args, env);
	}
	// close unused piipe.
	close(pipefd[0]);
	close(pipefd[1]);

	//wait for the child process to finish
	waitpid(pid, &status, 0);
}
