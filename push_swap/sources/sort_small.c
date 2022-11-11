/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:12:51 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/11 20:55:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

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

void	sort_132(t_stack *stack)
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
