/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:03:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 04:47:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

int	is_all_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str++)) 
			return (0);
	}
	return (1);
}

void	check_duplicate(int *queue, int i)
{
	int	curr;

	curr = queue[i--];
	while (i > 0)
	{
		if (queue[i--] == curr)
			error();
	}
}

void	put_argv_to_queue(t_circle_queue *circle_queue, char **argv)
{
	int			i;
	long long	num;

	i = 1; // top starts from index 1 in a queue
	while (argv[i])	
	{
		if (is_all_num(argv[i]))
		{
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN)
				error();
			circle_queue->queue[i] = (int)num;
			check_duplicate(circle_queue->queue, i++);
		}
		else
			error();
	}
	circle_queue->top = --i;
}
