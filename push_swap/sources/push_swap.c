/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 21:31:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circle_queue.h"
#include <stdio.h>

void	print_circle_queues(t_circle_queue *a, 
		t_circle_queue *b)
{
	int	n;

	n = a->size;
	printf("    [ top ]\n");
	printf("[index] [A] [B]\n");
	for (int i = 0; i < n; i++)
		printf("   %d     %d   %d\n",i, 
				a->arr[i], b->arr[i]);
	printf("     [ bot ]\n\n");
	printf("   [A]    [B]\n");
	printf(" top : %d top : %d\n", a->top, b->top);
	printf(" bot : %d bot : %d\n\n\n", a->bot, b->bot);
}

void	print_states(t_circle_queue *a, t_circle_queue *b)
{
	printf("    Initial state\n\n");
	print_circle_queues(a, b);
	sort(a);
	printf("    Final state\n\n");
	print_circle_queues(a, b);
/*
	printf("    push B\n\n");
	push(a, b);
	print_circle_queues(a, b);

	printf("    push B\n\n");
	push(a, b);
	print_circle_queues(a, b);

	printf("    push B\n\n");
	push(a, b);
	print_circle_queues(a, b);

	printf("    rotate A\n\n");
	rotate(a);
	print_circle_queues(a, b);

	printf("    rotate A\n\n");
	rotate(a);
	print_circle_queues(a, b);

	printf("    push B\n\n");
	push(a, b);
	print_circle_queues(a, b);

	printf("   reverse rotate A\n\n");
	r_rotate(a);
	print_circle_queues(a, b);


	printf("    reverse rotate B\n\n");
	r_rotate(b);
	print_circle_queues(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_circle_queues(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_circle_queues(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_circle_queues(a, b);
	*/
}

int	main(int argc, char **argv)
{
	t_circle_queue	*a;
	t_circle_queue	*b;

	if (argc == 1)
		exit(1);
	a = create_circle_queue(argc - 1);
	b = create_circle_queue(argc - 1);
	
	put_argv_to_queue(a, argv);

	print_states(a, b);
	return (0);
}
