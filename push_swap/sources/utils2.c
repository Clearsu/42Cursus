/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:12:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 03:47:18 by jincpark         ###   ########.fr       */
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

int	get_min_bigger_than_val_from(t_stack *a, t_info *temp)
{
	int	i;
	int	min;

	i = a->tnx;
	min = get_max(a);
	if (temp->val_from > min)
		return (get_min(a));
	while (i != a->bnx)
	{
		if (a->arr[i] > temp->val_from && a->arr[i] < min)
			min = a->arr[i];
		i = get_new_idx(i, '+', a->size);
	}
	return (min);
}
