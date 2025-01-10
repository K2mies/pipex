/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_example00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:34:19 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/10 15:59:24 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		main()
{
	if (unlink("example.txt") == 0)
		printf("File successfully deleted");
	else
		printf("Error deletin file");
	
	return (0);
}
