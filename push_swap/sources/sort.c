/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:14:31 by jincpark         ###   ########.fr       */
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

void	get_shortest_case(t_stack *a, t_stack *b, t_from_to *from_to)
{
	int	i;

	i = b->tnx;
}

void	sort(t_stack *a, t_stack *b)
{
	t_from_to	from_to;

	pb_by_size(a, b);
	sort_3(a);
	while (b->n > 0)
	{
		get_shortest_case(a, b, &from_to);	
		move_stacks(a, b, from_to);
	}
}
