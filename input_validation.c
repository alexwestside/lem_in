
#include "lem_in.h"

int		valid_ants(t_lemin **lemin, int ants, char *line)
{
	t_lemin	*list;

	list = *lemin;
	while (list)
	{
		if (list->ants)
			return (0);
		else
			list->ants = ants;
		list = list->next;
	}
	write_ants(lemin, line);
	return (1);
}

int		valid_start_end(t_lemin **lemin, char *line, int fd, int *i)
{
	t_room		*room;
	t_connect	*connect;

	room = (*lemin)->room;
	while (room)
	{
		connect = room->connect;
		while (connect)
		{
			if (connect->room)
				return (0);
			connect = connect->next;
		}
		room = room->next;
	}
	write_check_start_end(lemin, line, fd, i);
	return (1);
}

int		valid_connect(t_lemin **lemin, char *line, char **str, t_room *room)
{
	t_connect	*connect;

	room = (*lemin)->room;
	while (room)
	{
		if (room->name && (!ft_strcmp(str[0], room->name) ||
	!ft_strcmp(str[1], room->name)))
		{
			connect = room->connect;
			if (!valid_room_name(lemin, !ft_strcmp(str[0], room->name) ?
	str[1] : str[0]))
				return (free_twodem_str(str) == NULL ? 0 : 0);
			while (connect)
			{
				if (!ft_strcmp(!ft_strcmp(str[0], room->name) ?
	str[1] : str[0], connect->room->name))
					return (free_twodem_str(str) == NULL ? 0 : 0);
				connect = connect->next;
			}
			write_connect(lemin, line, ft_strsplit(line, '-'));
			return (free_twodem_str(str) == NULL ? 1 : 1);
		}
		room = room->next;
	}
	return (free_twodem_str(str) == NULL ? 0 : 0);
}
