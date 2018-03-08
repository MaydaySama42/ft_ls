/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:29:53 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/12 02:11:47 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check(const char *str, int i, int *comp)
{
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		return (1);
	else if (str[i] == '+')
	{
		*comp = *comp + 1;
		return (1);
	}
	else
		return (0);
}

static int	check_limit(int nb)
{
	if (nb <= 2147483647 && nb >= -2147483648)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int nb;
	int neg;
	int i;
	int sign;

	nb = 0;
	neg = 1;
	i = 0;
	sign = 0;
	while (check(str, i, &sign))
		i++;
	if (str[i] == '-')
	{
		sign++;
		neg = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && sign <= 1 && check_limit(nb))
	{
		if (nb > 0)
			nb *= 10;
		nb += (str[i++] - '0');
	}
	return (nb = nb * neg);
}

int			ft_atoi_free(char *str)
{
	int nb;
	int neg;
	int i;
	int sign;

	nb = 0;
	neg = 1;
	i = 0;
	sign = 0;
	while (check(str, i, &sign))
		i++;
	if (str[i] == '-')
	{
		sign++;
		neg = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && sign <= 1 && check_limit(nb))
	{
		if (nb > 0)
			nb *= 10;
		nb += (str[i++] - '0');
	}
	free(str);
	return (nb = nb * neg);
}
