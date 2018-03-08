/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swap_far(t_file *a, t_file *b)
{
	t_file *p;
	t_file *n;

	n = b->next;
	p = b->prev;
	b->prev = a->prev;
	b->next = a->next;
	a->prev = p;
	a->next = n;
	if (b->next != NULL)
		b->next->prev = b;
	if (b->prev != NULL)
		b->prev->next = b;
	if (a->next != NULL)
		a->next->prev = a;
	if (a->prev != NULL)
		a->prev->next = a;
}

static void		swap_next(t_file *a, t_file *b)
{
	a->next = b->next;
	b->prev = a->prev;
	if (a->next != NULL)
		a->next->prev = a;
	if (b->prev != NULL)
		b->prev->next = b;
	b->next = a;
	a->prev = b;
}

t_file			*sort_ascii(t_file *file, int size)
{
	int		i;
	t_file	*tmp;
	t_file	*tmp_side;

	i = 0;
	tmp_side = file;
	tmp = file;
	while (tmp && i <= size)
	{
		if (!skip_hidden_files(&tmp, 1))
			break ;
		if (ft_strcmp(tmp_side->filename, tmp->filename) < 0)
			tmp_side = tmp;
		tmp = tmp->next;
		i++;
	}
	if (i == 0)
		return (NULL);
	return (tmp_side);
}

void			file_time_sort(t_file **file)
{
	t_file	*tmp;

	tmp = *file;
	while (tmp->next)
	{
		if ((get_time(tmp->info) - get_time(tmp->next->info)) < 0)
		{
			swap_next(tmp, tmp->next);
			tmp = get_first_file(tmp);
		}
		else
			tmp = tmp->next;
	}
	*file = get_first_file(tmp);
}

void			insertion_alpha_sort(t_file **file)
{
	t_file	*tmp;
	t_file	*tmp_side;
	int		size;

	size = get_list_size(*file, 0) - 1;
	tmp = (*file);
	while ((tmp_side = sort_ascii(tmp, size)))
	{
		if (tmp_side->next)
		{
			if (tmp_side->next == get_file_at(tmp, size))
				swap_next(tmp_side, get_file_at(tmp, size));
			else
				swap_far(tmp_side, get_file_at(tmp, size));
			tmp = get_first_file(*file);
		}
		size--;
	}
	(*file) = get_first_file((*file));
	if (IS_OP(T))
		file_time_sort(file);
}
