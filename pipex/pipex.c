/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 00:43:04 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	argc_check(argc);
	parse(argv, envp, &vars);
//	printf("infile : %s\ncmd1 : %s\ncmd1_flag : %s\ncmd2 : %s\ncmd2_flag : %s\noutfile : %s\n", vars.infile, vars.cmd1, vars.cmd1_flag, vars.cmd2, vars.cmd2_flag, vars.outfile);		
}
