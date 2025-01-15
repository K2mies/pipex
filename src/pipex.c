/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:08:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/15 13:40:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Child process that creates a fork and a pipe. Then puts the output inside a pipe
* and then closes with the exec function: the main process will change its stdin
* for the pipe file descriptor
*/

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		cmd_exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
/*Function to make a child process that will read from the strin with
*get next line untill it finds the limiter word and then puts the output inside
*a pipe. The main process will change its stdin for the pipe file descriptor.
*/

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		ft_error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);//closing read end of the pipe.
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			write(fd[1], line, ft_strlen(line));
		}
		close(fd[1]);//!!
		free(line);
	}
	else
	{
		close(fd[1]);//closing write end of the pipe
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);//!!
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{

	int		i;
	int		filein;
	int		fileout;

	if (argc >= 5)
	{
		//check for here_doc input
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc -1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;	
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
		{
			child_process(argv[i++], envp);
			dup2(fileout, STDOUT_FILENO);
			cmd_exec(argv[argc - 2], envp);
		}
		close(filein);
		close(fileout);
	}
	usage();	
}
