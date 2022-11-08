/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 14:31:27 by jincpark         ###   ########.fr       */
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
	stack->size = size + 1;
	return (1);
}

int	is_stack_full(int bottom, int top, int size)
{
	if ((top + 1) % size == bottom)
		return (1);
	return (0);
}

int is_stack_empty(t_stack *stack)
{
	if (stack->bottom == stack->top)
		return (1);
	return (0);
}

int is_top_edge(int size, int top)
{
	 
}
