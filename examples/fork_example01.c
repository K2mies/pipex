/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_example01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:57:31 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/13 10:10:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int	id1 = fork();
	int	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("we are process y\n");
		}
		else
		{
			printf("we are process x\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf("we are process z\n");
		}
		else 
		{
			printf("we are the parent process!\n");
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("waited for a child to finish \n");
	}
}
