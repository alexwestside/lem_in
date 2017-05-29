
#include "lem_in.h"

int		check_visit_end(t_lemin **lemin, char *s)
{
	t_room	*room;

	room = (*lemin)->room;
	if (s)
	{
		while (room->next)
		{
			if (!ft_strcmp(room->name, s))
			{
				if (room->end)
					return (1);
			}
			room = room->next;
		}
	}
	return (0);
}

int		check_visit(char *name, char **visit)
{
	while (*visit)
	{
		if (!ft_strcmp(*visit, name))
			return (0);
		visit++;
	}
	return (1);
}

void	rewrite_queue(char ***queue)
{
	char	**s;
	int		i;

	i = 0;
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

void	fill_queue(t_connect *connect, char ***queue)
{
	int	i;

	i = 0;
	while ((*queue)[i])
		i++;
	while (connect)
	{
		(*queue)[i++] = connect->room->name;
		connect = connect->next;
	}
}

void	find_start(t_lemin **lemin, char ***queue)
{
	t_room	*room;
	int		i;

	i = 0;
	room = (*lemin)->room;
	while (room)
	{
		if (room->start)
		{
			(*queue)[i] = room->name;
			break ;
		}
		room = room->next;
	}
}
