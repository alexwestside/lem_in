
#include "lem_in.h"

int valid_ants(t_lemin **lemin, int ants, char *line)
{
	t_lemin *list;

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

int valid_room(t_lemin **lemin, char *line)
{
	t_room *room;
	char **str;
	int start_end;

	room = (*lemin)->room;
	str = ft_strsplit(line, ' ');
	start_end = check_start_end(lemin, line);
	while (room)
	{
		if (!room->name)
		{
			!start_end ? write_room(lemin, line, 0, 0) : 0;
			return (1);
		}
		else
		{
			if (!ft_strcmp(room->name, line) || room->connect || !(*lemin)->ants)
				return (0);
			if (!ft_strcmp(room->x, str[1]) && !ft_strcmp(room->y, str[2]))
				return (0);
		}
		room = room->next;
	}
//	write_room(lemin, line, 0, 0);
	return (1);
}

int valid_start_end(t_lemin **lemin, char *line, int fd, int *i)
{
	t_room *room;
	t_connect *connect;

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

int valid_connect(t_lemin **lemin, char *line)
{
	char **str;
	t_room *room;
	t_connect *connect;
//	int flag;

	str = ft_strsplit(line, '-');
	room = (*lemin)->room;
//	flag = 0;
	while (room)
	{
		if (room->name)
		{
			if (!ft_strcmp(str[0], room->name) || !ft_strcmp(str[1], room->name))
			{
				connect = room->connect;
				if (!valid_room_name(lemin, !ft_strcmp(str[0], room->name) ?  str[1] : str[0]))
					return (0);
				while (connect)
				{
					if (!ft_strcmp(!ft_strcmp(str[0], room->name) ? str[1] : str[0], connect->room->name))
						return (0);
					connect = connect->next;
				}
//				flag++;
				write_connect(lemin, line);
				return (1);
			}
		}
		room = room->next;
	}
//	if (!flag)
//		return (0);
//	write_connect(lemin, line);
	return (0);
}

int valid_room_name(t_lemin **lemin, char *s)
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