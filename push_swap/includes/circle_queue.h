/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_queue.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:27:27 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 16:08:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_QUEUE_H
# define CIRCLE_QUEUE_H

# include <stdlib.h>

typedef struct s_circle_queue
{
	int	*arr;
	int	bot;
	int	top;
	int	size;
	int	n;
}	t_circle_queue;

t_circle_queue	*create_circle_queue(int size);
int 			is_circle_full(t_circle_queue *circle_queue);
int 			is_circle_empty(t_circle_queue *circle_queue);
void			increase_idx(t_circle_queue *circle_queue, char c);
void			decrease_idx(t_circle_queue *circle_queue, char c);

void	swap(t_circle_queue *circle_queue);
void	push(t_circle_queue *circle_queue1, t_circle_queue *circle_queue2);
void	rotate(t_circle_queue *circle_queue);
void	r_rotate(t_circle_queue *circle_queue);

#endif
