/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:27:27 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 23:09:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	char	name;
	int		*arr;
	int		top;
	int		tnx;
	int		bot;
	int		bnx;
	int		size;
	int		n;
}	t_stack;

t_stack	*create_stack(int size);
int		is_stack_full(t_stack *stack);
int		is_stack_empty(t_stack *stack);
void	increase_idx(t_stack *stack, char c);
void	decrease_idx(t_stack *stack, char c);
void	swap(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif
