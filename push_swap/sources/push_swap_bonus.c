/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.52seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:09:09 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 22:40:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "stack.h"
#include "libft.h"

void	check_op(char *op)
{
	int			i;
	static char	*ops[12] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(ops[i++], op) == 0)
			return ;
	}
	error();
}

void	do_op(char *op, t_stack *a, t_stack *b)
{
	if (ft_strncmp(op, "pa\n", 4) == 0)
		push(b, a);
	if (ft_strncmp(op, "pb\n", 4) == 0)
		push(a, b);
	if (ft_strncmp(op, "sa\n", 4) == 0 || ft_strncmp(op, "ss\n", 4) == 0)
		swap(a);
	if (ft_strncmp(op, "sb\n", 4) == 0 || ft_strncmp(op, "ss\n", 4) == 0)
		swap(b);
	if (ft_strncmp(op, "ra\n", 4) == 0 || ft_strncmp(op, "rr\n", 4) == 0)
		rotate(a);
	if (ft_strncmp(op, "rb\n", 4) == 0 || ft_strncmp(op, "rr\n", 4) == 0)
		rotate(b);
	if (ft_strncmp(op, "rra\n", 5) == 0 || ft_strncmp(op, "rrr\n", 5) == 0)
		r_rotate(a);
	if (ft_strncmp(op, "rrb\n", 5) == 0 || ft_strncmp(op, "rrr\n", 5) == 0)
		r_rotate(b);
}

void	sort_by_op(t_stack *a, t_stack *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		check_op(op);
		do_op(op, a, b);
		free(op);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*temp;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		temp = ft_strjoin("name ", argv[1]);
		argv = split_argv(&argc, temp);
	}
	a = create_stack(argc - 1);
	b = create_stack(argc - 1);
	a->name = 'a';
	b->name = 'b';
	put_argv_to_stack(a, argv);
	sort_by_op(a, b);
	if (is_sorted(a) && is_stack_empty(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
