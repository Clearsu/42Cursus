/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 22:48:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circle_queue.h"
#include <stdio.h>

void	print_circle_queues(t_circle_queue *circle_queue_a, 
		t_circle_queue *circle_queue_b)
{
	int	n;

	n = circle_queue_a->size - 1;
	printf("    [ top ]\n");
	printf("[index] [A] [B]\n");
	for (int i = n; i >= 0; i--)
		printf("   %d     %d   %d\n",i, 
				circle_queue_a->queue[i], circle_queue_b->queue[i]);
	printf("   [ bottom ]\n\n");
	printf("[A] top : %d bottom : %d\n", circle_queue_a->top, circle_queue_a->bottom);
	printf("[B] top : %d bottom : %d\n\n", circle_queue_b->top, circle_queue_b->bottom);
}

int	main(void)
{
	t_circle_queue	*circle_queue_a;
	t_circle_queue	*circle_queue_b;

	circle_queue_a = create_circle_queue(9);
	circle_queue_b = create_circle_queue(9);
	for (int i = 1; i < 8; i++)
		circle_queue_a->queue[i] = i;
	circle_queue_a->top = 7;
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_a, circle_queue_b);
	push(circle_queue_a, circle_queue_b);
	print_circle_queues(circle_queue_a, circle_queue_b);
	r_rotate(circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	r_rotate(circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	r_rotate(circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_b, circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_b, circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	return (0);
}
