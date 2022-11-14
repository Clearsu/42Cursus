/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:22:01 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:29:10 by jincpark         ###   ########.fr       */
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
		ft_printf("s%c\n", stack->name);
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
		{
			swap(stack); //2 1 3
			ft_printf("s%c\n", stack->name);
		}
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
		ft_printf("s%c\n", stack->name);
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
		ft_printf("pb\n");
		sort_3(a);
		push(b, a);
		ft_printf("pa\n");
	}
	else
	{
		r_rotate_untill_val_on_tnx(a, min);
		push(a, b);
		ft_printf("pb\n");
		sort_3(a);
		push(b, a);
		ft_printf("pa\n");
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	min_idx;

	min = get_min(a);
	min_idx = get_idx_of_val(a, min);
	if (is_closer_from_top(a, min_idx))
		rotate_untill_val_on_tnx(a, min);
	else
		r_rotate_untill_val_on_tnx(a, min);
	push(a, b);
	ft_printf("pb\n");
	sort_4(a, b);
	push(b, a);
	ft_printf("pa\n");
}
