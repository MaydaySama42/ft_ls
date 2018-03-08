/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:29:34 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/18 18:04:43 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	int	check_size(unsigned long long n, int base)
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

char		*ft_u_b(unsigned long long n, int base)
{
	int			i;
	int			size;
	long long	num;
	char		*str;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	size = check_size(n, base);
	CHECK((str = ft_strnew(size)));
	while (n != 0)
	{
		num = n % base;
		str[i++] = (num > 9) ? (num - 10) + 'a' : num + '0';
		n = n / base;
	}
	return (ft_strrev(str));
}
