/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			skip_hidden_files(t_file **file, int ignore_r)
{
	while ((*file) && (*file)->filename[0] == '.' && !IS_OP(A))
		(*file) = check_rev((*file), ignore_r);
	if (!(*file))
		return (0);
	return (1);
}

void		choose_view(t_file *file)
{
	if (IS_OP(L))
		show_l(file);
	else if (IS_OP(X))
		show_x(file);
	else
		show_one(file);
}

void		no_args(char ***tab)
{
	*tab = malloc(sizeof(char*) * 2);
	if (!(*tab))
		return ;
	(*tab)[0] = ".";
	(*tab)[1] = NULL;
}

static void	manage_options(char *arg, t_stat info)
{
	t_file	*file;
	int		flag_a;

	flag_a = 0;
	file = NULL;
	if (IS_OP(UR) && S_ISDIR(info.st_mode) && (info.st_mode & S_IXUSR))
		recursive(arg, 0);
	else if (S_ISDIR(info.st_mode) && !IS_OP(D))
		file = get_dir(arg);
	else
	{
		file = get_single_file(arg);
		flag_a = A;
	}
	if (file)
	{
		g_options |= flag_a;
		choose_view(file);
		if (flag_a)
			g_options -= flag_a;
		free_dir(file);
	}
}

void		print_args(char **args)
{
	int		i;
	int		ret;
	int		arg_shown;
	t_stat	info;

	i = 0;
	arg_shown = 0;
	while (args[i])
	{
		ret = (IS_OP(L)) ? lstat(args[i], &info) : stat(args[i], &info);
		if (ret != 0)
			ret = lstat(args[i], &info);
		if (ret == 0)
		{
			if (count_args(args) > 1 && S_ISDIR(info.st_mode))
			{
				if (arg_shown > 0)
					ft_printfast("\n");
				ft_printfast("%s:\n", args[i]);
			}
			manage_options(args[i], info);
			arg_shown++;
		}
		i++;
	}
}
