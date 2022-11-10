/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:07:40 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 15:55:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "circle_queue.h"

void	put_argv_to_queue(t_circle_queue *queue, char **argv);
void	sort(t_circle_queue *a, t_circle_queue *b);
int		get_max(t_circle_queue *queue);
int		get_min(t_circle_queue *queue);
void	error(void);

#endif
