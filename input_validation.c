//
//#include "lem_in.h"
//
//int ifisdigit_str(char **s)
//{
//	char *p;
//
//	p = *s;
//	while (*p)
//	{
//		if (!ft_isdigit(*p))
//			return (0);
//		p++;
//	}
//	return (1);
//}
//
//int ft_is_limit_int(long int n)
//{
//	if (n >	2147483647 || n < -2147483648)
//		return (0);
//	return (1);
//}
//
//int valid_ants(char *s)
//{
//	char *p;
//	long int n;
//
//	n = 0;
//	p = s;
//	ifisdigit_str(&p);
////	while (*p)
////	{
////		if (!ft_isdigit(*p))
////			ft_error(2);
////		p++;
////	}
//	while (*s)
//	{
//		n = n * 10 + *s - '0';
//		s++;
//	}
//	return (ft_is_limit_int(n) ? 1 : 0);
//}
//
//int valid_connect(char *s)
//{
//	int flag;
//
//	flag = 0;
//	if (*s != 'L' || *s != '#')
//	{
//		while (*s && ft_isprint(*s) && !ft_isspace(*s))
//			s++;
//		*s ? flag++ : ft_error(2);
//		if (*s == ' ' && ft_isspace(*(s + 1)))
//			ft_error(2);
//		s++;
//		while (*s && *s != ' ')
//		{
//			if (!ft_isdigit(*s))
//				ft_error(2);
//			s++;
//		}
//		*s ? flag++ : ft_error(2);
//		if (*s == ' ' && ft_isspace(*(s + 1)))
//			ft_error(2);
//		s++;
//		*s ? flag++ : ft_error(2);
//		while (*s && *s != ' ')
//		{
//			if (!ft_isdigit(*s))
//				ft_error(2);
//			s++;
//		}
//		*s ? ft_error(2) : 0;
//		flag != 3 ? ft_error(2) : 0;
//		return (1);
//	}
//	return (0);
//}
//
//void valid_rooms(t_stdin **input)
//{
//	char **str;
//	char *s;
//	int flag;
//
//	str = (*input)->std_in;
//	while (*str)
//	{
//		flag = 0;
//		s = *str;
//		if (ifisdigit_str(&(*str)) && valid_ants(*str))
//		{
//			str++;
//			continue;
//		}
//		if (ft_isdigit(*s) && *(s + 1) == '-' && ft_isdigit(*(s + 2)) && !*(s + 3))
//		{
//			str++;
//			continue;
//		}
//		else if (strcmp(s, "##start") && strcmp(s, "##end"))
//		{
//			if (*s == 'L' || (*s == '#' && *(s + 1) != '#'))
//				ft_error(2);
//			while (*s && ft_isprint(*s) && !ft_isspace(*s))
//				s++;
//			*s ? flag++ : ft_error(2);
//			if (*s == ' ' && ft_isspace(*(s + 1)))
//				ft_error(2);
//			s++;
//			while (*s && *s != ' ')
//			{
//				if (!ft_isdigit(*s))
//					ft_error(2);
//				s++;
//			}
//			*s ? flag++ : ft_error(2);
//			if (*s == ' ' && ft_isspace(*(s + 1)))
//				ft_error(2);
//			s++;
//			*s ? flag++ : ft_error(2);
//			while (*s && *s != ' ')
//			{
//				if (!ft_isdigit(*s))
//					ft_error(2);
//				s++;
//			}
//			*s ? ft_error(2) : 0;
//			flag != 3 ? ft_error(2) : 0;
//		}
//		str++;
//	}
//}
//
//void valid_sart_end(t_stdin **input)
//{
//	char **str;
//	int ants;
//	int start;
//	int end;
//
//	ants = 1;
//	start = 1;
//	end = 1;
//	str = (*input)->std_in;
//	while (*str)
//	{
//		if (!strcmp(*str, "##start") && valid_connect(*(str + 1)))
//			start--;
//		if (!strcmp(*str, "##end") && valid_connect(*(str + 1)))
//			end--;
//		if (ifisdigit_str(&(*str)))
//			ants--;
//		str++;
//	}
//	if (start || end || ants)
//		ft_error(2);
//}
//
////void ft_input_valid(t_stdin **input)
//void ft_input_valid(t_stdin **input, char *s)
//{
//	if (*s == '#' && !ft_isalpha(*(s + 1)))
//		ft_error(2);
//	if (!ifisdigit_str(&s) && )
//		ft_error(2);
//
//
//
//
//
////	(*input)->start = 1;
////	(*input)->end = 1;
////	if (!((*(*input)->std_in)))
////		ft_error(1);
////	if (!(*(*(*input)->std_in)))
////		ft_error(2);
////	valid_sart_end(input);
////	valid_rooms(input);
////	valid_rooms_connect(input);
//}
