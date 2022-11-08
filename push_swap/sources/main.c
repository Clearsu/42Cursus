/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 04:43:13 by jincpark         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_circle_queue	*circle_queue_a;
//	t_circle_queue	*circle_queue_b;

	if (argc == 1)
		return (1);
	circle_queue_a = create_circle_queue(argc - 1);
//	circle_queue_b = create_circle_queue(argc - 1);
	
	put_argv_to_queue(circle_queue_a, argv);
/*	
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_a, circle_queue_b);
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_a, circle_queue_b);
	print_circle_queues(circle_queue_a, circle_queue_b);
	push(circle_queue_a, circle_queue_b);
	print_circle_queues(circle_queue_a, circle_queue_b);
	rotate(circle_queue_a);
	print_circle_queues(circle_queue_a, circle_queue_b);
	r_rotate(circle_queue_b);
	print_circle_queues(circle_queue_a, circle_queue_b);
	*/
	return (0);
}
