/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:22:04 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/08 16:12:20 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main()
{
	if (access("test.text", R_OK) == 0)
		printf("test.text is accessable in reading mode \n");

	if (access("test.text ", W_OK) == 0)
		printf("test.text is accessable in write mode \n");
	
	if (access("test.text", X_OK) == 0)
		printf("test.text is accessable in execution mode\n");
	
	if (access("test.text", R_OK|W_OK) == 0)
		printf("test.text is accessable in write and read mode\n");
}
