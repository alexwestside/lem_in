
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
	if ((*lemin)->ants)
		data++;
	while (*str)
	{
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
	find_start(lemin, &queue);
	while (queue[i])
	{
		i = 0;
		room = (*lemin)->room;
		if (check_visit(queue[i], visit))
		{
			while (room->name)
			{
				if (!ft_strcmp(queue[i], room->name))
				{
					visit[j] = queue[i];
					if (check_visit_end(lemin, visit[j]))
						return (1);
					rewrite_queue(&queue);
					connect = room->connect;
					fill_queue(connect, &queue);
					break;
				}
				room = room->next;
			}
			j++;
		}
		else
			rewrite_queue(&queue);
	}
	return (0);
}


int check_visit_end(t_lemin **lemin, char *s)
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

int check_visit(char *name, char **visit)
{
	while (*visit)
	{
		if (!ft_strcmp(*visit, name))
			return (0);
		visit++;
	}
	return (1);
}

void rewrite_queue(char ***queue)
{
	char **s;
	int i = 0;

	s = (*queue);
	while (s[i])
	{
		if (i == 0)
			i++;
		s[i - 1] = s[i];
		i++;
	}
	s[i - 1] = NULL;
}

void fill_queue(t_connect *connect, char ***queue)
{
	int i = 0;

	while ((*queue)[i])
		i++;
	while (connect)
	{
		(*queue)[i++] = connect->room->name;
		connect = connect->next;
	}
}

void find_start(t_lemin **lemin, char ***queue)
{
	t_room *room;
	int i = 0;

	room = (*lemin)->room;
	while (room)
	{
		if (room->start)
		{
			(*queue)[i] = room->name;
			break;
		}
		room = room->next;
	}
}