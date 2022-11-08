/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 14:42:21 by jincpark         ###   ########.fr       */
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
	if (is_stack_empty(stack2))
		return ;
	stack2->stack[--stack2->top] = stack1->stack[stack1->top++];
}

void	rotate(t_stack *stack)
{
	stack->stack[stack->bottom] = stack->stack[stack->top--];	
}

void	r_rotate(t_stack *stack)
{
	stack->stack[++stack->top] = stack->stack[stack->bottom++];

