/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:37:46 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/20 18:59:07 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**free_table(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

static int	words_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	*word(const char *s, char c)
{
	int			len;
	char		*str;
	int			i;

	len = words_len(s, c);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len > i)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = 0;
	return (str);
}

static int	ft_counts(const char *s1, char c)
{
	int	words;

	words = 0;
	while (*s1)
	{
		if (*s1 == c)
			s1++;
		if (*s1 && *s1 != c)
			words++;
		while (*s1 && *s1 != c)
			s1++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_counts(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ptr[i] = word(s, c);
			if (!ptr[i])
				free_table(ptr, i);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	ptr[i] = 0;
	return (ptr);
}
