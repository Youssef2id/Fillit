/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:35:29 by slaanani          #+#    #+#             */
/*   Updated: 2018/12/07 01:56:11 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			read_tetro(int fd, t_tetromino *t)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		get_next_line(fd, &line);
		if (*line)
		{
			ft_strcpy(t->data[i], line);
			i++;
		}
		j++;
	}
	*t->data[i] = '\0';
	if (!(add_position(t)))
		return (0);
	return (1);
}

int			add_position(t_tetromino *t)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		if (t->data[i][j] == '#')
		{
			t->p[k].x = i;
			t->p[k].y = j;
			k++;
		}
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	if (k != 4)
		return (0);
	return (1);
}

int			valid_tetro(t_tetromino t)
{
	int		p;
	int		x;
	int		y;
	int		nbr_lnk;

	nbr_lnk = 0;
	p = 0;
	while (p < 4)
	{
		x = t.p[p].x;
		y = t.p[p].y;
		if (t.data[x + 1][y] == '#' && (x + 1) <= 3)
			nbr_lnk++;
		if (t.data[x - 1][y] == '#' && (x - 1) >= 0)
			nbr_lnk++;
		if (t.data[x][y + 1] == '#' && (y + 1) <= 3)
			nbr_lnk++;
		if (t.data[x][y - 1] == '#' && (y - 1) >= 0)
			nbr_lnk++;
		p++;
	}
	if (nbr_lnk != 8 && nbr_lnk != 6)
		return (0);
	return (1);
}

void		build_tetromino(t_tetromino *t)
{
	int	x;
	int	y;
	int	p;
	int j;

	p = 0;
	while (p < 4)
	{
		j = 0;
		while (j < 4)
		{
			t->data[p][j] = '.';
			j++;
		}
		x = t->p[p].x;
		y = t->p[p].y;
		t->data[x][y] = '#';
		p++;
	}
}

int			reset_position(t_tetromino *t)
{
	int		p;

	p = 0;
	t->min.x = 10;
	t->min.y = 10;
	while (p < 4)
	{
		if (t->p[p].x < t->min.x)
			t->min.x = t->p[p].x;
		if (t->p[p].y < t->min.y)
			t->min.y = t->p[p].y;
		p++;
	}
	p = 0;
	while (p < 4)
	{
		t->p[p].x -= t->min.x;
		t->p[p].y -= t->min.y;
		p++;
	}
	build_tetromino(t);
	return (0);
}
