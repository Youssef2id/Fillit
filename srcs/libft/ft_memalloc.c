/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:57:45 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:07:55 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*mem;
	int		i;

	i = 0;
	mem = (void *)malloc(size * sizeof(mem));
	if (mem == NULL)
		return (NULL);
	while (size--)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
