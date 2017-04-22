
#include "lem_in.h"

int type_num_ants(char *str)
{
	if (if_is_digit_str(str))
		if (count_ants(str))
			return (1);
	return (0);
}

int type_room(char *str)
{
	int flag;
	char *s = str;

	flag = 0;
	if (*s == 'L' || *s == '#')
		return (0);
	while (*s && ft_isprint(*s) && !ft_isspace(*s))
		s++;
	*s ? flag++ : ft_error(2);
	if (*s == ' ' && ft_isspace(*(s + 1)))
		return (0);
	s++;
	while (*s && *s != ' ')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	*s ? flag++ : ft_error(2);
	if (*s == ' ' && ft_isspace(*(s + 1)))
		return (0);
	s++;
	*s ? flag++ : ft_error(2);
	while (*s && *s != ' ')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	if (*s || flag != 3)
		return (0);
	return (1);
}


int type_strt_end(char *str)
{
	if (!strcmp(str, "##start") || !strcmp(str, "##start"))
		return (1);
	return (0);
}

int type_connet(char *str)
{

	return (0);
}

int type_comment(char *str)
{

	return (0);
}