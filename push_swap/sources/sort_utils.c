/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 15:59:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circle_queue.h"

int	get_max(t_circle_queue *queue)
{
	int	i;
	int	max;
	int	size;

	i = 2;
	max = queue->arr[1];
	size = queue->size;
	while (i < size)
	{
		if (queue->arr[i] > max)
			max = queue->arr[i];
		i++;
	}
	return (max);
}

int	get_min(t_circle_queue *queue)
{
	int	i;
	int	min;
	int	size;

	i = 2;
	min = queue->arr[1];
	size = queue->size;
	while (i < size)
	{
		if (queue->arr[i] < min)
			min = queue->arr[i];
		i++;
	}
	return (min);
}
