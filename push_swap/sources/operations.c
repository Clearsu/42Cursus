/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 23:40:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle_queue.h"
#include "stdio.h"

void	swap(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->queue[circle_queue->top];
	circle_queue->queue[circle_queue->top] = circle_queue->queue[circle_queue->top - 1];
	circle_queue->queue[circle_queue->top - 1] = temp;
	printf("\nswap\n\n");
}

void	push(t_circle_queue *circle_queue1, t_circle_queue *circle_queue2)
{
	int	temp;

	if (is_circle_queue_empty(circle_queue1))
		return ;
	temp = circle_queue1->queue[circle_queue1->top];
	circle_queue1->queue[circle_queue1->top] = 0;
	decrease_idx(circle_queue1, 't');
	increase_idx(circle_queue2, 't');
	circle_queue2->queue[circle_queue2->top] = temp;
	printf("\npush\n\n");
}

void	rotate(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->queue[circle_queue->top];
	circle_queue->queue[circle_queue->top] = 0;;
	decrease_idx(circle_queue, 't');
	circle_queue->queue[circle_queue->bottom] = temp;	
	decrease_idx(circle_queue, 'b');
	circle_queue->queue[circle_queue->bottom] = 0;	
	printf("\nrotate\n\n");
}

void	r_rotate(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->queue[circle_queue->bottom + 1];
	increase_idx(circle_queue, 'b');
	circle_queue->queue[circle_queue->bottom] = 0;
	increase_idx(circle_queue, 't');
	circle_queue->queue[circle_queue->top] = temp;
	printf("\nreverse rotate\n\n");
}
