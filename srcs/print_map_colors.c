/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:42:24 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 01:46:23 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		set_colors(char a[26][18])
{
	int	ind;
	int k;

	ind = 0;
	k = 1;
	while (ind < 26)
	{
		ft_strncpy(a[ind], "\033[4am  \033[0m", 17);
		if (k == 8)
			k = 1;
		a[ind][3] = '0' + k;
		k++;
		ind++;
	}
}

void		print_map_colors(t_map map)
{
	int		i;
	int		j;
	int		ind;
	char	a[26][18];

	set_colors(a);
	i = -1;
	while (++i < map.size)
	{
		j = -1;
		while (++j < map.size)
		{
			if (map.data[i][j] != '.')
			{
				ind = (int)map.data[i][j] - 65;
				ft_putstr(a[ind]);
			}
			else
				ft_putstr(". ");
		}
		ft_putchar('\n');
	}
}
