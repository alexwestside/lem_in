
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
	if (!hard_data_check(lemin))
		ft_error(2);

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

int hard_data_check(t_lemin **lemin)
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
	while (queue[i])
	{
		i = j;
		room = (*lemin)->room;
		while (room->name)
		{
			if (!ft_strcmp(queue[i], room->name))
			{
				connect = room->connect;
				while (connect)
				{
					queue[++i] = connect->room->name;
					connect = connect->next;
				}
				break ;
			}
			room = room->next;
		}
		i = j;
		visit[i] = queue[i];
		if (check_visit(lemin, visit[i]))
			return (1);
		j++;
	}
	return (0);
}


int check_visit(t_lemin **lemin, char *s)
{
	t_room *room;

	room = (*lemin)->room;
	while (room->next)
	{
		if (!ft_strcmp(room->name, s))
		{
			if (room->end)
				return (1);
		}
		room = room->next;
	}
	return (0);
}