/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:25:18 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/12/23 14:11:01 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 20

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

//----------STRUCT--------------------
typedef struct s_thing
{
	int		hight;
	int		wight;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*k;
	int		x;
	int		p;
	int		c;
	int		e;
	int		space;
	int		mov;
	int		deff;
	int		fd;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	char	**table;
	char	*line;
	int		*forb;
	int		*enemy_x;
	int		*enemy_y;
	int		(*m)(void *, void *, void *, int, int);
}	t_thing;

//----------------FUNCTIONS------------
int		ft_check_map(char *file, t_thing *extension);
int		move(int key, t_thing *game);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	set_pic(t_thing *put);
void	update(t_thing *up);
int		animation(t_thing *move);
char	*ft_itoa(int n);
void	move_enemy(t_thing *p);
int		time_int(t_thing *l);

//---------------NEEEDS----------------
int		ft_strlen(char *str);
int		ft_strncmp(const char	*s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
int		ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char	*src);

//--------------NEEDS2-----------------
int		check_wall(char **table, int *ln);
void	ft_free(char **table);
void	end_game(char **table);
void	img_nf(t_thing *stc);

//------------NEEDS3------------
void	img_nf(t_thing *stc);
int		cross(t_thing *g);
void	you_die(t_thing *g);
void	*ft_calloc(size_t count, size_t size);

#endif