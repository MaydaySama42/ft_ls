/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 06:08:39 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/12 03:21:24 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = (char*)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
