/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:57:12 by mdalil            #+#    #+#             */
/*   Updated: 2018/02/21 16:57:14 by mdalil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		check_opt_priority(int flag)
{
	if (flag == L)
		g_options -= (IS_OP(X)) ? X : 0;
	else if (flag == F)
		g_options |= A;
	else if (flag == X)
		g_options -= (IS_OP(L)) ? L : 0;
	else if (flag == C)
		g_options -= (IS_OP(U)) ? U : 0;
	else if (flag == U)
		g_options -= (IS_OP(C)) ? C : 0;
}

void			fill_option(char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (OP_STR[i])
	{
		if (c == OP_STR[i])
		{
			index = ft_recursive_power(2, i++);
			g_options |= index;
			check_opt_priority(index);
			return ;
		}
		i++;
	}
}

void			check_is_opt(void)
{
	if (IS_OP(F) && IS_OP(R))
		g_options -= R;
	if (IS_OP(D) && IS_OP(UR))
		g_options -= UR;
	if (IS_OP(G) || IS_OP(O))
		check_opt_priority(L);
}
