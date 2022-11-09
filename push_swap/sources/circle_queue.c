/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 15:26:31 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle_queue.h"

t_circle_queue	*create_circle_queue(int size)
{
	t_circle_queue	*circle_queue;

	circle_queue = (t_circle_queue *)malloc(sizeof(t_circle_queue));
	circle_queue->arr = (int *)malloc(sizeof(int) * (size + 1));
	circle_queue->top = 0;
	circle_queue->bot = 0;
	circle_queue->size = size + 1;
	return (circle_queue);
}

int	is_circle_queue_full(t_circle_queue *circle_queue)
{
	if ((circle_queue->bot + 1) % circle_queue->size == circle_queue->top)
		return (1);
	return (0);
}

int	is_circle_queue_empty(t_circle_queue *circle_queue)
{
	if (circle_queue->top == circle_queue->bot)
		return (1);
	return (0);
}

void	increase_idx(t_circle_queue *circle_queue, char c)
{
	if (c == 't')
	{
		if (circle_queue->top == circle_queue->size - 1)
			circle_queue->top = 0;
		else
			circle_queue->top++;
	}
	else if (c == 'b')
	{
		if (circle_queue->bot == circle_queue->size - 1)
			circle_queue->bot = 0;
		else
			circle_queue->bot++;
	}
}

void	decrease_idx(t_circle_queue *circle_queue, char c)
{
	if (c == 't')
	{
		if (circle_queue->top == 0)
			circle_queue->top = circle_queue->size - 1;
		else
			circle_queue->top--;
	}
	else if (c == 'b')
	{
		if (circle_queue->bot == 0)
			circle_queue->bot = circle_queue->size - 1;
		else
			circle_queue->bot--;
	}
}
