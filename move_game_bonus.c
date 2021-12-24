/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:58:12 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 15:06:17 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move1(t_thing *g, int x, int y)
{
	if (g->table[g->p_y + y][g->p_x + x] == 'E' && g->c == 0)
		end_game(g->table);
	if (g->table[g->p_y + y][g->p_x + x] == 'X')
		you_die(g);
	if (g->table[g->p_y + y][g->p_x + x] == 'C')
		g->c--;
	if (g->table[g->p_y + y][g->p_x + x] != '1')
	{
		if (g->table[g->p_y + y][g->p_x + x] != 'E')
		{
			g->table[g->p_y + y][g->p_x + x] = 'P';
			g->table[g->p_y][g->p_x] = '0';
			g->p_y += y;
			g->p_x += x;
		}
	}
	update(g);
}

int	move(int key, t_thing *g)
{
	int	(*f)(void *, void *, void *, int, int);

	f = mlx_put_image_to_window;
	if (key == 53 || key == 17)
	{
		printf("THE GAME EXIT");
		exit(0);
	}
	if (key == 2)
		move1(g, 1, 0);
	if (key == 0)
		move1(g, -1, 0);
	if (key == 13)
		move1(g, 0, -1);
	if (key == 1)
		move1(g, 0, 1);
	if (key == 2 || key == 0 || key == 13 || key == 1)
		g->mov++;
	return (0);
}
