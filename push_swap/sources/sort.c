/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 23:15:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	pb_by_size(t_stack *a, t_stack *b, int pivot1, int pivot2)
{
	while (is_smaller_n_exist(a, pivot2) && a->n > 3)
	{
		if (a->arr[a->tnx] <= pivot2)
		{
			push(a, b);
			ft_printf("pb\n");
			if (b->arr[b->tnx] <= pivot1 && a->n > 3)
			{
				rotate(b);
				ft_printf("rb\n");
			}
		}
		if (a->n > 3 && is_smaller_n_exist(a, pivot2))
			a_rotate_opt(a, pivot2);
	}
	while (a->n > 3)
	{
		push(a, b);
		ft_printf("pb\n");
	}
	sort_3(a);
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
	min_dis = get_dis_set_dir_a(a, temp) + get_dis_set_dir_b(b, temp);
	set_info(temp, info);
	while (i != b->bnx)
	{
		dis = get_dis_set_dir_a(a, temp) + get_dis_set_dir_b(b, temp);
		if (dis < min_dis)
		{
			min_dis = dis;
			set_info(temp, info);
		}
		i = get_new_idx(i, '+', b->size);
		set_temp_info(a, b, temp, i);
	}
	free(temp);
}

void	sort(t_stack *a, t_stack *b)
{
	t_info	*info;
	int		pivot1;
	int		pivot2;

	if (a->size <= 6)
		sort_small(a, b);
	info = init_t_info();
	pivot1 = get_pivot(a, a->size / 3);
	pivot2 = get_pivot(a, a->size * 2 / 3);
	pb_by_size(a, b, pivot1, pivot2);
	while (b->n > 0)
	{
		get_shortest_case(a, b, info);
		move_stacks(a, b, info);
		push(b, a);
		ft_printf("pa\n");
		if (a->arr[a->tnx] == get_max(a))
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
	last_rotate(a, get_max(a));
	free(info);
}
