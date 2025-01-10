/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_example00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:16:40 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 15:34:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main()
{
	char	*args[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;

	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
	return (0);
}
