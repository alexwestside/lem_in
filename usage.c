
#include "lem_in.h"

void	ft_error(int id)
{
	if (id == 1 || id == 2)
	{
		id == 1 ? ft_printf("EMPTY stream INPUT!!!\n") : 0;
		id == 2 ? ft_printf("NOT a VALID input!!!\n") : 0;
		exit(0);
	}
}

void print_ants(int *ant, char *s, t_lemin **lemin)
{



}