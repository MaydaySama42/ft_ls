/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:45:18 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/19 14:45:19 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printfast.h"

int		ft_printfast(const char *format, ...)
{
	t_flag	flag;
	size_t	len;
	va_list	va;

	len = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			(format++);
			flag = get_flag(&format);
			len += write_conv(va, &flag);
		}
		if (*format)
			write(1, (format++), 1);
	}
	va_end(va);
	return (len);
}
