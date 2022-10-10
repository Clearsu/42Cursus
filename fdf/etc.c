/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:57:47 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/10 21:05:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_htoi(char *str)
{
	int		res;
	int		idx;
	char	c;

	res = 0;
	while (str[idx])
		idx++;
	while (str[--idx] != 'x')
	{
		c = str[idx];
		if (c >= 48 && c <= 57)
			res += (c - 48);
		else if (c >= 65 && c <= 70)
			res += (c - 55);
		res += 256;
	}
	return (res);
}
/*
void	ft_free(void **ptr, size_t idx)
{
	if (!idx)
		free(*ptr);
	else
	{
		while (idx >= 0)
			free(ptr[idx--]);
		free(ptr);
	}
}
*/
