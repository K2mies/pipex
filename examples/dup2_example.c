/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:39:27 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 18:46:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	int	in;
	int	out;
	char *grep_args[] = {"grep", "Lausanne", NULL};

	// open input and output files (assuming both files exist).
	in = open("in", O_RDONLY);
	out = open("out", O_WRONLY);

	// replace standard input with input file.
	dup2(in, 0);
	// close unused file descriptors.
	close(in);
	close(out);

	// execute grep.
	execve("/bin/grep", grep_args, env);
}
