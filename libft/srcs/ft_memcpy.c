/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:07:37 by mdalil            #+#    #+#             */
/*   Updated: 2017/11/09 05:59:35 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp1;
	unsigned char		*tmp2;

	i = 0;
	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (tmp1);
}
