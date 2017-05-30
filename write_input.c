
#include "lem_in.h"

void	write_ants(t_lemin **lemin, char *line)
{
	(*lemin)->ants = ft_atoi(line);
}

void	write_room(t_lemin **lemin, char *line, int start, int end)
{
	t_room	*room;
	char	**str;

	room = (*lemin)->room;
	while (room->next)
		room = room->next;
	if (!room->name)
	{
		str = ft_strsplit(line, ' ');
		room->name = ft_strdup(str[0]);
		room->x = ft_strdup(str[1]);
		room->y = ft_strdup(str[2]);
		room->start = start;
		room->end = end;
		free_twodem_str(str);
	}
	init_room(&(room->next));
}

void	write_connect(t_lemin **lemin, char *line, char **str)
{
	t_room		*room;
	t_connect	*connect;

	room = (*lemin)->room;
	while (room->next)
	{
		if (!ft_strcmp(room->name, str[0]) || !ft_strcmp(room->name, str[1]))
		{
			write_connect_if(str, &room, &connect);
		}
		room = room->next;
	}
	free_twodem_str(str);
}

void	write_connect_if(char **str, t_room **room, t_connect **connect)
{
	if (!(*room)->connect)
	{
		init_connect(&((*room)->connect));
		(*room)->connect->room->name = !ft_strcmp((*room)->name,
		str[0]) ? ft_strdup(str[1]) : ft_strdup(str[0]);
	}
	else
	{
		(*connect) = (*room)->connect;
		while ((*connect)->next)
		{
			if (!ft_strcmp((*connect)->room->name, !ft_strcmp((*room)->name,
			str[0]) ? str[1] : str[0]))
			{
				free_twodem_str(str);
				break ;
			}
			(*connect) = (*connect)->next;
		}
		init_connect(&((*connect)->next));
		(*connect)->next->room->name = !ft_strcmp((*room)->name,
		str[0]) ? ft_strdup(str[1]) : ft_strdup(str[0]);
	}
}

void	write_check_start_end(t_lemin **lemin, char *line, int fd, int *i)
{
	char	*s;

	s = ft_strdup(line);
	(*lemin)->std_in = ft_realloc(&(*lemin)->std_in,
	two_dem_strlen((*lemin)->std_in));
	get_next_line(fd, &((*lemin)->std_in[++(*i)]));
	if (type_room((*lemin)->std_in[(*i)]))
	{
		valid_room(lemin, (*lemin)->std_in[(*i)]);
		if (!ft_strcmp(s, "##start"))
			write_room(lemin, (*lemin)->std_in[(*i)], 1, 0);
		if (!ft_strcmp(s, "##end"))
			write_room(lemin, (*lemin)->std_in[(*i)], 0, 1);
		free(s);
	}
	else
	{
		free(s);
		return ;
	}
}
