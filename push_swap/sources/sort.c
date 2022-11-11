/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 02:18:52 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	pb_by_size(t_stack *a, t_stack *b)
{
	int	i;
	int	max;
	int	min;
	int	pivot;

	i = 2;
	max = get_max(a);
	min = get_min(a);
	pivot = (max - min) / 3 + min;
	while (i-- > 0)
	{
		while (is_smaller_n_exist(a, pivot) && a->n > 3)
		{
			while (a->arr[a->tnx] > pivot)
				rotate(a);
			push(a, b);
		}
		while (i == 0 && a->n > 3)
			push(a, b);
		if (a->n == 3)
		{
			sort_132(a);
			break ;
		}
		pivot = ((max - min) * 2) / 3 + min;
	}
}

t_info *init_t_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->from = 0;
	info->to = 0;
	info->val_from = 0;
	info->dir_b = '\0';
	info->dir_a = '\0';
	return (info);
}

void	get_shortest_case(t_stack *a, t_stack *b, t_info *info)
{
	t_info	*temp;
	int	dis;
	int	dis_a;
	int	dis_b;
	int	min_dis;
	int	i;

	temp = init_t_info();
	i = b->tnx;
	while (i != b->bnx)
	{
		dis_b = get_dis_b(b, i, temp);
		temp->val_from = b->arr[i];
		dis_a = get_dis_a(a, temp);
		dis = dis_a + dis_b;
		if (temp->val_from > get_max(a))
		{
			temp->val_to = get_min(a);
			temp->to = get_idx_of_val(a, temp->val_to);
		}
		if (dis < min_dis)
		{
			min_dis = dis;
			info->from = i;
			info->to = temp->to;
			info->val_to = temp->val_to;
			info->val_from = temp->val_from;
			info->dir_b = temp->dir_b;
			info->dir_a = temp->dir_a;
		}
		i = get_new_idx(i, '+', b->size);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	t_info	*info;
	int		max;

	info = init_t_info();
	info->val_max = get_max(a);
	pb_by_size(a, b);
	while (b->n > 0)
	{
		get_shortest_case(a, b, info);	
		move_stacks(a, b, info);
		push(b, a);
		if (a->arr[a->tnx] == info->val_max)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		print_stacks(a, b, info);
	}
	max = get_max(a);
	while (a->arr[a->bot] < max)
	{
		r_rotate(a);
		ft_printf("rra\n");
	}
	printf("    Final state\n\n");
	print_stacks(a, b, info);
}
