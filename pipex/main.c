/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 21:18:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		i = 0;

	if (argc < 5)
		error(0, NULL);
	parse(&vars, argc, argv, envp);
	/*
	printf("infile : %s\n", vars.infile);
	printf("outfile : %s\n", vars.outfile);
	while (vars.cmd[i])
	{
		printf("cmd%d : %s  cmd%d_path : %s  cmd%d_flag : %s\n", i, vars.cmd[i], i, vars.cmd_path[i], i, vars.cmd_flag[i]);
		i++;
	}
	i = 0;
	while (vars.path[i])
	{
		printf("path%d : %s\n", i, vars.path[i]);
		i++;
	}
	*/
	return (0);
}
