/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:12:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/13 21:38:25 by jincpark         ###   ########.fr       */
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

int	get_min_bigger_than_val(t_stack *a, int val)
{
	int	i;
	int	min;

	i = a->tnx;
	min = get_max(a);
	if (val > min)
		return (get_min(a));
	while (i != a->bnx)
	{
		if (a->arr[i] > val && a->arr[i] < min)
			min = a->arr[i];
		i = get_new_idx(i, '+', a->size);
	}
	return (min);
}

int	get_pivot(t_stack *a, int n)
{
	int	i;
	int	j;
	int	min;
	int	prev_min;
	int	reps;

	prev_min = get_min(a);
	if (n == 1)
		reps = a->size / 3;
	else
		reps = a->size * 2 / 3;
	i = 1;
	while (i < reps)
	{
		j = 1;
		min = 2147483647;
		while (j < a->size)
		{
			if (a->arr[j] > prev_min && a->arr[j] < min)
				min = a->arr[j];
			j++;
		}
		prev_min = min;
		i++;
	}
	return (min);
}

int	get_first_idx_smaller_from_top(t_stack *stack, int pivot)
{
	int	i;

	i = stack->tnx;
	while (i != stack->bnx)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i = get_new_idx(i, '+', stack->size);
	}
	return (0);
}

int	get_first_idx_smaller_from_bot(t_stack *stack, int pivot)
{
	int	i;

	i = stack->bot;
	while (i != stack->top)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i = get_new_idx(i, '-', stack->size);
	}
	return (0);
}

