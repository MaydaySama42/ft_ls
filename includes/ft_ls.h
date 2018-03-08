/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <time.h>
# include <limits.h>
# include "libft.h"

int						g_options;

# define OP_END			-2
# define OP_CHK_FILE	-1
# define OP_STR			"Racdfgilnortux1"
# define UR 			1
# define A				2
# define C				4
# define D				8
# define F				16
# define G				32
# define I				64
# define L				128
# define N				256
# define O				512
# define R				1024
# define T				2048
# define U				4096
# define X				8192
# define ONE			16384
# define IS_OP(x)		((g_options & x) > 0)
# define ARG_FILE		1
# define ARG_DIR		2

# define MAJOR(x)		((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINOR(x)		((int32_t)((x) & 0xffffff))

# define CHECK(x)		if (!x) return (NULL);

typedef	struct dirent	t_dirent;
typedef	struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef	struct			s_file
{
	char				*filename;
	char				*path;
	t_stat				info;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_pad
{
	int					nlink;
	int					usr;
	int					grp;
	int					size;
	int					tab;
	int					dev_major;
	int					dev_minor;
	int					nodes;
	int					file_shown;
	blkcnt_t			blk;
}						t_pad;

/*
**	time
*/
time_t					get_time(t_stat info);
void					print_time(t_file *file);
/*
**	manage options
*/
void					fill_option(char c);
void					check_is_opt(void);
/*
**	manage arguments
*/
char					pars_args(int ac, char **av, char ***tab);
int						count_args(char **args);
void					print_args(char **args);
void					no_args(char ***tab);
/*
**	sort args
*/
void					swap_args(char **s1, char **s2);
int						arg_type(char *str);
void					valid_args(char **args);
void					sort_type_args(char **args);
/*
**	manage files
*/
t_file					*get_single_file(char *path);
t_file					*get_dir(char *path);
void					free_file(t_file *file);
void					free_dir(t_file *file);
char					return_perm_type(mode_t st_mode);
char					ret_f_type(t_file *file);
/*
**	sort files
*/
int						skip_hidden_files(t_file **file, int ignore_r);
t_file					*check_rev(t_file *file, int ignore_r);
int						get_list_size(t_file *file, int real_size);
t_file					*get_file_at(t_file *file, int index);
t_file					*get_first_file(t_file *file);
t_file					*get_last_file(t_file *file);
t_file					*sort_ascii(t_file *file, int size);
void					file_time_sort(t_file **file);
void					insertion_alpha_sort(t_file **file);
/*
**	print files
*/
void					choose_view(t_file *file);
void					show_one(t_file *file);
void					show_l(t_file *file);
void					show_x(t_file *file);
void					recursive(char *path, char is_first);
/*
**	manage paddings
*/
void					get_padding(t_file *file, t_pad *pad);
void					get_tab_space(t_file *file, t_pad *pad);

#endif
