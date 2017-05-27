
#include "lem_in.h"


void free_twodem_str(char **s)
{
	int i = 0;

	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

void free_lemin(t_lemin **lemin)
{



}