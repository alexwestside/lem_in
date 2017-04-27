
#include "lem_in.h"

void need_data_check(t_lemin **lemin)
{
	simple_data_check(lemin);

	t_room *room;
	int i = -1;

	room = (*lemin)->room;
	while (room)
	{
		room = room->next;
		i++;
	}
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
	if (data < 4)
		ft_error(2);
}

void hard_data_check(t_lemin **lemin)
{
	t_room *room;
	t_connect *connect;
	char **queue;
	char **visit;
	int i = 0;
	int j = 0;

	queue = (*lemin)->queue;
	visit = (*lemin)->visit;
	room = (*lemin)->room;
	while (room)
	{
		if (room->start)
		{
			queue[i] = room->name;
			break;
		}
		room = room->next;
	}
	while (!queue[i])
	{
		room = (*lemin)->room;
		while (!ft_strcmp(*queue, room->name))
		{
			connect = room->connect;
			while (connect)
			{
				queue[++i] = connect->room->name;
				connect = connect->next;
			}
			room = room->next;
		}
		queue++;
	}











}
