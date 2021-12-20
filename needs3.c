/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:10:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/20 20:49:05 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	cross(void)
{
	printf("\033[0;31m THE GAME EXIT\n");
	exit(0);
	return (0);
}
