/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_folder_name(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	while (i > 0)
	{
		if (path[i] == '/')
			return (path + i + 1);
		i--;
	}
	return (path);
}

t_file			*get_single_file(char *path)
{
	t_file	*file;

	CHECK((file = malloc(sizeof(t_file))));
	file->filename = ft_strdup(path);
	file->path = ft_strdup(path);
	lstat(file->path, &(file->info));
	file->prev = NULL;
	file->next = NULL;
	return (file);
}

static t_file	*get_file_to_dir(t_dirent *name, char *path)
{
	t_file	*file;

	CHECK((file = malloc(sizeof(t_file))));
	file->filename = ft_strdup(name->d_name);
	file->path = ft_strnew(ft_strlen(path) + ft_strlen(file->filename) + 1);
	ft_strcat(file->path, path);
	ft_strcat(file->path, "/");
	ft_strcat(file->path, file->filename);
	lstat(file->path, &(file->info));
	file->prev = NULL;
	file->next = NULL;
	return (file);
}

static int		check_x_right(char *path)
{
	t_stat	info;

	lstat(path, &info);
	if (!(info.st_mode & S_IXUSR))
		return (-1);
	return (0);
}

t_file			*get_dir(char *path)
{
	t_dirent	*name;
	DIR			*rep;
	t_file		*dir;
	t_file		*begin;

	if (!(rep = opendir(path)))
		ft_printfast("ls: %s: %s\n", get_folder_name(path), strerror(errno));
	if (!rep || check_x_right(path) == -1)
		return (NULL);
	name = readdir(rep);
	dir = get_file_to_dir(name, path);
	begin = dir;
	while ((name = readdir(rep)))
	{
		dir->next = get_file_to_dir(name, path);
		dir->next->prev = dir;
		dir = dir->next;
	}
	closedir(rep);
	if (!IS_OP(F))
		insertion_alpha_sort(&begin);
	return (begin);
}
