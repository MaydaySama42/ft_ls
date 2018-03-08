/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static int	get_line_size(t_file *file, t_pad pad)
{
	struct winsize	w;
	t_file			*tmp;
	int				total_line;
	int				padding;

	padding = pad.tab + 1;
	padding += (IS_OP(I)) ? pad.nodes + 1 : 0;
	ioctl(0, TIOCGWINSZ, &w);
	tmp = file;
	total_line = 0;
	while (total_line * padding < w.ws_col)
		total_line++;
	if (total_line * padding > w.ws_col)
		total_line -= 1;
	return (total_line);
}

void		show_x(t_file *file)
{
	t_file			*tmp;
	t_pad			pad;
	int				col_nb;
	int				i;

	tmp = file;
	get_padding(tmp, &pad);
	col_nb = get_line_size(tmp, pad);
	i = 0;
	tmp = (IS_OP(R)) ? get_last_file(tmp) : tmp;
	while (tmp)
	{
		if (!skip_hidden_files(&tmp, 0))
			break ;
		if (IS_OP(I))
			ft_printfast("%*d ", pad.nodes, tmp->info.st_ino);
		ft_printfast("%-*s", pad.tab + 1, tmp->filename);
		tmp = check_rev(tmp, 0);
		i++;
		if ((i %= col_nb) == 0)
			ft_printfast("\n");
	}
	if (pad.file_shown)
		ft_printfast("\n");
}
