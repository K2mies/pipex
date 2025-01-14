/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:40:45 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/19 09:26:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_print.h"

static int	ft_len(long nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_printnbr(int nb)
{
	int		len;
	long	nbr;
	char	c;

	nbr = (long)nb;
	len = ft_len(nbr);
	c = '0';
	if (nb < 0)
		write(1, "-", 1);
	if (nb / 10 != 0)
	{
		if (nb < 0)
			ft_printnbr((nb / 10) * -1);
		else
			ft_printnbr(nb / 10);
	}
	if (nb < 0)
		c = (((nb % 10) * -1) + '0');
	else
		c = ((nb % 10) + '0');
	write (1, &c, 1);
	return (len);
}
