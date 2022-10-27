/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:35:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/27 20:29:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 128

typedef struct	s_vars
{
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	**cmd_flag;
	char	**cmd_path;
	char	**path;
	size_t	cmd_num;
}	t_vars;

void	argc_check(int argc);
void	parse(t_vars *vars, int argc, char **argv, char **envp);

void	ft_putstr_fd(char *str, int fd);
void	free_split(char **ptr);
char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif
