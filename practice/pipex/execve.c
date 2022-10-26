/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:56:50 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/26 15:08:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{	
	if (argc != 3)
	{
		printf("invalid argument number\n");
		exit(1);
	}
	execve(argv[1], &argv[1], envp);		
}
