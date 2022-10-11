/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:57:47 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 19:48:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_htoi(char *str)
{
	int		res;
	int		idx;
	char	c;

	res = 0;
	idx = 2;
	while (1)
	{
		c = str[idx++];
		if (c >= '0' && c <= '9')
			res += (c - 48);
		else if (c >= 'A' && c <= 'F')
			res += (c - 55);
		else if (c >= 'a' && c <= 'f')
			res += (c - 87);
		if (!str[idx])
			break ;
		res = res << 4;
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
