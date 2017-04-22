
#include "lem_in.h"

//int if_is_digit_str(char *s)
//{
//	char *p;
//
//	p = s;
//	while (*p)
//	{
//		if (!ft_isdigit(*p))
//			return (0);
//		p++;
//	}
//	return (1);
//}
//
//int limit_int(long int n)
//{
//	if (n >	2147483647 || n < -2147483648)
//		return (0);
//	return (1);
//}
//
//int valid_ants(char *s)
//{
//	char *p;
//	long int n;
//
//	n = 0;
//	p = s;
//	if (!if_is_digit_str(p))
//		ft_error(2);
//	while (*s)
//	{
//		n = n * 10 + *s - '0';
//		s++;
//	}
//	return (limit_int(n) ? 1 : 0);
//}
//
void read_stdin(t_lemin **lemin, char *line)
{
	if (valid_ants(line))
	{





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