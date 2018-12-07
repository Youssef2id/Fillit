/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:50:56 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:05:37 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int					valid_struct(int fd)
{
	char	*line;
	int		nbr_line;
	int		len;
	int		nb_tetromino;

	nbr_line = 0;
	nb_tetromino = 1;
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		if (len == 4)
			nbr_line++;
		else if (len == 0 && nbr_line == 4)
		{
			nbr_line = 0;
			nb_tetromino++;
		}
		else if (len != 4 && len != 0)
			return (0);
		else if (len == 0 && nbr_line == 0)
			return (0);
	}
	if (len != 4 || nbr_line != 4)
		return (0);
	return (nb_tetromino);
}

int					line_counter(int fd)
{
	char	c[1];
	int		counter;

	counter = 1;
	while (read(fd, c, 1) != 0)
	{
		if (*c == '\n')
			counter++;
		if (*c != '.' && *c != '#' && *c != '\n')
			return (0);
	}
	return (counter);
}

int					valid_file(char *file_name)
{
	int		fd;
	int		nbr_line;
	int		nb_tetromino;

	fd = open(file_name, O_RDONLY);
	nbr_line = line_counter(fd);
	if (nbr_line < 5)
		return (0);
	close(fd);
	fd = open(file_name, O_RDONLY);
	nb_tetromino = valid_struct(fd);
	close(fd);
	if (nbr_line != (nb_tetromino * 5))
		return (0);
	if (nb_tetromino > 26)
		return (0);
	return (nb_tetromino);
}
