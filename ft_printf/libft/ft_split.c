/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:14:01 by rhvidste          #+#    #+#             */
/*   Updated: 2024/11/14 09:58:39 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_free(char **strs, int count);
static int		ft_word_count(const char *s, char c);
static char		*ft_fill_word(const char *s, int start, int end);
char			**ft_splitter(char **res, const char *s, char c);

char	**ft_split(const char *s, char c)
{
	int			word_count;
	char		**res;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	res = ft_calloc(word_count + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_splitter(res, s, c);
	return (res);
}

char	**ft_splitter(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		s_word;

	s_word = -1;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		if ((s[i] == c || s[i + 1] == '\0') && s_word >= 0)
		{
			if (s[i] == c)
				res[j] = ft_fill_word(s, s_word, i);
			else
				res[j] = ft_fill_word(s, s_word, i + 1);
			if (!(res[j++]))
				return (ft_free(res, j));
			s_word = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

static void	*ft_free(char **strs, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_word_count(const char *s, char c)
{
	int		count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*ft_fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start) + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}
