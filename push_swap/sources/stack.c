/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 16:27:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack(t_stack *stack, int size)
{
	stack->stack = (int *)malloc(sizeof(int) * (size + 1));
	if (stack->stack)
		return (0);
	stack->bottom = 0;
	stack->top = 0;
	stack->size = size;
	return (1);
}

int	is_stack_full(t_stack *stack)
{
	if ((stack->top + 1) % stack->size  == stack->bottom)
		return (1);
	return (0);
}

int is_stack_empty(t_stack *stack)
{
	if (stack->bottom == stack->top)
		return (1);
	return (0);
}

void	increase_idx(t_stack *stack, char c)
{
	if (c == 't')
	{
		if (stack->top == stack->size - 1)
			stack->top = 0;
		else
			stack->top++;
	}
	else if (c == 'b')
	{
		if (stack->bottom == stack->size - 1)
			stack->bottom = 0;
		else
			stack->bottom++;
	}
}

void	decrease_idx(t_stack *stack, char c)
{
	if (c == 't')
	{
		if (stack->top == 0)
			stack->top = stack->size - 1;
		else
			stack->top--;
	}
	else if (c == 'b')
	{
		if (stack->bottom == 0)
			stack->bottom = stack->size - 1;
		else
			stack->bottom--;
	}
}
