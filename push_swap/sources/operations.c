/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 16:23:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = temp;
}

void	push(t_stack *stack1, t_stack *stack2)
{
	int	temp;

	if (is_stack_empty(stack1))
		return ;
	temp = stack1->stack[stack1->top];
	decrease_idx(stack1, 't');
	increase_idx(stack2, 't');
	stack2->stack[stack2->top] = temp;
}

void	rotate(t_stack *stack)
{
	int	temp;

	temp = stack->stack[stack->top];
	decrease_idx(stack, 't');
	decrease_idx(stack, 'b');
	stack->stack[stack->bottom] = temp;	
}

void	r_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->stack[stack->bottom];
	increase_idx(stack, 't');
	increase_idx(stack, 'b');
	stack->stack[stack->top] = temp;
}
