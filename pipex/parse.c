/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 00:42:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_cmd(char *argv, char **cmd, char **cmd_flag)
{
	char	**temp;

	temp = ft_split(argv, ' ');
	*cmd = temp[0];
	if (temp[1])
		*cmd_flag = temp[1];
	else
		*cmd_flag = NULL;
}
void	parse(char **argv, char **envp, t_vars *vars)
{
	vars->infile = argv[1];
	vars->outfile = argv[4];
	parse_cmd(argv[2], &(vars->cmd1), &(vars->cmd1_flag));
	parse_cmd(argv[3], &(vars->cmd2), &(vars->cmd2_flag));
}

