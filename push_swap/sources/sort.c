/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/11 18:52:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

/*
필요한 함수
1. 최대, 최솟값 구하는 함수
2. 정렬된 위치에 가기까지 가장 적은 명령을 수행하는 값의 인덱스를 구하는 함수
2-1. 탑과 바텀 중 어디가 더 가까운지 구하는 함수
3. 그 위치까지 보내는 함수
   */

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
		while (is_smaller_n_exist(a, pivot))
		{
			while (a->arr[a->tnx] > pivot)
				rotate(a);
			push(a, b);
		}
		pivot = ((max - min) * 2) / 3 + min;
	}
	while (a->n > 3)
		push(a, b);
}
/*
typedef struct s_from_to
{
	int 	from;
	int		to;
	int		val_from;
	char	dir_b;
	char	dir_a;
}	t_from_to;
*/
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
		dis_a = get_dis_b(b, i, temp);
		temp->val_from = b->arr[i];
		dis_b = get_dis_a(a, temp);
		dis = dis_a + dis_b;
		if (dis < min_dis)
		{
			min_dis = dis;
			info->from = i;
			info->to = temp->to;
			info->dir_b = temp->dir_b;
			info->dir_a = temp->dir_a;
		}
		get_new_idx(i, '+', b->size);
	}
}



void	sort(t_stack *a, t_stack *b)
{
	t_info	*info;
	int		max;

	info = init_t_info();
	pb_by_size(a, b);
	sort_3(a);
	while (b->n > 0)
	{
		get_shortest_case(a, b, info);	
		move_stacks(a, b, info);
		push(b, a);
		ft_printf("pa\n");
	}
	max = get_max(a);
	while (a->arr[a->bot] < max)
		r_rotate(a);
}
