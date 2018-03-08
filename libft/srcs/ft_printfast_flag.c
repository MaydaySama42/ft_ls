/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfast_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:45:18 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/19 14:45:19 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printfast.h"
#include "libft.h"

t_flag	get_flag(const char **format)
{
	t_flag	flag;
	int		i;

	i = 0;
	flag.just = (**format == '-' && ((*format)++)) ? 1 : 0;
	flag.star = (**format == '*' && ((*format)++)) ? 1 : 0;
	flag.field = ft_atoi(*format);
	flag.prec = 0;
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.' && (*format)++)
		flag.prec = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	flag.conv = *((*format)++);
	return (flag);
}

size_t	write_conv(va_list va, t_flag *flag)
{
	size_t	len;

	len = 0;
	flag->conv = (flag->conv == 's') ? 0 : flag->conv;
	flag->conv = (flag->conv == 'c') ? 1 : flag->conv;
	flag->conv = (flag->conv == 'd') ? 2 : flag->conv;
	flag->conv = (flag->conv == 'l') ? 3 : flag->conv;
	flag->field = (flag->star) ? va_arg(va, int) : flag->field;
	len = (flag->conv == 0) ?
		ft_putstr_flag(va_arg(va, char*), flag) : len;
	len = (flag->conv == 1) ?
		ft_putchar_flag((char)va_arg(va, int), flag) : len;
	len = (flag->conv == 2) ?
		ft_putnbr_flag((long long)va_arg(va, int), *flag) : len;
	len = (flag->conv == 3) ?
		ft_putnbr_flag(va_arg(va, long long), *flag) : len;
	len = (flag->conv > 1 && flag->field > len) ? flag->field : len;
	return (len);
}
