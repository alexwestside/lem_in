
#include "lem_in.h"

void need_data_check(t_lemin **lemin)
{
	simple_data_check(lemin);

	t_room *room;
	int i = -1;

	room = (*lemin)->room;
	while (room && i++)
		room = room->next;
	init_queue_visit(lemin, i);
	hard_data_check(lemin);

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
		if (type_connect(*str))
			data++;
		str++;
	}
	if (data != 4)
		ft_error(2);
}

void hard_data_check(t_lemin **lemin)
{








}
