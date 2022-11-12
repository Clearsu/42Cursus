/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:31 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/12 20:08:05 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
void	print_stacks(t_stack *a, t_stack *b, t_info *info)
{
	int	n;

	n = a->size;
	printf("    [ top ]\n");
	printf("[index] [A] [B]\n");
	for (int i = 0; i < n; i++)
		printf("   %d     %d   %d\n",i, 
				a->arr[i], b->arr[i]);
	printf("     [ bot ]\n\n");
	printf("   [A]    [B]\n");
	printf(" top : %d top : %d\n", a->top, b->top);
	printf(" tnx : %d tnx : %d\n", a->tnx, b->tnx);
	printf(" bot : %d bot : %d\n", a->bot, b->bot);
	printf(" bnx : %d bnx : %d\n", a->bnx, b->bnx);
	printf("   n : %d   n : %d\n\n", a->n, b->n);
	printf("    [info]\n");
	printf(" to : %d from : %d\n", info->to, info->from);
	printf(" val_to : %d val_from : %d\n", info->val_to, info->val_from);
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
	sort(a, b);
	return (0);
}
