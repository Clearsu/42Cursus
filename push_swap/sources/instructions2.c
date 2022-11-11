/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:00:25 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/11 18:56:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

void	rotate_untill_idx(t_stack *stack, int idx)
{
	while (stack->tnx != idx)
	{
		rotate(stack);
		ft_printf("r%c\n", stack->name);
	}
}

void	r_rotate_untill_idx(t_stack *stack, int idx)
{
	while (stack->tnx != idx)
	{
		r_rotate(stack);
		ft_printf("rr%c\n", stack->name);
	}
}

void	rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info)
{
	while (info->to != a->tnx || info->from != b->tnx)
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
	rotate_untill_idx(a, info->to);
	rotate_untill_idx(b, info->from);
}

void	r_rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info)
{
	while (info->to != a->tnx || info->from != b->tnx)
	{
		r_rotate(a);
		r_rotate(b);
		ft_printf("rrr\n");
	}
	r_rotate_untill_idx(a, info->to);
	r_rotate_untill_idx(b, info->from);
}
