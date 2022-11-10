/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:07:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

void	print_stacks(t_stack *a, 
		t_stack *b)
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
	printf(" tvi : %d tvi : %d\n", a->tvi, b->tvi);
	printf(" bot : %d bot : %d\n", a->bot, b->bot);
	printf(" bnx : %d bnx : %d\n", a->bnx, b->bnx);
	printf("   n : %d   n : %d\n\n", a->n, b->n);
}

void	print_states(t_stack *a, t_stack *b)
{
	printf("    push B\n\n");
	push(a, b);
	print_stacks(a, b);

	printf("    push B\n\n");
	push(a, b);
	print_stacks(a, b);

	printf("    push B\n\n");
	push(a, b);
	print_stacks(a, b);

	printf("    rotate A\n\n");
	rotate(a);
	print_stacks(a, b);

	printf("    rotate A\n\n");
	rotate(a);
	print_stacks(a, b);

	printf("   reverse rotate A\n\n");
	r_rotate(a);
	print_stacks(a, b);


	printf("    reverse rotate B\n\n");
	r_rotate(b);
	print_stacks(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_stacks(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_stacks(a, b);

	printf("    push A\n\n");
	push(b, a);
	print_stacks(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(1);
	a = create_stack(argc - 1);
	b = create_stack(argc - 1);
	a->name = 'a';
	b->name = 'b';
	
	put_argv_to_stack(a, argv);

	printf("    Initial state\n\n");
	print_stacks(a, b);

	//print_states(a, b);

	sort(a, b);

	printf("    Final state\n\n");
	print_stacks(a, b);

	return (0);
}
