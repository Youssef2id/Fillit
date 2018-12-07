/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 01:51:50 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:05:17 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static	int	ft_findln(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	while ((new_line = ft_strchr(buf[fd], '\n')))
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_strsub(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = ft_strnew(ft_strlen(buf[fd]));
		ft_strcpy(*line, buf[fd]);
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

static	int	ft_read(int fd, char **buffer)
{
	char		*temp;
	int			i;

	temp = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (!buffer[fd])
		{
			buffer[fd] = ft_strnew(ft_strlen(temp));
			ft_strcpy(buffer[fd], temp);
		}
		else
			buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (ft_strchr(buffer[fd], '\n'))
			break ;
		ft_memset(temp, 0, BUFF_SIZE);
	}
	free(temp);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*buf[MAXFD];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &buf[fd]) < 0) ||
fd > MAXFD)
		return (-1);
	if (ft_findln(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}
