/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:07:40 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 20:06:36 by jincpark         ###   ########.fr       */
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
	int		val_to;
	int		val_max;
	char	dir_b;
	char	dir_a;
}	t_info;

char	**split_argv(int *argc, char *argv);
void	put_argv_to_stack(t_stack *stack, char **argv);
void	sort(t_stack *a, t_stack *b);
void	sort_132(t_stack *a);
void	sort_2xx(t_stack *a);
void	sort_3xx(t_stack *a);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_new_idx(int i, char c, int size);
int		get_idx_of_val(t_stack *stack, int val);
int		is_smaller_n_exist(t_stack *stack, int n);
int		is_sorted(t_stack *stack);
int		is_closer_from_top(t_stack *stack, int idx);
int		get_distance_top(t_stack *stack, int idx);
int		get_distance_bot(t_stack *stack, int idx);
int		get_dis_a(t_stack *stack, t_info *temp);
int		get_dis_b(t_stack *stack, int i, t_info *temp);
int		get_min_bigger_than_val_from(t_stack *stack, t_info *info);
int		get_pivot(t_stack *a, int n);
void	move_stacks(t_stack *a, t_stack *b, t_info *info);
void	rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info);
void	r_rotate_together_untill_end(t_stack *a, t_stack *b, t_info *info);
void	rotate_untill_val_on_tnx(t_stack *stack, int val);
void	r_rotate_untill_val_on_tnx(t_stack *stack, int val);
void	r_rotate_untill_val_on_bot(t_stack *stack, int val);
void	compare_with_bot_val(t_stack *a, t_info *info);
void	print_stacks(t_stack *a, t_stack *b, t_info *info);
void	error(void);

#endif
