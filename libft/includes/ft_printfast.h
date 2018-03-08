/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:45:18 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/19 14:45:19 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFAST_H
# define FT_PRINTFAST_H

# include <stdarg.h>
# include <string.h>

typedef struct			s_flag
{
	unsigned short int	field;
	unsigned short int	prec;
	unsigned short int	conv;
	unsigned short int	star;
	unsigned short int	just;
}						t_flag;

/*
**	ft_printfast
*/
int						ft_printfast(const char *format, ...);
/*
**	functions
*/
t_flag					get_flag(const char **format);
size_t					write_conv(va_list va, t_flag *flag);
size_t					ft_putstr_flag(const char *str, t_flag *flag);
size_t					ft_putchar_flag(char c, t_flag *flag);
size_t					ft_putnbr_flag(long long nb, t_flag flag);

#endif
