/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:29:11 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/15 16:41:16 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = '0';
	if (n < 0)
		write(fd, "-", 1);
	if (n / 10 != 0)
	{
		if (n < 0)
			ft_putnbr_fd((n / 10) * -1, fd);
		else
			ft_putnbr_fd(n / 10, fd);
	}
	if (n < 0)
		c = (((n % 10) * -1) + '0');
	else
		c = ((n % 10) + '0');
	write(fd, &c, 1);
}
