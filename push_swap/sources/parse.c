/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:03:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/09 14:26:28 by jincpark         ###   ########.fr       */
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

void	check_duplicate(int *arr, int i)
{
	int	curr;

	curr = arr[i--];
	while (i > 0)
	{
		if (arr[i--] == curr)
			error();
	}
}

void	check_if_sorted(int *arr, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		if (arr[i] > arr[i + 1])
			error();
		i++;
	}
}

void	put_argv_to_queue(t_circle_queue *circle_queue, char **argv)
{
	int			i;
	long long	num;

	i = 1; // bottom starts from index 1 in a arr
	while (argv[i])	
	{
		if (is_all_num(argv[i]))
		{
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN)
				error();
			circle_queue->arr[i] = (int)num;
			check_duplicate(circle_queue->arr, i++);
		}
		else
			error();
	}
	circle_queue->bottom = --i;
	check_if_sorted(circle_queue->arr, i);
}
