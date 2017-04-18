
#include "lem_in.h"


unsigned long int ft_twodem_strlen(char **str)
{
	char **p;

	p = str;
	while (*p)
		p++;
	return ((p - str) + 1);
}


char **ft_realloc(char **std_in, unsigned long int len)
{
	char **str;
	int i = -1;

	str = (char **)malloc(sizeof(char) * len + 1);
	str[len] = NULL;
	while (std_in[++i])
		str[i] = std_in[i];
	return (str);
}

void ft_read_write(t_stdin **input)
{
//	int i = 1;
	char **str;
	int fd = open("/nfs/2016/o/orizhiy/ClionProjects/lem_in/test", O_RDONLY);

	(*input) = (t_stdin *)malloc(sizeof(t_stdin));
	(*input)->std_in = (char **)malloc(sizeof(char *) * 2);
	str = (*input)->std_in;
	*str = (char *)malloc(sizeof(char));
	str[1] = NULL;
	while (get_next_line(fd, &(*str)))
	{
//		(*str)++;
		(*input)->std_in = ft_realloc((*input)->std_in, ft_twodem_strlen((*input)->std_in));








	}







}

int main()
{
	t_stdin *input;
	ft_read_write(&input);





}