/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:00:25 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/13 05:45:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

void	rotate_untill_val_on_tnx(t_stack *stack, int val)
{
	while (stack->arr[stack->tnx] != val)
	{
		rotate(stack);
		ft_printf("r%c\n", stack->name);
	}
}

void	r_rotate_untill_val_on_tnx(t_stack *stack, int val)
{
	while (stack->arr[stack->tnx] != val)
	{
		r_rotate(stack);
		ft_printf("rr%c\n", stack->name);
	}
}

void	r_rotate_untill_val_on_bot(t_stack *stack, int val)
{
	while (stack->arr[stack->bot] != val)
	{
		r_rotate(stack);
		ft_printf("rr%c\n", stack->name);
	}
}

void	rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info)
{
	while (info->val_to != a->arr[a->tnx] && info->val_from != b->arr[b->tnx])
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
	rotate_untill_val_on_tnx(a, info->val_to);
	rotate_untill_val_on_tnx(b, info->val_from);
}

void	r_rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info)
{
	while (info->val_to != a->arr[a->tnx] && info->val_from != b->arr[b->tnx])
	{
		r_rotate(a);
		r_rotate(b);
		ft_printf("rrr\n");
	}
	r_rotate_untill_val_on_tnx(a, info->val_to);
	r_rotate_untill_val_on_tnx(b, info->val_from);
}
