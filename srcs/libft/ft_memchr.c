/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:43:04 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:08:02 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*strs;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	strs = (unsigned char *)s;
	while (i < (int)n)
	{
		if (*strs == chr)
			return (strs);
		else
			strs++;
		i++;
	}
	return (NULL);
}
