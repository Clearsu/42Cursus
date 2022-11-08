/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:03:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/08 23:37:57 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_all_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str)) 
			return (0);
		str++;
	}
	return (1);
}

void	put_argv_to_queue(t_circle_queue *circle_queue, char **argv)
{
	int	i;

	i = 1; // top starts from index 1 in a queue
	while (argv[i])	
	{
		if (is_all_num(argv[i]))
			circle_queue->queue[i] = ft_atoi(argv[i]);
		i++;
	}
	circle_queue->top = --i;
}
