/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:41:24 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 01:59:04 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			valid(char *file_name, t_tetromino t[26])
{
	int				nbr_tetro;
	int				fd;
	int				i;
	int				pos;

	i = -1;
	if (!(nbr_tetro = valid_file(file_name)))
		ft_putstr("error\n");
	fd = open(file_name, O_RDONLY);
	while (++i < nbr_tetro)
	{
		if (!(read_tetro(fd, &t[i])))
		{
			ft_putstr("error\n");
			return (0);
		}
		pos = add_position(&t[i]);
		if (!(valid_tetro(t[i])) || !pos)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	close(fd);
	return (nbr_tetro);
}
