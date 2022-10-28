#include "pipex.h"

void	arg_check(int argc, char **argv)
{
	int	fd_test;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		exit(0); // here_doc 만들 것
	if (argc < 5)
		ft_error(1, argv[argc - 1]);
	fd_test = open(argv[1], O_RDONLY);
	if (fd_test == -1)
		ft_error(0, argv[1]);
	close(fd_test);
}
