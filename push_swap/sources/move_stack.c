/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:29:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/11 18:36:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	move_same_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u')
		rotate_together_untill_end(a, b, info);
	else
		r_rotate_together_untill_end(a, b, info);
}

void	move_opposite_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u')
	{
		rotate_untill_idx(a, info->to);
		r_rotate_untill_idx(b, info->from);
	}
	else
	{
		r_rotate_untill_idx(a, info->to);
		rotate_untill_idx(b, info->from);
	}
}

void	move_stacks(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == info->dir_b)
		move_same_dir(a, b, info);
	else
		move_opposite_dir(a, b, info);
}
