/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:27:27 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 16:31:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int	*stack;
	int	bottom;
	int	top;
	int	size;
}	t_stack;

int		make_stack(t_stack *stack, int size);
int 	is_stack_full(t_stack *stack);
int 	is_stack_empty(t_stack *stack);
void	increase_idx(t_stack *stack, char c);
void	decrease_idx(t_stack *stack, char c);

void	swap(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif
