/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:50:04 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/26 14:01:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		printf("invalid argument number\n");
		return (1);
	}
	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
	dup2(fd, 1);
	for (int i = 0; i < 10; i++)
		printf("Negin is very adorable\n");
}
