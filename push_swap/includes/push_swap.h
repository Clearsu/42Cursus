/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:07:40 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/11 18:58:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "stack.h"

typedef struct s_info
{
	int 	from;
	int		to;
	int		val_from;
	char	dir_b;
	char	dir_a;
}	t_info;

void	put_argv_to_stack(t_stack *stack, char **argv);
void	sort(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_new_idx(int i, char c, int size);
int		is_smaller_n_exist(t_stack *stack, int n);
int		is_sorted(t_stack *stack);
int		get_distance_top(t_stack *stack, int idx);
int		get_distance_bot(t_stack *stack, int idx);
int		get_dis_a(t_stack *stack, t_info *temp);
int		get_dis_b(t_stack *stack, int i, t_info *temp);
void	move_stacks(t_stack *a, t_stack *b, t_info *info);
void	rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info);
void	r_rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info);
void	rotate_untill_idx(t_stack *stack, int idx);
void	r_rotate_untill_idx(t_stack *stack, int idx);
void	error(void);

#endif
