
#include "lem_in.h"

int ft_is_limit_int(char *s)
{

}


void valid_rooms(t_stdin **input)
{
	char **str;
	char *s;
	int flag;

	str = (*input)->std_in;
	while (*str)
	{
		flag = 0;
		s = *str;
		if (strcmp(s, "##start") && strcmp(s, "##end"))
		{
			if (*s == 'L' || (*s == '#' && *(s + 1) != '#'))
				ft_error(2);
			while (*s && ft_isprint(*s) && !ft_isspace(*s))
				s++;
			*s ? flag++ : ft_error(2);
			if (*s == ' ' && ft_isspace(*(s + 1)))
				ft_error(2);
			s++;
			while (*s && *s != ' ')
			{
				if (!ft_isdigit(*s))
					ft_error(2);
				s++;
			}
			*s ? flag++ : ft_error(2);
			if (*s == ' ' && ft_isspace(*(s + 1)))
				ft_error(2);
			s++;
			*s ? flag++ : ft_error(2);
			while (*s && *s != ' ')
			{
				if (!ft_isdigit(*s))
					ft_error(2);
				s++;
			}
			flag != 3 ? ft_error(2) : 0;
		}
		str++;
	}
}

void valid_sart_end(t_stdin **input)
{
	char **str;

	str = (*input)->std_in;
	while (*str)
	{
		if (!strcmp(*str, "##start"))
			(*input)->start--;
		if (!strcmp(*str, "##end"))
			(*input)->end--;
		str++;
	}
	if ((*input)->start || (*input)->end)
		ft_error(2);
}

void ft_input_valid(t_stdin **input)
{
	(*input)->start = 1;
	(*input)->end = 1;
	if (!((*(*input)->std_in)))
		ft_error(1);
	valid_sart_end(input);
	valid_rooms(input);
//	valid_connect(input);
}
