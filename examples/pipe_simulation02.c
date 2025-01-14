/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_simulation02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:16:25 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/13 10:33:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a pipe is a buffer in memory that you can read or write too. 
// a file description is a key for a file, or where we want to read or write too.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int	fd[2];
	// fd[0] - read
	// fd[1] - write
	if(pipe(fd) == -1)//creates the pipe here
	{
		printf("An error occured with opening the pipe.\n");
		return (1);
	}

	int	id = fork();
	if (id == -1)
	{
		printf("An error occured with fork.\n");
		return (4);
	}
	if (id == 0)
	{
		//Child Process---------------------------
		close(fd[0]);
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		if(write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("an error occured with writing to the pipe.\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		//Parent Process-------------------------
		close(fd[1]);
		int	y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("an error occured with reading from the pipe. \n");
			return (3);
		}
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
