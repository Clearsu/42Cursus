/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:03:08 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 22:32:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

char	**split_argv(int *argc, char *argv)
{
	char	**ptr;
	int		i;

	ptr = ft_split(argv, ' ');
	i = 0;
	while (ptr[i])
		i++;
	*argc = i;
	return (ptr);
}

int	is_all_num(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
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

void	put_argv_to_stack(t_stack *a, char **argv)
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
	a->bnx = 0;
	a->bot = --i;
	a->n = a->size - 1;
	if (is_stack_empty(a))
		error();
}
