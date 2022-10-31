/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/31 20:57:23 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_check(t_vars vars)
{
	int		i = 0;
	int		j;

	printf("infile_fd : %d\n", vars.fd_in);
	printf("outfile_fd : %d\n", vars.fd_out);
	while (vars.cmd_path[i])
	{
		printf("cmd%d_path : %s  cmd%d_argv : ", i, vars.cmd_path[i], i);
		j = 0;
		while (vars.argv[i][j])
			printf("%s ", vars.argv[i][j++]);
		printf("\n");
		i++;
	}
	i = 0;
	while (vars.path[i])
	{
		printf("path%d : %s\n", i, vars.path[i]);
		i++;
	}	
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	arg_check(argc, argv);
	parse(&vars, argc, argv, envp);
	pipex(&vars);
	//parsing_check(vars);
	return (0);
}
