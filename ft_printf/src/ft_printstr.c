/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:52:29 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/20 15:28:03 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_print.h"

int	ft_printstr(const char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	len = write(1, str, ft_strlen(str));
	return (len);
}
