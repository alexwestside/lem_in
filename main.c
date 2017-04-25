
#include "lem_in.h"

void read_stdin(t_lemin **lemin, char *line, int fd, int *i)
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
		return ;
	else
		return;
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
		read_stdin(lemin, (*std_in)[i], fd, &i);
		*std_in = ft_realloc(&(*std_in), two_dem_strlen(*std_in));
//		free(line);
	}
	(*std_in)[i] = NULL;
}

int main()
{
//	char *s = "4-2";
//	char **str = ft_strsplit(s, '-');
//	printf("%s\n", str[0]);
//	printf("%s\n", str[1]);

	t_lemin *lemin;
//	char **std_in;


	init_lemin(&lemin, 0, NULL, NULL);
	read_and_valid(&lemin, &lemin->std_in);


//	int i = 0;
//	while (lemin->std_in[i])
//	{
//		ft_printf("%s\n", lemin->std_in[i]);
//		i++;
//	}

}

