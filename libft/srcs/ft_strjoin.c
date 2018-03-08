/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 05:14:08 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/18 13:08:27 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = (char*)malloc(sizeof(char) * (size))) == 0)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i] = s2[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
