/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <yidabdes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:14:07 by yidabdes          #+#    #+#             */
/*   Updated: 2018/12/06 22:09:10 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n > -10)
	{
		ft_putchar('-');
		ft_putchar(n * -1 + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}
