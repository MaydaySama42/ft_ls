/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_dot(char *str)
{
	if (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0)
		return (1);
	return (0);
}

void		recursive(char *path, char is_first)
{
	t_file			*file;
	t_file			*temp;

	if (is_first)
		ft_printfast("\n%s:\n", path);
	if (!(file = get_dir(path)))
		return ;
	choose_view(file);
	file = (IS_OP(R)) ? get_last_file(file) : file;
	while (file)
	{
		while (file && file->filename[0] == '.' && !IS_OP(A))
		{
			temp = check_rev(file, 0);
			free_file(file);
			file = temp;
		}
		if (!file)
			break ;
		if (S_ISDIR(file->info.st_mode) && !is_dot(file->filename))
			recursive(file->path, 1);
		temp = check_rev(file, 0);
		free_file(file);
		file = temp;
	}
}
