/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:56:45 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/07 01:59:48 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_read_tetro(char *file_name, t_tetromino t[26])
{
	int		nbr_tetromino;
	int		fd;
	int		i;

	i = 0;
	if (!(nbr_tetromino = valid(file_name, t)))
		return (0);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (0);
	while (i < nbr_tetromino)
	{
		read_tetro(fd, &t[i]);
		reset_position(&t[i]);
		t[i].id = 'A' + i;
		t[i].nb_tetro = nbr_tetromino;
		i++;
	}
	return (1);
}
