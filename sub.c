
#include "lem_in.h"

int if_is_digit_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int limit_int(long int n)
{
	if (n >	2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int count_ants(char *s)
{
	long int n;

	n = 0;
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (limit_int(n) ? 1 : 0);
}
