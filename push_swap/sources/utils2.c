/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:12:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 01:17:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	get_idx_of_val(t_stack *stack, int val)
{
	int	i;

	i = stack->tnx;
	while (i != stack->bnx)
	{
		if (stack->arr[i] == val)
			return (i);
		i = get_new_idx(i, '+', stack->size);
	}
	return (0);
}

void	get_min_bigger_than_val_from(t_stack *a, t_info *info)
{
	int	i;

	i = a->tnx;
	info->val_to = get_max(a);
	if (info->val_from == info->val_max)
	{
		info->val_to = get_min(a);
		info->to = get_idx_of_val(a, info->val_to);
		return ;
	}
	while (i != a->bnx)
	{
		if (a->arr[i] > info->val_from && a->arr[i] < info->val_to)
		{
			info->val_to = a->arr[i];
			info->to = i;
		}
		i = get_new_idx(i, '+', a->size);
	}
}
