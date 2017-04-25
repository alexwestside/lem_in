
#include "lem_in.h"

int read_stdin(t_lemin **lemin, char *line, int fd, int *i)
{
	if (type_num_ants(line))
	{
		valid_ants(lemin, ft_atoi(line));
		write_ants(lemin, line);
	}
	else if (type_room(line))
	{
		valid_room(lemin, line);
		write_room(lemin, line, 0, 0);
	}
	else if (type_start_end(line))
	{
		valid_start_end(lemin);
		write_check_start_end(lemin, line, fd, i);
	}
	else if (type_connect(line))
	{
		valid_connect(lemin, line);
		write_connect(lemin, line);
	}
	else if (type_comment(line))
		return (1);
	return (0);
}

void read_and_valid(t_lemin **lemin, char ***std_in)
{
	int fd;
	char *line;
	int i;

	i = -1;
	fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test4", O_RDONLY);
	while (get_next_line(fd, &((*std_in)[++i])))
	{
		if (!(read_stdin(lemin, (*std_in)[i], fd, &i)))
			break;
		*std_in = ft_realloc(&(*std_in), two_dem_strlen(*std_in));
//		free(line);
	}
	(*std_in)[i] = NULL;
}

int main()
{
	t_lemin *lemin;

	init_lemin(&lemin, 0, NULL, NULL);
	read_and_valid(&lemin, &lemin->std_in);

//	int i = 0;
//	while (lemin->std_in[i])
//	{
//		ft_printf("%s\n", lemin->std_in[i]);
//		i++;
//	}

}

