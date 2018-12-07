/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:01:06 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:10:38 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int len1;
	int	j;

	j = 0;
	len1 = (int)ft_strlen(s1);
	while (s2[j] != '\0' && j < (int)n)
	{
		s1[len1] = s2[j];
		j++;
		len1++;
	}
	s1[len1] = '\0';
	return (s1);
}
