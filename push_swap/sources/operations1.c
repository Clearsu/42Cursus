/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 21:18:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;
	int	idx_temp;

	if (stack->n <= 1)
		return ;
	idx_temp = get_new_idx(stack->tnx, '+', stack->size);
	temp = stack->arr[stack->tnx];
	stack->arr[stack->tnx] = stack->arr[idx_temp];
	stack->arr[idx_temp] = temp;
}

void	push(t_stack *stack1, t_stack *stack2)
{
	if (is_stack_empty(stack1))
		return ;
	stack2->arr[stack2->top] = stack1->arr[stack1->tnx];
	increase_idx(stack1, 't');
	decrease_idx(stack2, 't');
	stack1->n--;
	stack2->n++;
}

void	rotate(t_stack *stack)
{
	if (stack->n <= 1)
		return ;
	stack->arr[stack->bnx] = stack->arr[stack->tnx];
	increase_idx(stack, 't');
	increase_idx(stack, 'b');
}

void	r_rotate(t_stack *stack)
{
	if (stack->n <= 1)
		return ;
	stack->arr[stack->top] = stack->arr[stack->bot];
	decrease_idx(stack, 't');
	decrease_idx(stack, 'b');
}
