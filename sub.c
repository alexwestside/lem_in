
#include "lem_in.h"

int atoi_lemin(char *str)
{
	int num;

	num = 0;
	*str == '-' ? str++ : 0;
	while (*str)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (str[0] == '-' ? num * -1 : num);
}

int if_is_digit_sign_str(char *s)
{
	if (*s == '-' || *s == '+')
		if (!if_is_digit_str(s + 1))
			return (0);
	return (1);
}

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

int if_is_alpha_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isalpha(*s))
			return (0);
		p++;
	}
	return (1);
}

int if_is_alnum_str(char *s)
{
	char *p;

	p = s;
	if (!p)
		return (0);
	while (*p)
	{
		if (!ft_isalpha(*p) && !ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}


int limit_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
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

int check_start_end(t_lemin **lemin, char *line)
{
	char **s;

	s = (*lemin)->std_in;
	while (ft_strcmp(*s, line))
		s++;
	s--;
	if (!ft_strcmp(*s, "##start") || !ft_strcmp(*s, "##end"))
		return (1);
	return (0);

//	char **str;
//	int i = 0;

//	str = (*lemin)->std_in;
//	while ((*lemin)->std_in[i])
//		i++;
//	i -= 2;
//	while (*str)
//		str++;
//	str = str - 2;
//	if ((*lemin)->std_in)
//	{
//		if ((*lemin)->std_in[i])
//		{
//				if (!ft_strcmp((*lemin)->std_in[i], "##start") || !ft_strcmp((*lemin)->std_in[i], "##end"))
//					return (1);
//		}
//	}
//	return (0);
}

void free_visit_and_queue(char **visit, char **queue)
{
	while (*visit)
	{
//		free(*visit);
		*visit = NULL;
		visit++;
	}
	while (*queue)
	{
//		free(*queue);
		*queue = NULL;
		queue++;
	}
//	ft_strdel(visit);
//	ft_strdel(queue);

}