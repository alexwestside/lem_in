
#include "lem_in.h"

void need_data_check(t_lemin **lemin)
{
	simple_data_check(lemin);


}

void simple_data_check(t_lemin **lemin)
{
	char **str;
	int data;

	data = 0;
	str = (*lemin)->std_in;
	while (*str)
	{
		if ((*lemin)->ants)
			data++;
		if (!ft_strcmp(*str, "##start"))
			data++;
		if (!ft_strcmp(*str, "##end"))
			data++;
		if ()



		str++;
	}
}
