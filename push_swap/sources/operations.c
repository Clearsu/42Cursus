/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:13:02 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 14:31:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circle_queue.h"
#include "stdio.h"

void	swap(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->arr[circle_queue->top];
	circle_queue->arr[circle_queue->top] = circle_queue->arr[circle_queue->top - 1];
	circle_queue->arr[circle_queue->top - 1] = temp;
	printf("\nswap\n\n");
}

void	push(t_circle_queue *circle_queue1, t_circle_queue *circle_queue2)
{
	int	temp;

	if (is_circle_queue_empty(circle_queue1))
		return ;
	temp = circle_queue1->arr[circle_queue1->top];
	circle_queue1->arr[circle_queue1->top] = 0;
	increase_idx(circle_queue1, 't');
	decrease_idx(circle_queue2, 't');
	circle_queue2->arr[circle_queue2->top] = temp;
	printf("\npush\n\n");
}

void	rotate(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->arr[circle_queue->top];
	circle_queue->arr[circle_queue->top] = 0;;
	increase_idx(circle_queue, 't');
	circle_queue->arr[circle_queue->bot] = temp;	
	increase_idx(circle_queue, 'b');
	circle_queue->arr[circle_queue->bot] = 0;	
	printf("\nrotate\n\n");
}

void	r_rotate(t_circle_queue *circle_queue)
{
	int	temp;

	temp = circle_queue->arr[circle_queue->bot + 1];
	decrease_idx(circle_queue, 'b');
	circle_queue->arr[circle_queue->bot] = 0;
	decrease_idx(circle_queue, 't');
	circle_queue->arr[circle_queue->top] = temp;
	printf("\nreverse rotate\n\n");
}
