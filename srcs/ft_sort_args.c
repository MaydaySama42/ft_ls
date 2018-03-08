/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	sort_alphanum_args(char **args)
{
	int	i;

	i = 0;
	while (args[i + 1])
	{
		if (ft_strcmp(args[i], args[i + 1]) > 0)
		{
			swap_args(&args[i], &args[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static void		sort_time_args(char **args)
{
	int		i;
	t_stat	info;
	t_stat	info2;

	i = 0;
	while (args[i + 1])
	{
		lstat(args[i], &info);
		lstat(args[i + 1], &info2);
		if (get_time(info) - get_time(info2) < 0)
		{
			swap_args(&args[i], &args[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

static void		sort_reverse_args(char **args)
{
	int	start;
	int	end;

	start = 0;
	end = count_args(args) - 1;
	while (start < end)
	{
		swap_args(&args[start], &args[end]);
		start++;
		end--;
	}
}

void			sort_type_args(char **args)
{
	int		i;

	i = 0;
	if (!args)
		return ;
	if (!IS_OP(F))
		sort_alphanum_args(args);
	valid_args(args);
	if (IS_OP(T) && !IS_OP(F))
		sort_time_args(args);
	if (IS_OP(R) && !IS_OP(F))
		sort_reverse_args(args);
	while (args[i + 1])
	{
		if (arg_type(args[i]) != ARG_FILE && arg_type(args[i + 1]) == ARG_FILE)
		{
			swap_args(&args[i], &args[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
