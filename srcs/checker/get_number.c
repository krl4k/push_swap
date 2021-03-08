#include "checker.h"

void check_number(const char *n)
{
	int len;
	int nbr;

	nbr = ft_atoi(n);
	len = ft_strlen(n);
	if (len > 1 && (nbr == 0 || nbr == -1))
		error_handler(2);
	if (n[0] != '-' && nbr < 0)
		error_handler(2);
	if (n[0] == '-' && nbr > 0)
		error_handler(2);
}