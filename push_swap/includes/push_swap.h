/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:07:40 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 20:03:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "circle_queue.h"

typedef struct s_from_to
{
	int from;
	int	to;
}	t_from_to;

void	put_argv_to_queue(t_circle_queue *queue, char **argv);
void	sort(t_circle_queue *a, t_circle_queue *b);
int		get_max(t_circle_queue *queue);
int		get_min(t_circle_queue *queue);
int		get_new_idx(int i, char c, int size);
int		is_smaller_n_exist(t_circle_queue *queue, int n);
int		is_sorted(t_circle_queue *queue);
void	error(void);

#endif
