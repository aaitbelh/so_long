/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:01 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 11:22:10 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_stepes(t_thing *up)
{
	char	*stepes;

	stepes = ft_itoa(up->mov);
	mlx_string_put(up->mlx, up->win, 0, 0, 0xFFFF00, stepes);
	free(stepes);
}

static void	lol(t_thing *up, int j, int i)
{
	if (up->table[j][i] == 'E')
		mlx_put_image_to_window(up->mlx, up->win, up->exit, i * 64, j * 64);
	else if (up->table[j][i] == 'X')
		mlx_put_image_to_window(up->mlx, up->win, up->enemy, i * 64, j * 64);
	else if (up->table[j][i] == 'P')
		mlx_put_image_to_window(up->mlx, up->win, up->player, i * 64, j * 64);
}

void	update(t_thing *up)
{
	int	i;
	int	j;
	int	(*f)(void *, void *, void *, int x, int y);

	j = 0;
	f = mlx_put_image_to_window;
	while (up->table[j])
	{
		i = 0;
		while (up->table[j][i])
		{
			if (up->table[j][i] == '1')
				f(up->mlx, up->win, up->wall, i * 64, j * 64);
			else if (up->table[j][i] == '0')
			{
				f(up->mlx, up->win, up->floor, i * 64, j * 64);
				print_stepes(up);
			}
			else if (up->table[j][i] == 'C')
				f(up->mlx, up->win, up->k, i * 64, j * 64);
			lol(up, j, i);
			i++;
		}
		j++;
	}
}
