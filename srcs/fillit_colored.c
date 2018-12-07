/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_colored.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:57:50 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 23:19:03 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			main(int argc, char *argv[])
{
	t_tetromino t[26];
	t_map		map;
	int			bool;

	bool = 0;
	if (argc != 2)
	{
		write(1, "usage: fillit target_file\n", 27);
		return (0);
	}
	if (ft_read_tetro(argv[argc - 1], t) == 0)
		return (0);
	map.size = ft_sqrt(4 * t[0].nb_tetro);
	reset_map(&map);
	set_map(&map);
	while (bool == 0)
	{
		set_map(&map);
		bool = animated_solve(t, &map, 0);
		if (bool == 0)
			map.size++;
	}
	return (0);
}
