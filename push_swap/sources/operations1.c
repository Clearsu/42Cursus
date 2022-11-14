/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:29:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp1;
	int	temp2;

	if (stack->n <= 1)
		return ;
	increase_idx(stack, 't');
	temp1 = stack->arr[stack->top];
	increase_idx(stack, 't');
	temp2 = stack->arr[stack->top];
	stack->arr[stack->top] = temp1;
	decrease_idx(stack, 't');
	stack->arr[stack->top] = temp2;
	decrease_idx(stack, 't');
}

void	push(t_stack *stack1, t_stack *stack2)
{
	int	temp;

	if (is_stack_empty(stack1))
		return ;
	increase_idx(stack1, 't');
	temp = stack1->arr[stack1->top];
	stack1->arr[stack1->top] = 0;
	stack2->arr[stack2->top] = temp;
	decrease_idx(stack2, 't');
	stack2->arr[stack2->top] = 0;
	stack1->tnx = get_new_idx(stack1->tnx, '+', stack1->size);
	stack2->tnx = get_new_idx(stack2->tnx, '-', stack2->size);
	stack1->n--;
	stack2->n++;
}

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->n <= 1)
		return ;
	increase_idx(stack, 't');
	temp = stack->arr[stack->top];
	stack->arr[stack->top] = 0;
	increase_idx(stack, 'b');
	stack->arr[stack->bot] = temp;
	stack->tnx = get_new_idx(stack->tnx, '+', stack->size);
	stack->bnx = get_new_idx(stack->bnx, '+', stack->size);
}

void	r_rotate(t_stack *stack)
{
	int	temp;

	if (stack->n <= 1)
		return ;
	temp = stack->arr[stack->bot];
	stack->arr[stack->bot] = 0;
	decrease_idx(stack, 'b');
	stack->arr[stack->top] = temp;
	decrease_idx(stack, 't');
	stack->tnx = get_new_idx(stack->tnx, '-', stack->size);
	stack->bnx = get_new_idx(stack->bnx, '-', stack->size);
}
