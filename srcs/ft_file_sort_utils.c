/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*get_file_at(t_file *file, int index)
{
	t_file	*tmp;
	int		i;

	tmp = file;
	i = 0;
	while (tmp)
	{
		if (!skip_hidden_files(&tmp, 1))
			break ;
		if (i == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

t_file		*get_first_file(t_file *file)
{
	t_file	*begin;
	t_file	*first;

	begin = file;
	while (file->prev)
		file = file->prev;
	first = file;
	file = begin;
	return (first);
}

t_file		*get_last_file(t_file *file)
{
	t_file	*begin;
	t_file	*last;

	begin = file;
	while (file->next)
		file = file->next;
	last = file;
	file = begin;
	return (last);
}

int			get_list_size(t_file *file, int real_size)
{
	t_file	*tmp;
	int		size;

	size = 0;
	tmp = file;
	while (tmp)
	{
		while (tmp && tmp->filename[0] == '.' && !IS_OP(A) && !real_size)
			tmp = tmp->next;
		if (!tmp)
			break ;
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_file		*check_rev(t_file *file, int ignore_r)
{
	t_file	*tmp;

	if (ignore_r)
		tmp = file->next;
	else
		tmp = (IS_OP(R)) ? file->prev : file->next;
	return (tmp);
}
