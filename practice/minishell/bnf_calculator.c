/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnf_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:13 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/23 19:50:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* RULE */
/*

EXPRESSION_1 	::= EXPRESSION_1 OPERATOR_1 EXPRESSION_2
				| PARENTHESIS EXPRESSION_1 PARENTHESIS
				| EXPRESSION_2

EXPRESSION_2	::= EXPRESSION_2 OPERATOR_2 NUMBER
				| NUMBER

PARENTHESIS	::= ( | )

NUMBER 		::= DIGIT NUMBER
			| DIGIT

OPERATOR_1	::= + | -

OPERATOR_2	::= * | / | %

DIGIT 		::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

*/

#include "libft.h"
#include "ft_btree.h"
#include "readline/readline.h"

#define NUMBER 0
#define OPERATOR_1 1
#define OPERATOR_2 2
#define PARENTHESIS 3

struct typedef s_token
{
	int		type; // could be DIGIT or OPERATION
	char	*value;
}	t_token;

void	parse(char *str, t_btree *btree)
{
	
}

int	compute(t_btree *btree)
{

}

int	main(void)
{	
	char	*str;
	t_btree	*btree;
	int		res;

	while (1)
	{
		str = readline("calculator >> ");
		if (!ft_strcmp(str, "exit\n"))
			break ;
		parse(str, btree);
		res = compute(btree);
		ft_printf("result : %d\n", res);
	}
	return (0);
}
