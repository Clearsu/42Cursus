/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/14 23:16:09 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

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
	if (!is_sorted(a))
		sort(a, b);
	return (0);
}
