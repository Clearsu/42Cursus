/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:01 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 14:16:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	sort_3xx(t_stack *stack)
{
	int	i;

	if (is_sorted(stack))
		return ;
	i = stack->tnx;
	i = get_new_idx(i, '+', stack->size);
	if (stack->arr[stack->tnx] > stack->arr[i] &&
			stack->arr[i] > stack->arr[stack->bot])
	{
		swap(stack); // 3 2 1
		r_rotate(stack);
		ft_printf("rr%c\n", stack->name);
	}
	else // 3 1 2
	{
		rotate(stack);
		ft_printf("r%c\n", stack->name);
	}
}

void	sort_2xx(t_stack *stack)
{
	int	i;

	if (is_sorted(stack))
		return ;	
	i = stack->tnx;
	i = get_new_idx(i, '+', stack->size);
	if (stack->arr[stack->tnx] > stack->arr[i])
	{
		if (stack->arr[stack->tnx] < stack->arr[stack->bot])
			swap(stack); //2 1 3
	}
	else if (stack->arr[stack->tnx] > stack->arr[stack->bot])
	{
		r_rotate(stack); // 2 3 1
		ft_printf("rr%c\n", stack->name);
	}
	sort_3xx(stack);
}

void	sort_3(t_stack *stack)
{
	int	i;

	if (is_sorted(stack))
		return ;	
	i = stack->tnx;
	i = get_new_idx(i, '+', stack->size);
	if (stack->arr[stack->tnx] < stack->arr[i] &&
			stack->arr[stack->tnx] < stack->arr[stack->bot])
	{
		r_rotate(stack);
		ft_printf("rr%c\n", stack->name);
		swap(stack);
	}
	sort_2xx(stack);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min;

	min = get_min(a);
	if (is_closer_from_top(a, get_idx_of_val(a, min)))
	{
		rotate_untill_val_on_tnx(a, min);
		push(a, b);
		sort_3(a);
		push(b, a);
	}
	else
	{
		r_rotate_untill_val_on_tnx(a, min);
		push(a, b);
		sort_3(a);
		push(b, a);
	}
}

void	rotate_push_min_and_2nd_min(t_stack *a, t_stack *b, int min_idx, int min_2nd_idx)
{
	int	min_dis_top;
	int	min_dis_bot;
	int	min_2nd_dis_top;
	int min_2nd_dis_bot;

	min_dis_top = get_distance_top(a, min_idx);
	min_dis_bot = get_distance_bot(a, min_idx);
	min_2nd_dis_top = get_distance_top(a, min_2nd_idx);
	min_2nd_dis_bot = get_distance_top(a, min_2nd_idx);
	if (min_dis_top <= min_dis_bot)
	{
		if (min_2nd_dis_top < min_dis_top)
		{
			rotate_untill_val_on_tnx(a, a->arr[min_2nd_idx]);
			push(a, b);
			rotate_untill_val_on_tnx(a, a->arr[min_idx]);
			push(a, b);
		}
		else
		{
			rotate_untill_val_on_tnx(a, a->arr[min_idx]);
			push(a, b);
			rotate_untill_val_on_tnx(a, a->arr[min_2nd_idx]);
			push(a, b);
		}
	}
	else
	{
		if (min_2nd_dis_bot < min_dis_bot)
		{
			r_rotate_untill_val_on_tnx(a, a->arr[min_2nd_idx]);
			push(a, b);
			r_rotate_untill_val_on_tnx(a, a->arr[min_idx]);
			push(a, b);
		}
		else
		{
			r_rotate_untill_val_on_tnx(a, a->arr[min_2nd_idx]);
			push(a, b);
			r_rotate_untill_val_on_tnx(a, a->arr[min_idx]);
			push(a, b);
		}
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	min_2nd;
	int	min_idx;
	int	min_2nd_idx;

	min = get_min(a);
	min_2nd = get_min_bigger_than_val(a, min);
	min_idx = get_idx_of_val(a, min);
	min_2nd_idx = get_idx_of_val(a, min_2nd);
	rotate_push_min_and_2nd_min(a, b, min_idx, min_2nd_idx);
	sort_3(a);
	if (b->arr[0] > b->arr[5])
		swap(b);
	push(b, a);
	push(b, a);
}
