/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 05:10:32 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/10 02:50:51 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_neg(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static int	check_size(int n)
{
	int size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size *= 10;
	}
	return (size);
}

void		ft_putnbr(int n)
{
	int	size;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	check_neg(&n);
	size = check_size(n);
	while (size > 0)
	{
		ft_putchar('0' + (n / size));
		n %= size;
		size /= 10;
	}
}
