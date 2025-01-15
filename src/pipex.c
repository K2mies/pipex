/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:08:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/15 15:07:35 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1_process(char **argv, char **envp, int *fd)
{
	//printf("child 1 process entered");
	//(void)envp;
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error();
	//replace stdin with contents of file1.
	dup2(file1, STDIN_FILENO);
	//replace stdout with write end of the pipe.
	dup2(fd[1], STDOUT_FILENO);
	//closing the read end
	close(fd[0]);
	//cmd execution
	cmd_exec(argv[2], envp);
}

void	child_2_process(char **argv, char **envp, int *fd)
{
	//printf("child 2 process entered");
	//(void)envp;
	int	file2;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file2 == -1)
		ft_error();
	//replace stdin with read enf od the pipe.
	dup2(fd[0], STDIN_FILENO);
	//replace stdout with file2.
	dup2(file2, STDOUT_FILENO);
	//close the writing end.
	close(fd[1]);
	cmd_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		//first fork------------------------
		child1 = fork();
		if (child1 == -1)
			ft_error();
		if (child1 == 0)
			child_1_process(argv, envp, fd);
		//second fork-----------------------
		child2 = fork();
		if (child2 == -1)
			ft_error();
		if (child2 == 0)
			child_2_process(argv, envp, fd);
		//close the parent------------------
		close(fd[0]);
		close(fd[1]);
		//wait for child porcesses----------
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
	}
	else
		ft_error();
		
}
