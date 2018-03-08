/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:01:18 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/11 05:07:23 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen(find) == 0)
		return ((char*)str);
	while (str[i] && i < len)
	{
		while (find[j] == str[i + j] && i + j < len)
		{
			if (j == ft_strlen(find) - 1)
				return ((char*)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
