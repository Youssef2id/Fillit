/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:05:15 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:08:17 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*strdst;
	char	*strsrc;

	i = (int)len;
	strdst = (char *)dst;
	strsrc = (char *)src;
	if (strsrc > strdst)
		ft_memcpy(strdst, strsrc, i);
	else
	{
		while (i--)
			strdst[i] = strsrc[i];
	}
	return (dst);
}
