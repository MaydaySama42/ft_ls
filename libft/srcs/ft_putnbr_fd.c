/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 05:11:50 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/10 02:51:11 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_neg(int *n, int fd)
{
	if (*n < 0)
	{
		*n *= -1;
		ft_putchar_fd('-', fd);
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

void		ft_putnbr_fd(int n, int fd)
{
	int	size;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	check_neg(&n, fd);
	size = check_size(n);
	while (size > 0)
	{
		ft_putchar_fd('0' + (n / size), fd);
		n %= size;
		size /= 10;
	}
}
