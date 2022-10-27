/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:34:20 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/28 02:00:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_malloc(t_vars *vars)
{
	vars->cmd = (char **)malloc(sizeof(char *) * (vars->cmd_num + 1));
	vars->cmd_flag = (char **)malloc(sizeof(char *) * (vars->cmd_num + 1));
	vars->cmd_path = (char **)malloc(sizeof(char *) * (vars->cmd_num + 1));
	vars->cmd[vars->cmd_num] = NULL;
	vars->cmd_flag[vars->cmd_num] = NULL;
}

void	parse_cmd(t_vars *vars, char **argv)
{
	char	**temp;
	int		i;
	int		cmd_num;

	i = 0;
	cmd_num = (int)vars->cmd_num;
	while (i < cmd_num)
	{
		temp = ft_split(argv[i + 2], ' ');
		vars->cmd[i] = temp[0];
		if (temp[1])
			vars->cmd_flag[i] = temp[1];
		else
			vars->cmd_flag[i] = NULL;
		free(temp);	
		i++;
	}
}

void	parse_path(t_vars *vars, char **envp)
{
	char	**temp_list;
	char	*temp;
	int		i;

	temp_list = ft_split(envp[11], '=');
	vars->path = ft_split(temp_list[1], ':');
	free_split(temp_list);
	i = 0;
	while (vars->path[i])
	{
		temp = ft_strjoin(vars->path[i], "/");
		free(vars->path[i]);
		vars->path[i] = temp;
		i++;
	}
}

void	search_path(t_vars *vars)
{	
	char	*temp;
	size_t	i;
	size_t	j;
	int		access_val;

	i = 0;
	while (vars->cmd[i])
	{
		j = 0;
		while (vars->path[j])
		{
			temp = ft_strjoin(vars->path[j++], vars->cmd[i]);
			access_val = access(temp, X_OK);
			if (access_val == 0)
			{
				vars->cmd_path[i] = temp;
				break ;
			}
			else
				free(temp);
		}
		if (vars->path[j] == NULL)
			ft_error(1, vars->cmd[i]);
		i++;
	}
}

void	parse(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->infile = argv[1];
	vars->outfile = argv[argc - 1];
	vars->cmd_num = argc - 3;
	vars->envp = envp;
	cmd_malloc(vars);
	parse_cmd(vars, argv);
	parse_path(vars, envp);
	search_path(vars);
}
