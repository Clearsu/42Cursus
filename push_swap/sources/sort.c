/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/13 19:34:17 by jincpark         ###   ########.fr       */
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
		a_rotate_opt(a, pivot2);
	}
	while (a->n > 3)
		push(a, b);
	sort_132(a);
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
	min_dis = get_dis_a(a, temp) + get_dis_b(b, temp);
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

void	sort(t_stack *a, t_stack *b)
{
	t_info	*info;

	if (a->size == 3)
	{
		swap(a);
		return ;
	}
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
