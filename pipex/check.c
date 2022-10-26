/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:53:17 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 00:07:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("invalid argument number\n", 1);
		exit(1);
	}
}
