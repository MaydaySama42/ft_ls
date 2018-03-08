/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 07:14:17 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/12 03:23:47 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_char(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

static int	check_size(const char *str, unsigned int *index)
{
	unsigned int	i;
	int				nb_space;

	i = 0;
	nb_space = 0;
	while (check_char(str[i]))
	{
		nb_space++;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	*index = i;
	i = ft_strlen(str) - 1;
	while (check_char(str[i]))
	{
		nb_space++;
		i--;
	}
	return (ft_strlen(str) - nb_space);
}

char		*ft_strtrim(const char *s)
{
	char			*str;
	int				size;
	unsigned int	start;

	start = 0;
	if (!s)
		return (NULL);
	if ((size = check_size(s, &start)) == -1)
		return (ft_strdup(""));
	if ((str = ft_strsub(s, start, size)) == 0)
		return (NULL);
	return (str);
}
