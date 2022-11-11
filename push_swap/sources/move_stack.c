/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:29:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 05:16:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	move_same_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u')
		rotate_together_untill_end(a, b, info);
	else if (info->dir_a == 'd')
		r_rotate_together_untill_end(a, b, info);
}

void	move_opposite_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u' && info->dir_b == 'd')
	{
		rotate_untill_val_on_tnx(a, info->val_to);
		r_rotate_untill_val_on_tnx(b, info->val_from);
	}
	else if (info->dir_a == 'd' && info->dir_b == 'u')
	{
		r_rotate_untill_val_on_tnx(a, info->val_to);
		rotate_untill_val_on_tnx(b, info->val_from);
	}
}

void	move_stacks(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == info->dir_b && b->n)
		move_same_dir(a, b, info);
	else
		move_opposite_dir(a, b, info);
}
