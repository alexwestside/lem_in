
#include "lem_in.h"

void print_lemin(t_pack_routes *choice, t_lemin **lemin)
{
	int ant;
	t_routes *rs;
	t_route *r;
	int count_routes;

	ant = 1;
	rs = choice->routes;
	count_routes = choice->count_routes;
	while (ant <= (*lemin)->ants)
	{
		r = rs->route;
		while (r->next)
		{
			ft_printf("L%d-%s ", ant, r->room);
			r = r->next;
		}
		ft_printf("\n");
		ant++;
	}
}