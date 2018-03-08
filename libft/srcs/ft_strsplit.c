/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:48:56 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/13 05:43:41 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_char(const char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int i;
	int word;
	int check_space;
	int check_word;

	i = 0;
	word = 0;
	check_word = 0;
	while (str[i])
	{
		if (!check_char(str[i], c) && !check_word)
		{
			check_word = 1;
			check_space = 0;
			word++;
		}
		if (check_char(str[i], c) && !check_space)
		{
			check_word = 0;
			check_space = 1;
		}
		i++;
	}
	return (word);
}

static int	str_begin(const char *str, int i, char c, int *len)
{
	int begin;
	int check_space;
	int check_word;

	begin = 0;
	check_word = 0;
	check_space = 1;
	while (str[i])
	{
		if (!check_char(str[i], c) && check_word == 0)
		{
			check_word = 1;
			begin = i;
			while (!check_char(str[i], c) && str[i])
				i++;
			*len = i - begin;
			break ;
		}
		i++;
	}
	return (begin);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(tab) * (count_words(s, c) + 1))))
		return (NULL);
	while (i < count_words(s, c))
	{
		j = str_begin(s, j, c, &len);
		if ((tab[i] = ft_strsub(s, j, len)) == 0)
			return (NULL);
		j += len;
		i++;
	}
	tab[count_words(s, c)] = 0;
	return (tab);
}
