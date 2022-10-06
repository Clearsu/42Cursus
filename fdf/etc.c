/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:57:47 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/07 02:18:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_htoi(char *str)
{
	int	res;
	int	idx;
	int	c;

	res = 0;
	while (str[idx++])
	while (str[idx] != 'x')
	{
		c = str[idx--];
		if (c >= 48 && c <= 57)
			res += (c - 48);
		else if (c >= 65 && c <= 70)
			res += (c - 55);
		res << 64;
	}
	return (res);
}
