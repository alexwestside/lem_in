
#include "lem_in.h"

void write_ants(t_lemin **lemin, char *line)
{
	(*lemin)->ants = ft_atoi(line);
}

void write_room(t_lemin **lemin, char *line)
{
	t_room *room;
	char **str;

	str = ft_strsplit(line, ' ');
	room = (*lemin)->room;
	while (room->next)
		room = room->next;
	if (!room->name)
	{
		room->name = str[0];
		room->x = str[1];
		room->y = str[2];
	}
	init_room(&room);
}

void write_connect(t_lemin **lemin, char *line)
{
	char **str;
	t_room *room;
	t_connect *connect;

	str = ft_strsplit(line, ' ');
	room = (*lemin)->room;
	while (room->next)
	{
		connect = room->connect;
		if (!ft_strcmp(room->name, str[0]))
		{
			while(connect->next)
				connect = connect->next;
			init_connect(&connect->next);
			connect->next->room = str[1];
		}
		room = room->next;
	}
}



