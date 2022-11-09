/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:51:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 22:00:36 by jincpark         ###   ########.fr       */
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

void	sort(t_circle_queue *a)
{
	re_init_from_zero(a->arr, a->size - 1);
}
