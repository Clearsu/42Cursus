/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:12:51 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 20:26:09 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 3)
	{
		swap(a);
		ft_printf("sa\n");
	}
	if (a->size == 4)
		sort_3(a);
	if (a->size == 5)
		sort_4(a, b);
	if (a->size == 6)
		sort_5(a, b);
	exit(0);
}
