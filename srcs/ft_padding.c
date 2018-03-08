/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_size(int n, int var)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	if (len > var)
		var = len;
	return (var);
}

static void		get_len_pwd(t_passwd *pwd, t_file *file, t_pad *pad)
{
	char	*tmp;

	if (pwd && !IS_OP(N))
	{
		if ((int)ft_strlen(pwd->pw_name) > pad->usr)
			pad->usr = (int)ft_strlen(pwd->pw_name);
	}
	else
	{
		tmp = ft_l_b(file->info.st_uid, 10);
		if ((int)ft_strlen(tmp) > pad->usr)
			pad->usr = (int)ft_strlen(tmp);
		free(tmp);
	}
}

static void		get_len_grp(t_group *grp, t_file *file, t_pad *pad)
{
	char	*tmp;

	if (grp && !IS_OP(N))
	{
		if ((int)ft_strlen(grp->gr_name) > pad->grp)
			pad->grp = (int)ft_strlen(grp->gr_name);
	}
	else
	{
		tmp = ft_l_b(file->info.st_gid, 10);
		if ((int)ft_strlen(tmp) > pad->grp)
			pad->grp = (int)ft_strlen(tmp);
		free(tmp);
	}
}

static void		init_pad(t_pad *pad)
{
	pad->nlink = 0;
	pad->usr = 0;
	pad->grp = 0;
	pad->size = 0;
	pad->blk = 0;
	pad->tab = 0;
	pad->dev_major = 3;
	pad->dev_minor = 4;
	pad->nodes = 0;
	pad->file_shown = 0;
}

void			get_padding(t_file *file, t_pad *pad)
{
	t_file			*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	init_pad(pad);
	tmp = file;
	while (tmp)
	{
		if (!skip_hidden_files(&tmp, 1))
			break ;
		pwd = getpwuid(tmp->info.st_uid);
		grp = getgrgid(tmp->info.st_gid);
		pad->blk += tmp->info.st_blocks;
		get_len_pwd(pwd, tmp, pad);
		get_len_grp(grp, tmp, pad);
		pad->size = get_size(tmp->info.st_size, pad->size);
		pad->nlink = get_size(tmp->info.st_nlink, pad->nlink);
		pad->nodes = get_size(tmp->info.st_ino, pad->nodes);
		if ((int)ft_strlen(tmp->filename) > pad->tab)
			pad->tab = (int)ft_strlen(tmp->filename);
		pad->file_shown++;
		tmp = tmp->next;
	}
}
