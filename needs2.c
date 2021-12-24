/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:14:48 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 11:57:50 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	printf("\033[0;32m You Win 👏🤴 \n");
	exit (0);
}

void	ft_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	printf("THERE ARE SOME OBTERUSIVE CHAR IN MAP\n");
	exit(1);
}

static int	check_fewall(char **table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table[j])
		j++;
	j -= 1;
	while (table[0][i])
	{
		if (table[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (table[j][i])
	{
		if (table[j][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **table, int *ln)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (table[i])
	{
		if (table[i][0] != '1' || table[i][*ln - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	if (!check_fewall(table))
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
