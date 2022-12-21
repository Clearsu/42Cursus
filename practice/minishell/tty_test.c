#include <unistd.h>
#include <stdio.h>

int	main()
{
	printf("%s\n", ttyname(0));
}
