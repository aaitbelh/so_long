/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:58:12 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/20 20:14:50 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_thing *g, int (*f)(void *, void *, void *, int, int))
{
	if (g->table[g->p_y / 64 - 1][g->p_x / 64] == 'E' && g->c == 0)
		end_game(g->table);
	if (g->table[g->p_y / 64 - 1][g->p_x / 64] != '1')
	{
		if (g->table[g->p_y / 64 - 1][g->p_x / 64] != 'E')
		{
			if (g->table[g->p_y / 64 - 1][g->p_x / 64] == 'C' && g->c != 0)
			{
				g->table[g->p_y / 64 - 1][g->p_x / 64] = '0';
				g->c--;
			}
			f(g->mlx, g->win, g->player, g->p_x, g->p_y -= 64);
			f(g->mlx, g->win, g->floor, g->p_x, g->p_y + 64);
		}
	}
}

static void	move_down(t_thing *g, int (*f)(void *, void *, void *, int, int))
{
	if (g->table[g->p_y / 64 + 1][g->p_x / 64] == 'E' && g->c == 0)
		end_game(g->table);
	if (g->table[g->p_y / 64 + 1][g->p_x / 64] != '1')
	{
		if (g->table[g->p_y / 64 + 1][g->p_x / 64] != 'E')
		{
			if (g->table[g->p_y / 64 + 1][g->p_x / 64] == 'C' && g->c != 0)
			{
				g->table[g->p_y / 64 + 1][g->p_x / 64] = '0';
				g->c--;
			}
			f(g->mlx, g->win, g->player, g->p_x, g->p_y += 64);
			f(g->mlx, g->win, g->floor, g->p_x, g->p_y - 64);
		}
	}
}

static void	move_right(t_thing *g, int (*f)(void *, void *, void *, int, int))
{
	if (g->table[g->p_y / 64][g->p_x / 64 + 1] == 'E' && g->c == 0)
		end_game(g->table);
	if (g->table[g->p_y / 64][g->p_x / 64 + 1] != '1')
	{
		if (g->table[g->p_y / 64][g->p_x / 64 + 1] != 'E')
		{
			if (g->table[g->p_y / 64][g->p_x / 64 + 1] == 'C' && g->c != 0)
			{
				g->table[g->p_y / 64][g->p_x / 64 + 1] = '0';
				g->c--;
			}
			f(g->mlx, g->win, g->player, g->p_x += 64, g->p_y);
			f(g->mlx, g->win, g->floor, g->p_x - 64, g->p_y);
		}
	}
}

static void	move_left(t_thing *g, int (*f)(void *, void *, void *, int, int))
{
	if (g->table[g->p_y / 64][g->p_x / 64 - 1] == 'E' && g->c == 0)
		end_game(g->table);
	if (g->table[g->p_y / 64][g->p_x / 64 - 1] != '1')
	{
		if (g->table[g->p_y / 64][g->p_x / 64 - 1] != 'E')
		{
			if (g->table[g->p_y / 64][g->p_x / 64 - 1] == 'C' && g->c != 0)
			{
				g->table[g->p_y / 64][g->p_x / 64 - 1] = '0';
				g->c--;
			}
			f(g->mlx, g->win, g->player, g->p_x -= 64, g->p_y);
			f(g->mlx, g->win, g->floor, g->p_x + 64, g->p_y);
		}
	}
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
		move_right(g, f);
	if (key == 0)
		move_left(g, f);
	if (key == 13)
		move_up(g, f);
	if (key == 1)
		move_down(g, f);
	return (0);
}
