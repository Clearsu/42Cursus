/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 16:11:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle_queue.h"

t_circle_queue	*create_circle_queue(int size)
{
	t_circle_queue	*queue;

	queue = (t_circle_queue *)malloc(sizeof(t_circle_queue));
	queue->arr = (int *)malloc(sizeof(int) * (size + 1));
	queue->top = 0;
	queue->bot = 0;
	queue->size = size + 1;
	queue->n = 0;
	return (queue);
}

int	is_queue_full(t_circle_queue *queue)
{
	if (queue->n == queue->size - 1)
		return (1);
	return (0);
}

int	is_queue_empty(t_circle_queue *queue)
{
	if (queue->top == queue->bot)
		return (1);
	return (0);
}

void	increase_idx(t_circle_queue *queue, char c)
{
	if (c == 't')
	{
		if (queue->top == queue->size - 1)
			queue->top = 0;
		else
			queue->top++;
	}
	else if (c == 'b')
	{
		if (queue->bot == queue->size - 1)
			queue->bot = 0;
		else
			queue->bot++;
	}
}

void	decrease_idx(t_circle_queue *queue, char c)
{
	if (c == 't')
	{
		if (queue->top == 0)
			queue->top = queue->size - 1;
		else
			queue->top--;
	}
	else if (c == 'b')
	{
		if (queue->bot == 0)
			queue->bot = queue->size - 1;
		else
			queue->bot--;
	}
}
