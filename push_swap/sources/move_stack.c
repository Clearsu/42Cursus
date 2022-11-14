/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:29:12 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 20:51:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	move_same_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u')
		rotate_together_untill_end(a, b, info);
	if (info->dir_a == 'd')
		r_rotate_together_untill_end(a, b, info);
}

void	move_opposite_dir(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == 'u' && info->dir_b == 'd')
	{
		rotate_untill_val_on_tnx(a, info->val_to);
		r_rotate_untill_val_on_tnx(b, info->val_from);
	}
	if (info->dir_a == 'd' && info->dir_b == 'u')
	{
		r_rotate_untill_val_on_tnx(a, info->val_to);
		rotate_untill_val_on_tnx(b, info->val_from);
	}
}

void	move_stacks(t_stack *a, t_stack *b, t_info *info)
{
	if (info->dir_a == info->dir_b)
		move_same_dir(a, b, info);
	else
		move_opposite_dir(a, b, info);
}

void	last_rotate(t_stack *a, int max)
{
	int	i;

	i = get_idx_of_val(a, max);
	if (is_closer_from_top(a, i))
	{
		rotate_untill_val_on_tnx(a, max);
		rotate(a);
		ft_printf("ra\n");
	}
	else
		r_rotate_untill_val_on_bot(a, max);
}

void	a_rotate_opt(t_stack *a, int pivot)
{
	int	i_top;
	int	i_bot;

	i_top = get_first_idx_smaller_from_top(a, pivot);
	i_bot = get_first_idx_smaller_from_bot(a, pivot);
	if (get_distance_top(a, i_top) <= get_distance_bot(a, i_bot))
		rotate_untill_val_on_tnx(a, a->arr[i_top]);
	else
		r_rotate_untill_val_on_tnx(a, a->arr[i_bot]);
}
