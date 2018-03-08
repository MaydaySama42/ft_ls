/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_one(t_file *file)
{
	t_file	*tmp;
	t_pad	pad;

	tmp = file;
	get_padding(tmp, &pad);
	tmp = (IS_OP(R)) ? get_last_file(tmp) : tmp;
	while (tmp)
	{
		if (!skip_hidden_files(&tmp, 0))
			break ;
		if (IS_OP(I))
			ft_printfast("%-*d ", pad.nodes, tmp->info.st_ino);
		ft_printfast("%s\n", tmp->filename);
		tmp = check_rev(tmp, 0);
	}
}
