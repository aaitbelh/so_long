/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:10:15 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 00:20:04 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

static void	put_nmbr(char *ptr, unsigned int m, int len_num)
{
	ptr[len_num] = '\0';
	len_num--;
	if (m == 0)
	{
		ptr[len_num--] = '0';
	}
	while (len_num >= 0 && m != 0)
	{
		*(ptr + len_num) = m % 10 + '0';
		m /= 10;
		len_num--;
	}
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	m;

	ptr = (char *)malloc(sizeof(char) * (len(n) + 1));
	if (!ptr)
		return (0);
	if (n < 0)
	{
		ptr[0] = '-';
		m = -n;
	}
	else
		m = n;
	put_nmbr(ptr, m, len(n));
	return (ptr);
}
