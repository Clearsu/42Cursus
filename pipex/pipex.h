/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:35:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 02:29:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_vars
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd1_flag;
	char	*cmd1_path;
	char	*cmd2;
	char	*cmd2_flag;
	char	*cmd2_path;
}	t_vars;

void	argc_check(int argc);
void	parse(char **argv, char **envp, t_vars *vars);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char c);

#endif
