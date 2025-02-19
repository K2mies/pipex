/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:02:10 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/16 10:56:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

char	*set_paths(char *command, char **mypaths)
{
	bool	it_works;
	char	*fullpath;
	char	*onepath;
	int		i;

	i = 0;
	it_works = false;
	while (mypaths[i])
	{
		onepath = ft_strjoin(mypaths[i], "/");
		fullpath = ft_strjoin(onepath, command);
		free(onepath);
		if (access(fullpath, F_OK) == 0)
		{
			it_works = true;
			break ;
		}
		else
			free(fullpath);
		i++;
	}	
	free_array(mypaths);
	if (it_works)
		return (fullpath);
	return (NULL);
}

char	*path_parsing(char *command, char **envp)
{
	char	**mypaths;
	char	*fullpath;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	fullpath = set_paths(command, mypaths);
	return (fullpath);
}

void	cmd_exec(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	path = path_parsing(command[0], envp);
	if (!path)
	{
		free_array(command);
		ft_error();
	}
	if (execve(path, command, envp) == -1)
	{
		free_array(command);
		free(path);
		ft_error();
	}
	free_array(command);
	free(path);
}
