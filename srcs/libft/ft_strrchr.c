/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:49:49 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:11:07 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		last;

	i = 0;
	last = -1;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	if (str[i] == '\0' && c == 0)
		return (&str[i]);
	if (last != -1)
		return (&str[last]);
	return (NULL);
}
