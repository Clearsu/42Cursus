/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 23:56:58 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circle_queue.h"

void	re_init_from_zero(unsigned int *arr, unsigned int size)
{
	unsigned int	min;
	unsigned int	min_idx;
	unsigned int	i;
	unsigned int	j;

	min_idx = 1;
	i = 0;
	while (i < size)
	{
		j = 1;
		min = 0xFFFFFFFF;
		while (j < size + 1)
		{
			if (arr[j] <= min && arr[j] >= i)
			{
				min = arr[j];
				min_idx = j;
			}
			j++;
		}
		arr[min_idx] = i++;
	}
}

void	plusminus_i(unsigned int *i, char c, unsigned int size)
{
	if (c == 'p')
	{
		if (*i == size - 1)
			*i = 0;
		else
			(*i)++;
	}
	else if (c == 'm')
	{
		if (*i == 0)
			*i = size - 1;
		else
			(*i)--;
	}
}

unsigned int	get_max_idx(t_circle_queue *queue)
{
	unsigned int	i;
	unsigned int	max;
	unsigned int	max_idx;

	max = 0;
	i = queue->top;
	plusminus_i(&i, 'p', queue->size);
	while(i != queue->bot)
	{
		if (queue->arr[i] > max)
		{
			max = queue->arr[i];
			max_idx = i;
		}
		plusminus_i(&i, 'p', queue->size);
	}
	return (max_idx);
}

int	is_closer_from_top(unsigned int idx, t_circle_queue *queue)
{
	unsigned int	dis_top;
	unsigned int	dis_bot;
	unsigned int	idx_cp;

	dis_top = 0;
	dis_bot = 0;
	idx_cp = idx;
	while (idx != queue->top)
	{
		dis_top++;
		plusminus_i(&idx, 'm', queue->size);
	}
	dis_top--;
	while (idx_cp != queue->bot)
	{
		dis_bot++;
		plusminus_i(&idx_cp, 'p', queue->size);
	}
	if (dis_top >= dis_bot)
		return (1);
	return (0);
}

void	sort(t_circle_queue *a, t_circle_queue *b)
{
	unsigned int	max_idx;

	re_init_from_zero(a->arr, a->size - 1);
	while (!is_circle_queue_empty(a))
	{
		push(a, b);
		ft_printf("pb\n");
	}
	while (!is_circle_queue_empty(b))
	{
		max_idx = get_max_idx(b);
		if (is_closer_from_top(max_idx, b))
		{
			plusminus_i(&max_idx, 'm', b->size);
			while (max_idx != b->top)
			{
				rotate(b);
				ft_printf("rb\n");
			}
			push(b, a);
			ft_printf("pa\n");
		}
		else
		{
			while (max_idx != b->bot)
			{
				r_rotate(b);
				ft_printf("rrb\n");
			}
			push(b, a);
			ft_printf("pa\n");
		}
	}
}
