/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_file(t_file *file)
{
	file->next = NULL;
	file->prev = NULL;
	free(file->filename);
	free(file->path);
	file->filename = NULL;
	file->path = NULL;
	free(file);
	file = NULL;
}

void	free_dir(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file->next;
		free_file(file);
		file = tmp;
	}
}
