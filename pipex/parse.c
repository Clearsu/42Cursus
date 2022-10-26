/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 00:26:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(char **argv, t_vars *vars)
{
	char	**temp;

	vars->infile = argv[1];
	vars->outfile = argv[4];
	temp = ft_split(argv[2], ' ');
	vars->cmd1 = temp[0];
	if (temp[1])
		vars->cmd1_flag = temp[1];
	else
		vars->cmd1_flag = NULL;
	temp = ft_split(argv[3], ' ');
	vars->cmd2 = temp[0];
	if (temp[1])
		vars->cmd2_flag = temp[1];
	else
		vars->cmd2_flag = NULL;
}
