/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:29:31 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 13:57:37 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_len(t_thing *map)
{
	int	i;

	i = 0;
	map->wight = ft_strlen(map->table[i]);
	while (map->table[i])
	{
		if (ft_strlen(map->table[i]) != map->wight)
			return (1);
		i++;
	}
	if (check_wall(map->table, &map->wight))
		return (1);
	return (0);
}

int	count_char(t_thing *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->table[j])
	{
		i = 0;
		while (map->table[j][i])
		{
			if (map->table[j][i] == 'C')
				map->c += 1;
			else if (map->table[j][i] == 'E')
				map->e += 1;
			else if (map->table[j][i] == 'P')
				map->p += 1;
			else if (map->table[j][i] == 'X')
				map->x += 1;
			else if (map->table[j][i] != '0' && map->table[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	is_rectangular(t_thing *map)
{
	char	*buf;
	int		i;

	map->line = NULL;
	i = 0;
	while (1)
	{
		buf = get_next_line(map->fd);
		if (!buf)
			break ;
		if (*buf == '\n')
			return (0);
		map->line = ft_strjoin(map->line, buf);
		free(buf);
	}
	if (map->line == NULL)
		return (0);
	map->table = ft_split(map->line, '\n');
	map->deff = check_len(map);
	if (!count_char(map))
		ft_free(map->table);
	if (!map->c || !map->e || map->p != 1 || map->deff)
		return (0);
	return (1);
}

int	is_dot_ber(char *file)
{
	int		len;
	char	*string;

	string = ft_strrchr(file, '.');
	if (!string)
	{
		len = 0;
		return (0);
	}
	else
		len = ft_strlen(string);
	if (!(ft_strncmp(string, ".ber", len)))
	{
		return (1);
	}
	return (0);
}

int	ft_check_map(char *file, t_thing *extension)
{
	int		is_valid;

	extension->c = 0;
	extension->p = 0;
	extension->e = 0;
	extension->x = 0;
	extension->wight = 0;
	extension->hight = 0;
	extension->mov = 0;
	extension->fd = open(file, O_RDONLY);
	if (extension->fd == -1)
		return (0);
	is_valid = 1;
	if (!is_dot_ber(file) || !is_rectangular(extension))
		is_valid = 0;
	return (is_valid);
}
