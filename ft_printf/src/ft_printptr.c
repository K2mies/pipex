/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:27:55 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/20 15:28:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_print.h"

static int		ft_ptr_len(unsigned long num);
static void		ft_put_ptr(unsigned long num);

int	ft_printptr(void *ptr)
{
	int					print_len;
	unsigned long		n;

	n = (unsigned long)ptr;
	print_len = 0;
	if (ptr == NULL)
	{
		print_len += write(1, "(nil)", 5);
		return (print_len);
	}
	print_len += write(1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_put_ptr(n);
		print_len += ft_ptr_len(n);
	}
	return (print_len);
}

static int	ft_ptr_len(unsigned long num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}
