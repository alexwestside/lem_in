
#include "lem_in.h"

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
//	ft_input_valid(&input);



//	int i = 0;
//	while (input->std_in[i])
//	{
//		ft_printf("%s\n", input->std_in[i]);
//		i++;
//	}
}