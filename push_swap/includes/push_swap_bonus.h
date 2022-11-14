/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:07:40 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:42:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "libft.h"
# include "stack.h"

char	**split_argv(int *argc, char *argv);
void	put_argv_to_stack(t_stack *stack, char **argv);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_new_idx(int i, char c, int size);
int		get_idx_of_val(t_stack *stack, int val);
int		is_sorted(t_stack *stack);
void	error(void);

#endif
