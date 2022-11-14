/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:32:39 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/13 21:41:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

t_info	*init_t_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->from = 0;
	info->to = 0;
	info->val_from = 0;
	info->dir_b = 'u';
	info->dir_a = 'u';
	return (info);
}

void	set_temp_info(t_stack *a, t_stack *b, t_info *temp, int idx)
{
	temp->from = idx;
	temp->val_from = b->arr[idx];
	temp->val_to = get_min_bigger_than_val(a, temp->val_from);
	temp->to = get_idx_of_val(a, temp->val_to);
}

void	set_info(t_info *temp, t_info *info)
{
	info->from = temp->from;
	info->to = temp->to;
	info->val_to = temp->val_to;
	info->val_from = temp->val_from;
	info->dir_b = temp->dir_b;
	info->dir_a = temp->dir_a;
}
