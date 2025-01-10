/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_simulation01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:44:30 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 18:46:30 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	//create the pipe and check for error.
	int fd[2];
	if (pipe(fd) == -1)
	{
		return (1);
	}
	
	int pid1 = fork(); // here we fork the process.
	//pid = process id.
	if (pid1 < 0)
	{
		//check for error.
		return (2);
	}

	if (pid1 == 0)
	{
		//CHILD PROCESS 1 (ping)--------------------------------------------------------
		dup2(fd[1], 1); //fd[1] is the write end of the pipe. which is replacing STDOUT.
		//dup2(fd[1], STDOUT_FILENO);
		close(fd[0]); // closing the read end of the pipe.
		close(fd[1]); // closing the write end of the pipe.
		execlp("ping", "ping", "-c", "5", "google.com", NULL); // >pint -c 5 google.com.
	}

	int	pid2 = fork(); // here we fork the process again.
	if (pid2 < 0)
	{
		//check for error.
		return (3);
	}

	if (pid2 == 0)
	{
		// CHILD PROCESS 2 (grep.)----------------------------------------------------
		dup2(fd[0], 0); //fd[0] is the read end of the pipe, which is replacing STDIN.
		//dup2(fd[0], STDIN_FILENO);
		close(fd[0]);// closing the read end of the pipe.
		close(fd[1]);// closing the write end of the pipe.
		execlp("grep", "grep", "rtt", NULL);
	}

	//close the parent pipe.
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
