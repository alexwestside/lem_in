
#include "lem_in.h"

void	make_route_pack(t_lemin **lemin)
{
	int	i;

	i = 1;
	sort_routes(lemin, i);
	(*lemin)->pack_routes = NULL;
	init_pack_routes(lemin);
	make_pack_routes(lemin);
}

int		read_stdin(t_lemin **lemin, char *line, int fd, int *i)
{
	int	valid;

	valid = 0;
	if (type_num_ants(line))
		valid = valid_ants(lemin, ft_atoi(line), line);
	else if (type_room(line))
		valid = valid_room(lemin, line);
	else if (type_start_end(line))
		valid = valid_start_end(lemin, line, fd, i);
	else if (type_connect(line))
		valid = valid_connect(lemin, line, ft_strsplit(line, '-'), NULL);
	else if (type_comment(line))
		valid = 1;
	return (valid ? 1 : 0);
}

void	read_and_valid(t_lemin **lemin, char ***std_in)
{
	int	fd;
	int	i;

	i = -1;
	fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test7", O_RDONLY);
//	fd = 0;
	while (get_next_line(fd, &((*std_in)[++i])))
	{
		if (!(read_stdin(lemin, (*std_in)[i], fd, &i)))
			break ;
		*std_in = ft_realloc(&(*std_in), two_dem_strlen(*std_in));
	}
	free((*std_in)[i]);
	(*std_in)[i] = NULL;
	need_data_check(lemin);
}

t_room	*start_room(t_lemin *lemin)
{
	t_room	*start_room;

	start_room = lemin->room;
	while (start_room)
	{
		if (start_room->start)
			break ;
		start_room = start_room->next;
	}
	return (start_room);
}

int		main(void)
{
	t_lemin	*lemin;

	init_lemin(&lemin, 0, NULL, NULL);
	read_and_valid(&lemin, &lemin->std_in);
	dfs(&lemin, start_room(lemin));
//	print_1(lemin);
	make_route_pack(&lemin);
	make_a_choice(&lemin);
//	sleep(1000);
	return (0);
}
