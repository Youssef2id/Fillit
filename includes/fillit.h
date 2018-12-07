/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:17:33 by slaanani          #+#    #+#             */
/*   Updated: 2018/12/07 22:59:27 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ABS(Value) ((Value < 0) ? (-Value) : (Value))

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_tetromino
{
	char		data[4][5];
	char		id;
	int			nb_tetro;
	t_point		p[4];
	t_point		min;
	t_point		lastpos;
}					t_tetromino;

typedef struct		s_map
{
	char	data[22][23];
	int		size;
}					t_map;

int					valid_file(char *file_name);
int					read_tetro(int fd, t_tetromino *t);
int					add_position(t_tetromino *t);
int					valid_tetro(t_tetromino t);
void				build_tetromino(t_tetromino *t);
int					reset_position(t_tetromino *t);
int					valid(char *file_name, t_tetromino t[26]);
void				reset_map(t_map *map);
void				set_map(t_map *map);
void				print_map(t_map map);
int					set_tetro(t_map	*map, t_tetromino *t, int x, int y);
int					unset_tetro(t_map	*map, t_tetromino *t);
int					ft_read_tetro(char *file_name, t_tetromino t[26]);
int					solve_it(t_tetromino t[26], t_map *map, int i);
int					ft_sqrt(int n);
void				set_colors(char a[26][18]);
void				print_map_colors(t_map map);
int					animated_solve(t_tetromino t[26], t_map *map, int i);

#endif
