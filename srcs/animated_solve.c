/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:06:51 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 23:17:43 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				animated_solve(t_tetromino t[26], t_map *map, int i)
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
				system("clear");
				ft_putstr("\033[1m\033[31m---------- MAP ----------\n");
				print_map_colors(*map);
				sleep(1);
				if (animated_solve(t, map, i + 1) == 1)
					return (1);
				else
					unset_tetro(map, &t[i]);
			}
		}
	}
	return (0);
}
