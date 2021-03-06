#include "checker.h"
#include "libft.h"

void error_handler(int error_code)
{
	if (error_code == 0)
		ft_putendl_fd(RED_COLOR"MALLOC ERROR😢"END_COLOR, 2);
	if (error_code == 1)
		ft_putendl_fd(RED_COLOR"WRONG OPERATION😢"END_COLOR, 2);
	if (error_code == 2)
		ft_putendl_fd(RED_COLOR"WRONG INPUT😢"END_COLOR, 2);
	exit(0);
}