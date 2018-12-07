/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:45:22 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:08:20 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	str = b;
	while (i < (unsigned int)len)
	{
		str[j] = c;
		i++;
		j++;
	}
	return (b);
}
