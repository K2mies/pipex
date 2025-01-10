/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_simulation03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:30 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 12:57:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//creates a named pip file called myfifo01 and gives it full permissions (cmhod 0777).
	if(mkfifo("myfifo01", 0777) == -1)
	{
		if (errno != EEXIST)
		printf("Could not create fifo file.\n");
		return (1);
	}



	return (0);
}
