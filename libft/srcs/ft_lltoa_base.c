/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:29:34 by mdalil            #+#    #+#             */
/*   Updated: 2018/01/08 17:53:40 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static	int	check_neg(long long *n, int base)
{
	if ((*n) < 0 && base == 10)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

static	int	check_size(long long n, int base)
{
	int size;

	size = 0;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char		*ft_l_b(long long n, int base)
{
	int			i;
	int			neg;
	int			size;
	long long	num;
	char		*str;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	neg = check_neg(&n, base);
	size = check_size(n, base) + neg;
	CHECK((str = ft_strnew(size)));
	while (n != 0)
	{
		num = n % base;
		str[i++] = (num > 9) ? (num - 10) + 'a' : num + '0';
		n = n / base;
	}
	if (neg)
		str[i++] = '-';
	return (ft_strrev(str));
}
