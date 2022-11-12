/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/13 05:28:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	pb_by_size(t_stack *a, t_stack *b)
{
	int	pivot1;
	int	pivot2;

	pivot1 = get_pivot(a, 1);
	pivot2 = get_pivot(a, 2);
	while (is_smaller_n_exist(a, pivot2) && a->n > 3)
	{
		if (a->arr[a->tnx] <= pivot2)
		{
			push(a, b);
			if (b->arr[b->tnx] <= pivot1)
			{
				rotate(b);
				ft_printf("rb\n");
			}
		}
		rotate(a);
		ft_printf("ra\n");
	}
	while (a->n > 3)
		push(a, b);
	sort_132(a);
}

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
	temp->val_to = get_min_bigger_than_val_from(a, temp);
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

void	get_shortest_case(t_stack *a, t_stack *b, t_info *info)
{
	t_info	*temp;
	int		dis;
	int		min_dis;
	int		i;

	temp = init_t_info();
	i = b->tnx;
	set_temp_info(a, b, temp, i);
	min_dis = 2147483647;
	set_info(temp, info);
	while (i != b->bnx)
	{
		dis = get_dis_a(a, temp) + get_dis_b(b, temp);
		if (dis < min_dis)
		{
			min_dis = dis;
			set_info(temp, info);
		}
		i = get_new_idx(i, '+', b->size);
		set_temp_info(a, b, temp, i);
	}
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

void	sort(t_stack *a, t_stack *b)
{
	t_info	*info;

	info = init_t_info();
	pb_by_size(a, b);
	while (b->n > 0)
	{
		get_shortest_case(a, b, info);	
		move_stacks(a, b, info);
		push(b, a);
		if (a->arr[a->tnx] == get_max(a))
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
	last_rotate(a, get_max(a));
}
