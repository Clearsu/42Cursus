/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/07 23:54:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->bottom];
	stack->stack[stack->bottom] = temp;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	
	stack2->stack[--stack2->top] = stack1->stack[stack1->top++];
}
