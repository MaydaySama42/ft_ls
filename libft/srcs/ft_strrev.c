/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:44:45 by mdalil            #+#    #+#             */
/*   Updated: 2017/12/18 17:47:27 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		ft_char_swap(&str[start], &str[end]);
		start++;
		end--;
	}
	return (str);
}
