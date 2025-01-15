/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:35:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/15 11:09:50 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdbool.h> 

#include "../ft_printf/include/libft.h"

//Error----------------------
void	ft_error(void);
void	usage(void);
//parsing-------------------
int		get_next_line(char **line);
void	cmd_exec(char *argv, char **envp);
int		open_file(char *argv, int i);

#endif
