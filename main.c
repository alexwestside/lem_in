
#include "lem_in.h"

void read_stdin(t_lemin **lemin, char *line)
{
	if (type_num_ants(line))
	{
		valid_ants(lemin, ft_atoi(line));
	}
	else if (type_room(line))
	{
		return;
	}
	else if (type_start_end(line))
	{
		valid_start_end(lemin);
	}
	else if (type_connect(line))
	{
		return;
	}
	else if (type_comment(line))
	{
		return;
	}
	else
		ft_error(2);
}


void read_and_valid(t_lemin **lemin, char ***std_in)
{
	int fd;
	char *line;
	t_lemin *lem_list;
	t_room *room_list;
	int i;

	i = -1;
	lem_list = (*lemin);
	room_list = (*lemin)->room;
	fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test4", O_RDONLY);
	while (get_next_line(fd, &((*std_in)[++i])))
	{
		read_stdin(lemin, (*std_in)[i]);
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
	char **std_in;

	std_in = (char **)malloc(sizeof(char *) * 2);
	std_in[1] = NULL;
	init_lemin(&lemin, 0, NULL, NULL);
	read_and_valid(&lemin, &std_in);


}





//int main()
//{
//	t_stdin *input;
//	input = (t_stdin *)malloc(sizeof(t_stdin));
//	input->std_in = (char **)malloc(sizeof(char *) * 2);
//	input->std_in[1] = NULL;
//	ft_read_write(&input);
//	ft_input_valid(&input);
//
//	int i = 0;
//	while (input->std_in[i])
//	{
//		ft_printf("%s\n", input->std_in[i]);
//		i++;
//	}
//}