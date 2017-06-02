
#include "lem_in.h"

void	move_old_ants_1(t_route **route, t_lemin **lemin)
{
	t_route	*r;

	r = (*route);
	r->next->ant = r->ant;
	r->ant = 0;
	print_ants(&r->next->ant, r->next->room, lemin, 1);
//	ft_printf("L%d-%s ", r->next->ant, r->next->room);
	check_ant_in_end(&(r->next), lemin);
}

void	move_old_ants(t_routes **routes, t_lemin **lemin)
{
	t_routes	*rs;
	t_route		*r;

	rs = (*routes);
	while (rs)
	{
		r = rs->route->next;
		if (r->ant)
		{
			while (r->next->ant)
				r = r->next;
			move_old_ants_1(&r, lemin);
			rs = rs->next;
			(!rs) ? rs = (*routes) : 0;
		}
		else
		{
			if (!rs->next)
				return ;
			if (rs->next->route->next->ant)
				rs = rs->next;
			else
				break ;
		}
	}
}
