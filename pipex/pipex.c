/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:14:15 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/24 21:43:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;

	int infile = open(argv[1], O_RDONLY);
	int	outfile = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	dup2(infile, 0);
	dup2(outfile, 1);
	execve(argv[2], &argv[2], envp);
}
