/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:50:32 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/12 17:45:30 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (!dst && size == 0)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dst_len < (size -1) && size > 0)
	{
		while (src[i] && dst_len + i < (size -1))
		{
			dst[j++] = src[i++];
		}
		dst[j] = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (src_len + dst_len);
}
