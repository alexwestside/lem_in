
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



