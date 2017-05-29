
#include "lem_in.h"

int		count_ants(char *s)
{
	long int	n;

	n = 0;
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (limit_int(n) ? 1 : 0);
}

int		check_start_end(t_lemin **lemin, char *line)
{
	char	**s;

	s = (*lemin)->std_in;
	while (ft_strcmp(*s, line))
		s++;
	s--;
	if (!ft_strcmp(*s, "##start") || !ft_strcmp(*s, "##end"))
		return (1);
	return (0);
}

void	free_visit_and_queue(char **visit, char **queue)
{
	while (*visit)
	{
		*visit = NULL;
		visit++;
	}
	while (*queue)
	{
		*queue = NULL;
		queue++;
	}
}

char	*is_end(t_lemin **lemin)
{
	t_room	*room;

	room = (*lemin)->room;
	while (room)
	{
		if (room->end)
			break ;
		room = room->next;
	}
	return (room->name);
}
