/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		check_options(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && (++i))
	{
		if (!str[i])
			return (OP_CHK_FILE);
		while (str[i])
		{
			if (str[i] == '-' && ft_strlen(str) == 2)
				return (OP_END);
			fill_option(str[i]);
			if (ft_strchr(OP_STR, str[i]) == NULL)
				return (str[i]);
			i++;
		}
	}
	else
		return (OP_CHK_FILE);
	return (0);
}

static	char	**fill_args(int ac, char **av, int idx)
{
	int		i;
	char	**tab;

	i = 0;
	if (ac - idx <= 0)
		return (NULL);
	tab = malloc(sizeof(char*) * ((ac - idx) + 1));
	while (idx < ac)
		tab[i++] = av[idx++];
	tab[i] = NULL;
	return (tab);
}

char			pars_args(int ac, char **av, char ***tab)
{
	int		i;
	char	ret;

	i = 1;
	while (i < ac)
	{
		ret = check_options(av[i]);
		if (ret == OP_END && (i++))
			break ;
		if (ret == OP_CHK_FILE)
			break ;
		if (ret > 0)
			return (ret);
		i++;
	}
	check_is_opt();
	*tab = fill_args(ac, av, i);
	return (0);
}
