/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 16:46:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	make_stack(&stack_a, 5);
	make_stack(&stack_b, 5);

	for (int i = 0; i < 5; i++)
		stack_a.stack[i] = i;
}
