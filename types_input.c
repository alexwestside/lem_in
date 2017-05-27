
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
	char **s;
	unsigned long int len;

	if (!str)
		return (0);
	s = ft_strsplit(str, ' ');
	len = two_dem_strlen(s) - 1;
	if (len != 3)
	{
		free_twodem_str(s);
		return (0);
	}
	if (if_is_alnum_str(s[0]))
	{
		if (if_is_digit_sign_str(s[1]) && if_is_digit_sign_str(s[2]))
		{
			if (limit_int(atoi_lemin(s[1])) && limit_int(atoi_lemin(s[2])))
			{
				free_twodem_str(s);
				return (1);
			}
		}
	}
	free_twodem_str(s);
	return (0);
}

int type_start_end(char *str)
{
	if (!strcmp(str, "##start") || !strcmp(str, "##end"))
		return (1);
	return (0);
}

int type_connect(char *str)
{
	char **s;
	unsigned long int len;

	s = ft_strsplit(str, '-');
	len = two_dem_strlen(s) - 1;
	if (len == 2)
		if (if_is_alnum_str(s[0]) || if_is_alnum_str(s[1]))
			return (1);
	return (0);
}

int type_comment(char *str)
{
	if (*str == '#' && (ft_strcmp(str, "##start") && ft_strcmp(str, "##end")))
		return (1);
	return (0);
}
