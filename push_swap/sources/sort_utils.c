/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:08:26 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->arr[stack->tnx];
	i = get_new_idx(stack->tnx, 'p', stack->size);
	while (i != stack->bnx)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i = get_new_idx(i, 'p', stack->size);
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	min = stack->arr[stack->tnx];
	i = get_new_idx(stack->tnx, 'p', stack->size);
	while (i != stack->bnx)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i = get_new_idx(i, 'p', stack->size);
	}
	return (min);
}

int	get_new_idx(int i, char c, int size)
{
	if (c == 'p')
	{
		if (i == size - 1)
			return (0);
		else
			return (i + 1);
	}
	else
	{
		if (i == 0)
			return (size - 1);
		else
			return (i - 1);
	}
}

int	is_smaller_n_exist(t_stack *stack, int n)
{
	int	i;

	i = stack->tnx;
	while (i != stack->bnx)
	{
		if (stack->arr[i] <= n)
			return (1);
		i = get_new_idx(i, 'p', stack->size);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->tnx;;
	while (i != stack->bot)
	{
		temp = get_new_idx(i, 'p', stack->size);
		if (stack->arr[i] > stack->arr[temp])
			return (0);
		i = temp;
	}
	return (1);
}
