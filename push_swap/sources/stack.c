/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:09:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->arr = (int *)malloc(sizeof(int) * (size + 1));
	stack->top = 0;
	stack->tvi = 1;
	stack->bot = 0;
	stack->bnx = 1;
	stack->size = size + 1;
	stack->n = 0;
	return (stack);
}

int	is_stack_full(t_stack *stack)
{
	if (stack->n == stack->size - 1)
		return (1);
	return (0);
}

int	is_stack_empty(t_stack *stack)
{
	if (stack->top == stack->bot)
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
		if (stack->bot == stack->size - 1)
			stack->bot = 0;
		else
			stack->bot++;
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
		if (stack->bot == 0)
			stack->bot = stack->size - 1;
		else
			stack->bot--;
	}
}
