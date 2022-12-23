/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnf_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:13 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/23 14:22:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* RULE */
/*

EXPRESSION 	::= EXPRESSION OPERATOR NUMBER
			| NUMBER

NUMBER 		::= DIGIT NUMBER
			| DIGIT

OPERATOR	::= + | - | * | / | %

PARENTHESIS	::= ( | )

DIGIT 		::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

*/

#include "libft.h"
#include "ft_btree.h"
#include "readline/readline.h"

#define

struct typedef s_token
{
	int	type; // could be DIGIT or OPERATION
	int	value;
}	t_token;

void	parse(char **argv, t_list *head)
{
	
}

int	main(void)
{	
	char	*str;

	while (1)
	{
		str = 
	}
}
