
#include "lem_in.h"

int if_is_digit_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int limit_int(long int n)
{
	if (n >	2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int valid_ants(char *s)
{
	char *p;
	long int n;

	n = 0;
	p = s;
	if (!if_is_digit_str(p))
		ft_error(2);
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (limit_int(n) ? 1 : 0);
}

void read_stdin(t_lemin **lemin, char *line)
{
	if (valid_ants(line))
	{





	}
	else
		ft_error(2);
}

void read_and_valid(t_lemin **lemin)
{
	int fd;
	char *line;
	t_lemin *lem_list;
	t_room *room_list;

	lem_list = (*lemin);
	room_list = (*lemin)->room;
	fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test4", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		read_stdin(lemin, line);
		free(line);
	}


}

void init_room(t_room **room)
{
	*room = (t_room *)malloc(sizeof(t_room));

	(*room)->id_room = 0;
	(*room)->x = 0;
	(*room)->y = 0;
	(*room)->connect = NULL;
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->ants = 0;
	(*room)->next = NULL;
}

void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next)
{
	*lemin = (t_lemin *)malloc(sizeof(t_lemin));
	(*lemin)->room = (t_room *)malloc(sizeof(t_room));
	init_room(&((*lemin)->room));
	(*lemin)->rout = (t_route* )malloc(sizeof(t_route));

	(*lemin)->ants = ants;
	(*lemin)->name = name;
	(*lemin)->next = next;
}

int main()
{
	t_lemin *lemin;

	init_lemin(&lemin, 0, NULL, NULL);
	read_and_valid(&lemin);



}






unsigned long int ft_two_dem_strlen(char **s)
{
	char **p;

	p = s;
	while (*p)
		p++;
	return ((p - s) + 1);
}


char **ft_realloc(char ***std_in, unsigned long int len)
{
	char **str;
	int i;

	i = -1;
	str = (char **)malloc(sizeof(char *) * (len + 1));
	str[len] = NULL;
	while ((*std_in)[++i])
		str[i] = (*std_in)[i];
	str[i] = NULL;
	free(*std_in);
	return (str);
}

void ft_read_write(t_stdin **input)
{
	int i;
	int fd;

	i = -1;
	fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test4", O_RDONLY);
	while (get_next_line(fd, &((*input)->std_in[++i])))
	{
		ft_input_valid(input, (*input)->std_in[i]);
		(*input)->std_in = ft_realloc(&(*input)->std_in, ft_two_dem_strlen((*input)->std_in));
	}
	(*input)->std_in[i] = NULL;
}

int main()
{
	t_stdin *input;
	input = (t_stdin *)malloc(sizeof(t_stdin));
	input->std_in = (char **)malloc(sizeof(char *) * 2);
	input->std_in[1] = NULL;
	ft_read_write(&input);
	ft_input_valid(&input);

	int i = 0;
	while (input->std_in[i])
	{
		ft_printf("%s\n", input->std_in[i]);
		i++;
	}
}