/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 21:20:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->arr = (int *)malloc(sizeof(int) * (size + 1));
	stack->top = 0;
	stack->tnx = 1;
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
		stack->top = get_new_idx(stack->top, '+', stack->size);
		stack->tnx = get_new_idx(stack->tnx, '+', stack->size);
	}
	else if (c == 'b')
	{
		stack->bot = get_new_idx(stack->bot, '+', stack->size);
		stack->bnx = get_new_idx(stack->bnx, '+', stack->size);
	}
}

void	decrease_idx(t_stack *stack, char c)
{
	if (c == 't')
	{
		stack->top = get_new_idx(stack->top, '-', stack->size);
		stack->tnx = get_new_idx(stack->tnx, '-', stack->size);
	}
	else if (c == 'b')
	{
		stack->bot = get_new_idx(stack->bot, '-', stack->size);
		stack->bnx = get_new_idx(stack->bnx, '-', stack->size);
	}
}
