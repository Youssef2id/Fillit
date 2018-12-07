/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:31:52 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:10:46 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < (unsigned int)len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (unsigned int)len)
		dst[i++] = '\0';
	return (dst);
}
