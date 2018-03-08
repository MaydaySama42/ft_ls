/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:22:44 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/09 00:26:08 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)(s);
	while (tmp[i])
	{
		if (tmp[i] == c)
			return (tmp + i);
		i++;
	}
	if (tmp[i] == c)
		return (tmp + i);
	return (NULL);
}
