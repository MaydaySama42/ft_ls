/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	return_perm_type(mode_t st_mode)
{
	char	c;

	c = S_ISDIR(st_mode) ? 'd' : '-';
	c = S_ISCHR(st_mode) ? 'c' : c;
	c = S_ISBLK(st_mode) ? 'b' : c;
	c = S_ISFIFO(st_mode) ? 'p' : c;
	c = S_ISLNK(st_mode) ? 'l' : c;
	c = S_ISSOCK(st_mode) ? 's' : c;
	return (c);
}

int		count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	swap_args(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		arg_type(char *str)
{
	t_stat	info;
	int		type;
	int		ret;

	ret = lstat(str, &info);
	type = 0;
	if (ret == 0)
		type = (S_ISDIR(info.st_mode)) ? 2 : 1;
	return (type);
}

void	valid_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (arg_type(args[i]) == 0)
			ft_printfast("ls: %s: %s\n", args[i], strerror(errno));
		i++;
	}
}
