
#include "lem_in.h"

void	need_data_check(t_lemin **lemin)
{
	t_room	*room;
	int		i;

	i = 1;
	simple_data_check(lemin);
	room = (*lemin)->room;
	while (room)
	{
		room = room->next;
		i++;
	}
	init_queue_visit(lemin, i);
	if (!hard_data_check(lemin, -1, (*lemin)->queue, (*lemin)->visit))
		ft_error(2);
}

void	simple_data_check(t_lemin **lemin)
{
	char	**str;
	int		data;

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

void	hard_data_check_1(char **queue, t_connect **connect, t_room **room)
{
	rewrite_queue(&queue);
	*connect = (*room)->connect;
	fill_queue(*connect, &queue);
}

int		hard_data_check(t_lemin **lemin, int j, char **queue, char **visit)
{
	t_room		*room;
	t_connect	*connect;

	find_start(lemin, &queue);
	while (queue[0] && (room = (*lemin)->room))
		if (check_visit(queue[0], visit))
			while (room->name)
			{
				if (!ft_strcmp(queue[0], room->name))
				{
					visit[++j] = queue[0];
					if (check_visit_end(lemin, visit[j]))
					{
						free_visit_and_queue((*lemin)->visit, (*lemin)->queue);
						return (1);
					}
					hard_data_check_1(queue, &connect, &room);
					break ;
				}
				room = room->next;
			}
		else
			rewrite_queue(&queue);
	return (0);
}
