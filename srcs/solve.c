/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:06:51 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 23:17:51 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				solve_it(t_tetromino t[26], t_map *map, int i)
{
	int				x;
	int				y;

	if (i == t[0].nb_tetro)
		return (1);
	x = -1;
	while (++x < map->size)
	{
		y = -1;
		while (++y < map->size)
		{
			if (set_tetro(map, &t[i], x, y) == 1)
			{
				if (solve_it(t, map, i + 1) == 1)
					return (1);
				else
					unset_tetro(map, &t[i]);
			}
		}
	}
	return (0);
}

int				ft_sqrt(int n)
{
	float	an;
	float	eps;
	float	anplus1;

	an = (float)n / 2.0;
	anplus1 = (an + (float)n / an) / 2.0;
	eps = 0.00001;
	while ((ABS(an - anplus1)) >= eps)
	{
		an = anplus1;
		anplus1 = (an + (float)n / an) / 2.0;
	}
	return ((int)anplus1);
}
