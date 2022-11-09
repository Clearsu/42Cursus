/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 19:22:49 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle_queue.h"
#include "stdio.h"

void	swap(t_circle_queue *queue)
{
	int	temp1;
	int	temp2;

	increase_idx(queue, 't');
	temp1 = queue->arr[queue->top];
	increase_idx(queue, 't');
	temp2 = queue->arr[queue->top];
	queue->arr[queue->top] = temp1;
	decrease_idx(queue, 't');
	queue->arr[queue->top] = temp2;
	decrease_idx(queue, 't');
}

void	push(t_circle_queue *queue1, t_circle_queue *queue2)
{
	int	temp;

	if (is_circle_queue_empty(queue1))
		return ;
	increase_idx(queue1, 't');
	temp = queue1->arr[queue1->top];
	queue1->arr[queue1->top] = 0;
	queue2->arr[queue2->top] = temp;
	decrease_idx(queue2, 't');
	queue2->arr[queue2->top] = 0;
}

void	rotate(t_circle_queue *queue)
{
	int	temp;

	increase_idx(queue, 't');
	temp = queue->arr[queue->top];
	queue->arr[queue->top] = 0;
	increase_idx(queue, 'b');
	queue->arr[queue->bot] = temp;
}

void	r_rotate(t_circle_queue *queue)
{
	int	temp;

	temp = queue->arr[queue->bot];
	queue->arr[queue->bot] = 0;
	decrease_idx(queue, 'b');
	queue->arr[queue->top] = temp;
	decrease_idx(queue, 't');
}
