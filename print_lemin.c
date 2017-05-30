
#include "lem_in.h"

void	move_new_ants(t_routes **routes, t_lemin **lemin, int *ant)
{
	t_routes	*rs;
	t_route		*r;

	rs = (*routes);
	while (rs)
	{
		r = rs->route->next;
		if (!r->ant)
		{
			if ((*ant) <= (*lemin)->ants)
			{
				r->ant = *ant;
				ft_printf("L%d-%s ", *ant, r->room);
				(*ant)++;
			}
		}
		rs = rs->next;
	}
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
			r->next->ant = r->ant;
			r->ant = 0;
			ft_printf("L%d-%s ", r->next->ant, r->next->room);
			check_ant_in_end(&(*routes)->route, lemin);
			rs = rs->next;
			if (!rs)
				rs = (*routes);
		}
		else
			break ;
	}
}

void	push_old_ants(t_routes **routes, t_lemin **lemin)
{
	t_routes	*rs;
	t_route		*r;

	rs = (*routes);
	while (routes_is_ampty(routes) && (r = rs->route->next))
	{
		if (route_is_ampty(r))
		{
			while (r->next->room)
			{
				if (r->ant && !r->next->ant)
					break ;
				r = r->next;
			}
			r->next->ant = r->ant;
			r->ant = 0;
			ft_printf("L%d-%s ", r->next->ant, r->next->room);
			end(&(r->next), lemin);
		}
		rs = rs->next;
		if (!rs)
			ft_printf("\n");
		if (!rs)
			rs = *routes;
	}
}

void	push_one_route(t_routes **routes, t_lemin **lemin, int flag, int ant)
{
	t_routes	*rs;
	t_route		*r;

	rs = *routes;
	r = rs->route;
	while (!r->ant)
		r = r->next;
	ant = r->ant;
	while (route_is_ampty(r))
	{
		flag = 0;
		while (r->next->room)
		{
			if (r->ant && !r->next->ant)
				break ;
			r = r->next;
		}
		r->ant == ant ? flag = 1 : 0;
		r->next->ant = r->ant;
		r->ant = 0;
		ft_printf("L%d-%s ", r->next->ant, r->next->room);
		end(&(r->next), lemin);
		r = rs->route;
		flag == 1 ? ft_printf("\n") : 0;
	}
}

void	print_lemin(t_routes **routes, t_lemin **lemin, int ant)
{
	print_stdin(lemin);
	move_new_ants(routes, lemin, &ant);
	ft_printf("\n");
	while (ant <= (*lemin)->ants)
	{
		move_old_ants(routes, lemin);
		if (ant <= (*lemin)->ants)
			move_new_ants(routes, lemin, &ant);
		ft_printf("\n");
	}
	(*routes)->next ? push_old_ants(routes, lemin) :
	push_one_route(routes, lemin, 0, 0);
}
