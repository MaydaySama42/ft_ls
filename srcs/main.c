/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	char	ret;
	char	**args;

	args = NULL;
	ret = pars_args(ac, av, &args);
	if (ret > 0)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(ret, 2);
		ft_putstr_fd("\nusage: ls [", 2);
		ft_putstr_fd(OP_STR, 2);
		ft_putstr_fd("] [file ...]\n", 2);
		return (1);
	}
	sort_type_args(args);
	if (!args)
		no_args(&args);
	print_args(args);
	free(args);
	return (0);
}
