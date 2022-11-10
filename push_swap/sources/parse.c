/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:03:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/10 16:04:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

int	is_all_num(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
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
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	exit(0);
}

void	put_argv_to_queue(t_circle_queue *a, char **argv)
{
	int			i;
	long long	num;

	i = 1;
	while (argv[i])
	{
		if (is_all_num(argv[i]))
		{
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN)
				error();
			a->arr[i] = (int)num;
			check_duplicate(a->arr, i++);
		}
		else
			error();
	}
	a->bot = --i;
	if (is_circle_queue_empty(a))
		error();
	check_if_sorted(a->arr, i);
	a->n = a->size - 1;
}
