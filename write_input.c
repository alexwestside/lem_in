
#include "lem_in.h"

void write_ants(t_lemin **lemin, char *line)
{
	(*lemin)->ants = ft_atoi(line);
}

void write_room(t_lemin **lemin, char *line, int start, int end)
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
		room->start = start;
		room->end = end;
	}
	init_room(&(room->next));
}

void write_connect(t_lemin **lemin, char *line)
{
	char **str;
	t_room *room;
	t_connect *connect;

	str = ft_strsplit(line, '-');
	room = (*lemin)->room;
	while (room->next)
	{
		if (!ft_strcmp(room->name, str[0]) || !ft_strcmp(room->name, str[1]))
		{
			if (!room->connect)
			{
				init_connect(&(room->connect));
				room->connect->room->name = !ft_strcmp(room->name, str[0]) ? str[1] : str[0];
//				return;
			}
			else
			{
				connect = room->connect;
				while (connect->next)
				{
					if (!ft_strcmp(connect->room->name, !ft_strcmp(room->name, str[0]) ? str[1] : str[0]))
						break ;
					connect = connect->next;
				}
				init_connect(&(connect->next));
				connect->next->room->name = !ft_strcmp(room->name, str[0]) ? str[1] : str[0];
//				return;
			}
		}
		room = room->next;
	}
}

void write_check_start_end(t_lemin **lemin, char *line, int fd, int *i)
{
// 	(*lemin)->std_in;
	get_next_line(fd, &((*lemin)->std_in[++(*i)]));
	if (type_room((*lemin)->std_in[(*i)]))
	{
		valid_room(lemin, (*lemin)->std_in[(*i)]);
		if (!ft_strcmp(line, "##start"))
			write_room(lemin, (*lemin)->std_in[(*i)], 1, 0);
		if (!ft_strcmp(line, "##end"))
			write_room(lemin, (*lemin)->std_in[(*i)], 0, 1);
		(*lemin)->std_in = ft_realloc(&(*lemin)->std_in, two_dem_strlen((*lemin)->std_in));
	}
	else
		return ;
}

