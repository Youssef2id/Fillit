/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:44:15 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:04:55 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		reset_map(t_map *map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			map->data[i][j] = '0';
			j++;
		}
		map->data[i][j] = '\0';
		j = 0;
		i++;
	}
}

void		set_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			map->data[i][j] = '.';
			j++;
		}
		map->data[i][j] = '\0';
		j = 0;
		i++;
	}
}

void		print_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.size)
	{
		ft_putstr(map.data[i]);
		ft_putchar('\n');
		i++;
	}
}

int			set_tetro(t_map *map, t_tetromino *t, int x, int y)
{
	int			p;
	t_point		tmp[4];

	p = 0;
	t->lastpos.x = x;
	t->lastpos.y = y;
	if (x >= map->size || y >= map->size)
		return (0);
	while (p < 4)
	{
		tmp[p].x = t->p[p].x + x;
		tmp[p].y = t->p[p].y + y;
		if (tmp[p].x >= map->size || tmp[p].y >= map->size)
			return (0);
		if (map->data[tmp[p].x][tmp[p].y] != '.')
			return (0);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		map->data[tmp[p].x][tmp[p].y] = t->id;
		p++;
	}
	return (1);
}

int			unset_tetro(t_map *map, t_tetromino *t)
{
	int			p;
	t_point		tmp[4];

	p = 0;
	while (p < 4)
	{
		tmp[p].x = t->p[p].x + t->lastpos.x;
		tmp[p].y = t->p[p].y + t->lastpos.y;
		if (tmp[p].x >= map->size || tmp[p].y >= map->size)
			return (0);
		if (map->data[tmp[p].x][tmp[p].y] != t->id)
			return (0);
		p++;
	}
	p = 0;
	while (p < 4)
	{
		map->data[tmp[p].x][tmp[p].y] = '.';
		p++;
	}
	return (1);
}
