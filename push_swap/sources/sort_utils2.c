/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:48:35 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:08:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int	is_closer_from_top(t_stack *stack, int idx)
{
	int	dis_top;
	int	dis_bot;
	int	idx_cp;

	dis_top = 0;
	dis_bot = 0;
	while (idx != stack->top)
	{
		idx = get_new_idx(idx, 'm', stack->size);
		dis_top++;
	}
	while (idx_cp != stack->bnx)
	{
		idx_cp = get_new_idx(idx_cp, 'p', stack->size);
		dis_bot++;
	}
	if (dis_top >= dis_bot)
		return (1);
	return (0);
}


