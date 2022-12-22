/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnf_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:13 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/22 21:54:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* RULE */
/*

EXPRESSION 	::= NUMBER OPERATOR_1 EXPRESSION
			| NUMBER OPERATOR_2 EXPRESSION
			| NUMBER

NUMBER 		::= DIGIT NUMBER
			| DIGIT

OPERATOR	::= + | - | * | / | %

DIGIT 		::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

*/

#include "libft.h"

#define 

struct typedef s_token
{
	int	type; // could be DIGIT or OPERATION
	int	value;
}	t_token;

void	parse(char **argv, t_list *head)
{
	
}

int	main(int argc, char **argv)
{	
	t_list	*head;
	int		result;

	(void)argc;
	head = parse(argv, head);
	result = compute(head);
	ft_printf("result : %d\n", result);
}
