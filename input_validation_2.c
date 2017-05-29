
#include "lem_in.h"

int		valid_room_name(t_lemin **lemin, char *s)
{
	t_room *room;

	room = (*lemin)->room;
	while (room->next)
	{
		if (!ft_strcmp(room->name, s))
			return (1);
		room = room->next;
	}
	return (0);
}

int		valid_room(t_lemin **lemin, char *line)
{
	t_room	*room;
	char	**str;
	int		start_end;

	room = (*lemin)->room;
	str = ft_strsplit(line, ' ');
	start_end = check_start_end(lemin, line);
	while (room)
	{
		if (!room->name)
		{
			free_twodem_str(str);
			!start_end ? write_room(lemin, line, 0, 0) : 0;
			return (1);
		}
		else
		{
			if (!ft_strcmp(room->name, line) || room->connect || !(*lemin)->ants)
			{
				free_twodem_str(str);
				return (0);
			}
			if (!ft_strcmp(room->x, str[1]) && !ft_strcmp(room->y, str[2]))
			{
				free_twodem_str(str);
				return (0);
			}
		}
		room = room->next;
	}
	free_twodem_str(str);
	return (1);
}
