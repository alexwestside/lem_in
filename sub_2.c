
#include "lem_in.h"

int		atoi_lemin(char *str)
{
	int	num;

	num = 0;
	*str == '-' ? str++ : 0;
	while (*str)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (str[0] == '-' ? num * -1 : num);
}

int		limit_int(long int n)
{
	if (n > 2147483647 || n < 0)
		return (0);
	return (1);
}

int		if_is_digit_sign_str(char *s)
{
	if (*s == '-' || *s == '+')
		if (!if_is_digit_str(s + 1))
			return (0);
	return (1);
}

int		if_is_digit_str(char *s)
{
	char	*p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int		if_is_alnum_str(char *s)
{
	char	*p;

	p = s;
	if (!p)
		return (0);
	while (*p)
	{
		if (!ft_isalpha(*p) && !ft_isdigit(*p))
		{
			p = NULL;
			return (0);
		}
		p++;
	}
	p = NULL;
	return (1);
}
