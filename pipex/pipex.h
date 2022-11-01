/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:35:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/01 18:22:22 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"

# define BUFFER_SIZE 128

typedef struct	s_vars
{
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	char	**cmd_path;
	char	**path;
	char	***argv;
	char	**envp;
	size_t	cmd_num;
	char	*limiter;
	size_t	limiter_len;
}	t_vars;

void	parse(t_vars *vars, int argc, char **argv, char **envp);
void	ft_error(int n, char *str);
int		arg_check(int argc, char **argv);
void	pipex(t_vars *vars);
void	here_doc(t_vars *vars, int argc, char **argv, char **envp);
void	parse_path(t_vars *vars, char **envp);
void	search_path(t_vars *vars);

int		ft_printf(const char *str, ...);
void	free_split(char **ptr);
char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
