/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:11:12 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/11 13:05:16 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*dst;

	temp = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (temp < dst)
	{
		while (n--)
			dst[n] = temp[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dst);
}
