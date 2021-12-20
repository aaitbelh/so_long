/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:55:00 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/20 19:00:22 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != (char )c && str[i])
		i++;
	if (str[i] == (char ) c)
		return (1);
	else
		return (0);
}

char	*ft_strdup(const char	*src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i])
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strrchr(const char *str, int c)
{	
	char	*ptr;

	ptr = (char *)str;
	if (c == 0 && *str == '\0')
		return ((char *)str);
	while (*str)
		str++;
	while (str >= ptr)
	{
		if (*str == (char )c)
		{
			return ((char *)str);
		}
		str--;
	}
	return (NULL);
}

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
