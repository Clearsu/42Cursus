/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:09:09 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:35:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "stack.h"
#include "libft.h"

void	do_op(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(op, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(op, "ra\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotate(a);
	else if (ft_strcmp(op, "rb\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotate(b);
	else if (ft_strcmp(op, "rra\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		r_rotate(a);
	else if (ft_strcmp(op, "rrb\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		r_rotate(b);
}

void	sort_by_op(t_stack *a, t_stack *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		do_op(op, a, b);
		if (!op)
			break ;
		free(op);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*temp;

	if (argc == 1)
		exit(1);
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
