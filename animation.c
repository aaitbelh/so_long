/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:42:49 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 14:56:52 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_thing *p)
{
	int	index;

	index = 0;
	while (index < p->x)
	{
		if (!p->forb[index])
			p->forb[index] = 1;
		if (p->table[p->enemy_y[index]][p->enemy_x[index]
			+ p->forb[index]] == '0')
		{
			p->table[p->enemy_y[index]][p->enemy_x[index]] = '0';
			p->table[p->enemy_y[index]][p->enemy_x[index]
				+ p->forb[index]] = 'X';
			p->enemy_x[index] += p->forb[index];
		}
		else if (p->table[p->enemy_y[index]][p->enemy_x[index]
			+ p->forb[index]] == 'P' )
			you_die(p);
		else
			p->forb[index] *= -1;
		index++;
	}
}

int	animation(t_thing *move)
{
	static int	i;
	static int	j;
	int			p;

	p = 60;
	if (i == 1000)
	{
		move->k = mlx_xpm_file_to_image(move->mlx, "./i/coll.xpm", &p, &p);
		update (move);
	}
	if (i / 2 == 1000)
	{
		i = 0;
		move->k = mlx_xpm_file_to_image(move->mlx, "./i/coll2.xpm", &p, &p);
		update (move);
	}
	if (j == 3000)
	{
		move_enemy(move);
		update (move);
		j = 0;
	}
	i++;
	j++;
	return (1);
}
