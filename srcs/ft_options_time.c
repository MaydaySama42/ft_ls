/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	get_time(t_stat info)
{
	if (IS_OP(C))
		return (info.st_ctime);
	else if (IS_OP(U))
		return (info.st_atime);
	else
		return (info.st_mtime);
}

void	print_time(t_file *file)
{
	time_t	*t;
	time_t	date;

	t = NULL;
	date = get_time(file->info);
	write(1, ctime(&date) + 4, 7);
	if (time(t) - (date) > 15552000)
		write(1, ctime(&date) + 19, 5);
	else
		write(1, ctime(&date) + 11, 5);
}
