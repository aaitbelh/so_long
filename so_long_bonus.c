/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:37:52 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 14:11:07 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_index_2(t_thing *ind)
{
	int	i;
	int	j;
	int	index;

	j = 0;
	index = 0;
	while (ind->table[j])
	{
		i = 0;
		while (ind->table[j][i])
		{
			if (ind->table[j][i] == 'X')
			{
				ind->enemy_x[index] = i;
				ind->enemy_y[index] = j;
				index ++;
			}
			i++;
		}
		j++;
	}
}

static void	get_index(t_thing *ind)
{
	int	i;
	int	j;

	j = 0;
	while (ind->table[j])
	{
		i = 0;
		while (ind->table[j][i])
		{
			if (ind->table[j][i] == 'P')
			{
				ind->p_x = i;
				ind->p_y = j;
			}
			i++;
		}
		j++;
	}
	ind->hight = j;
	get_index_2(ind);
}

void	set_pic(t_thing *put)
{
	int	i;
	int	j;

	put->m = mlx_put_image_to_window;
	j = 0;
	while (put->table[j])
	{
		i = 0;
		while (put->table[j][i])
		{
			put->m(put->mlx, put->win, put->floor, i * 64, j * 64);
			if (put->table[j][i] == 'P')
				put->m(put->mlx, put->win, put->player, i * 64, j * 64);
			else if (put->table[j][i] == '1')
				put->m(put->mlx, put->win, put->wall, i * 64, j * 64);
			else if (put->table[j][i] == 'E')
				put->m(put->mlx, put->win, put->exit, i * 64, j * 64);
			else if (put->table[j][i] == 'C')
				put->m(put->mlx, put->win, put->k, i * 64, j * 64);
			else if (put->table[j][i] == 'X')
				put->m(put->mlx, put->win, put->enemy, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

static void	git_pics(t_thing *pic)
{
	int	p;

	pic->wall = mlx_xpm_file_to_image(pic->mlx, "./i/dirt.xpm", &p, &p);
	if (!pic->wall)
		img_nf(pic);
	pic->player = mlx_xpm_file_to_image(pic->mlx, "./i/char.xpm", &p, &p);
	if (!pic->player)
		img_nf(pic);
	pic->floor = mlx_xpm_file_to_image(pic->mlx, "./i/floor.xpm", &p, &p);
	if (!pic->floor)
		img_nf(pic);
	pic->exit = mlx_xpm_file_to_image(pic->mlx, "./i/portal.xpm", &p, &p);
	if (!pic->exit)
		img_nf(pic);
	pic->k = mlx_xpm_file_to_image(pic->mlx, "./i/coll.xpm", &p, &p);
	if (!pic->k)
		img_nf(pic);
	pic->enemy = mlx_xpm_file_to_image(pic->mlx, "./i/criper.xpm", &p, &p);
	if (!pic->enemy)
		img_nf(pic);
	set_pic(pic);
}

int	main(int ac, char **av)
{
	t_thing	d;

	if (ac != 2)
	{
		printf("USEAGE : ./so_long map\n");
		exit (1);
	}
	if (!ft_check_map(av[1], &d))
	{
		printf("ERROR :(\n");
		exit (1);
	}
	d.forb = calloc(d.x, sizeof(int));
	d.enemy_x = calloc(d.x, sizeof(int));
	d.enemy_y = calloc(d.x, sizeof(int));
	get_index(&d);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.wight * 64, d.hight * 64, "./so_long");
	mlx_hook(d.win, 17, 0, cross, NULL);
	mlx_hook(d.win, 02, 1L << 0, move, &d);
	git_pics(&d);
	mlx_loop_hook(d.mlx, animation, &d);
	mlx_loop(d.mlx);
}
