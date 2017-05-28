
#include "lem_in.h"

unsigned long int two_dem_strlen(char **s)
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
		str[i] = ft_strdup((*std_in)[i]);
	str[i] = NULL;
	free(*std_in);
	return (str);
}