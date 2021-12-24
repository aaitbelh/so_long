/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:10:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 13:47:35 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

void	img_nf(t_thing *stc)
{
	int	i;

	i = 0;
	while (stc->table[i])
	{
		free(stc->table[i]);
		i++;
	}
	free(stc->table);
	printf("\033[0;33m THIS IMAGE DOES FOUND !!\n");
	exit (1);
}

int	cross(t_thing *g)
{
	int	i;

	i = 0;
	printf("\033[0;31m THE GAME EXIT\n");
	while (g->table[i])
	{
		free(g->table[i]);
		i++;
	}
	free(g->table[i]);
	exit(0);
	return (0);
}

void	you_die(t_thing *g)
{
	int	i;

	i = 0;
	while (g->table[i])
	{
		free(g->table[i]);
		i++;
	}
	i = 0;
	free(g->table);
	free(g->forb);
	printf("\033[0;31m THE CREEPER EXLOISE IN YOUR FACE TRY AGAIN\n");
	exit(1);
}
