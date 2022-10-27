/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 20:38:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	argc_check(argc);
	parse(&vars, argc, argv, envp);
	/*
	printf("infile : %s\n", vars.infile);
	printf("outfile : %s\n", vars.outfile);
	printf("cmd1 : %s, cmd2 : %s\n", vars.cmd[0], vars.cmd[1]);
	printf("path1 : %s, path2 : %s, path3 : %s\n", vars.path[0], vars.path[1], vars.path[2]);
	printf("cmd_flag1 : %s, cmd_flag2 : %s\n", vars.cmd_flag[0], vars.cmd_flag[1]);
	printf("cmd_path1 : %s, cmd_path2 : %s\n", vars.cmd_path[0], vars.cmd_path[1]);
	*/
	return (0);
}
