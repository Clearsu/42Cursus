/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:48:35 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 20:57:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "limits.h"

int	is_closer_from_top(t_stack *stack, int idx)
{
	int	dis_top;
	int	dis_bot;

	dis_top = get_distance_top(stack, idx);
	dis_bot = get_distance_bot(stack, idx);
	if (dis_top <= dis_bot)
		return (1);
	return (0);
}

int	get_distance_top(t_stack *stack, int idx)
{
	int	dis_top;

	dis_top = 0;
	while (idx != stack->tnx)
	{
		idx = get_new_idx(idx, '-', stack->size);
		dis_top++;
	}
	return (dis_top);
}

int	get_distance_bot(t_stack *stack, int idx)
{
	int	dis_bot;

	dis_bot = 0;
	while (idx != stack->bnx)
	{
		idx = get_new_idx(idx, '+', stack->size);
		dis_bot++;
	}
	return (dis_bot);
}

int	get_dis_set_dir_b(t_stack *b, t_info *temp)
{
	int	dis;

	if (is_closer_from_top(b, temp->from))
	{
		dis = get_distance_top(b, temp->from);
		temp->dir_b = 'u';
	}
	else
	{
		dis = get_distance_bot(b, temp->from);
		temp->dir_b = 'd';
	}
	return (dis);
}

int	get_dis_set_dir_a(t_stack *a, t_info *temp)
{
	int	dis;

	if (is_closer_from_top(a, temp->to))
	{
		dis = get_distance_top(a, temp->to);
		temp->dir_a = 'u';
	}
	else
	{
		dis = get_distance_bot(a, temp->to);
		temp->dir_a = 'd';
	}
	return (dis);
}
