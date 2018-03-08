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
#include <sys/xattr.h>
#include <sys/acl.h>

static char	check_xattr_acl(t_file *file)
{
	ssize_t		xattr;
	acl_t		acl;

	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(file->path, ACL_TYPE_EXTENDED);
	if (xattr > 0)
	{
		if (acl)
			acl_free((void*)acl);
		return ('@');
	}
	else if (acl)
	{
		acl_free((void*)acl);
		return ('+');
	}
	else
		return (' ');
}

static void	print_perm(t_file *file)
{
	char	perm[12];

	perm[0] = return_perm_type(file->info.st_mode);
	perm[1] = (file->info.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (file->info.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (file->info.st_mode & S_IXUSR) ? 'x' : '-';
	perm[3] = (file->info.st_mode & S_ISUID) ? 's' : perm[3];
	perm[4] = (file->info.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (file->info.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (file->info.st_mode & S_IXGRP) ? 'x' : '-';
	perm[6] = (file->info.st_mode & S_ISGID) ? 's' : perm[6];
	perm[7] = (file->info.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (file->info.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (file->info.st_mode & S_IXOTH) ? 'x' : '-';
	perm[9] = (file->info.st_mode & S_ISVTX) ? 't' : perm[9];
	perm[3] = ((file->info.st_mode & S_ISUID) &&
		!(file->info.st_mode & S_IXUSR)) ? 'S' : perm[3];
	perm[6] = ((file->info.st_mode & S_ISGID) &&
		!(file->info.st_mode & S_IXGRP)) ? 'S' : perm[6];
	perm[9] = ((file->info.st_mode & S_ISVTX) &&
		!(file->info.st_mode & S_IXOTH)) ? 'T' : perm[9];
	perm[10] = check_xattr_acl(file);
	perm[11] = 0;
	ft_printfast("%s ", perm);
}

static void	check_pwd_grp(t_file *file, t_pad pad, t_passwd *pwd, t_group *grp)
{
	char	*tmp;

	tmp = NULL;
	if (!IS_OP(G))
	{
		if (pwd && !IS_OP(N))
			ft_printfast("%-*s ", pad.usr + 1, pwd->pw_name);
		else
		{
			tmp = ft_l_b(file->info.st_uid, 10);
			ft_printfast("%-*s ", pad.usr + 1, tmp);
			free(tmp);
		}
	}
	if (!IS_OP(O))
	{
		if (grp && !IS_OP(N))
			ft_printfast("%-*s ", pad.grp + 1, grp->gr_name);
		else
		{
			tmp = ft_l_b(file->info.st_gid, 10);
			ft_printfast("%-*s ", pad.grp + 1, tmp);
			free(tmp);
		}
	}
}

static void	print_file(t_file *file, t_pad pad, t_passwd *pwd, t_group *grp)
{
	char	link[PATH_MAX];

	print_perm(file);
	ft_printfast("%*d ", pad.nlink, file->info.st_nlink);
	check_pwd_grp(file, pad, pwd, grp);
	if (S_ISBLK(file->info.st_mode) || S_ISCHR(file->info.st_mode))
	{
		ft_printfast("%*d,", pad.dev_major, MAJOR(file->info.st_rdev));
		ft_printfast("%*d ", pad.dev_minor, MINOR(file->info.st_rdev));
	}
	else
		ft_printfast("%*l ", pad.size, file->info.st_size);
	print_time(file);
	ft_printfast(" %s", file->filename);
	if (S_ISLNK(file->info.st_mode))
	{
		ft_memset(link, 0, PATH_MAX);
		readlink(file->path, link, PATH_MAX);
		ft_printfast(" -> %s", link);
	}
	ft_printfast("\n");
}

void		show_l(t_file *file)
{
	t_passwd		*pwd;
	t_group			*grp;
	t_pad			pad;
	t_file			*begin;

	begin = file;
	get_padding(file, &pad);
	if (get_list_size(file, 1) > 1 && pad.file_shown)
		ft_printfast("total %d\n", pad.blk);
	file = (IS_OP(R)) ? get_last_file(file) : file;
	while (file)
	{
		if (!skip_hidden_files(&file, 0))
			break ;
		if (IS_OP(I))
			ft_printfast("%*d ", pad.nodes, file->info.st_ino);
		pwd = getpwuid(file->info.st_uid);
		grp = getgrgid(file->info.st_gid);
		print_file(file, pad, pwd, grp);
		file = check_rev(file, 0);
	}
	file = begin;
}
