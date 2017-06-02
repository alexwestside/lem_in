
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
				print_ants(ant, r->room, lemin, 0);
//				ft_printf("L%d-%s ", *ant, r->room);
				(*ant)++;
			}
		}
		rs = rs->next;
	}
}

void	move_old_route(t_route **route, t_lemin **lemin)
{
	t_route	*r;

	r = *route;
	if (route_is_ampty(r))
	{
		while (!r->ant && !r->move)
			r = r->next;
		while (r->next->ant)
			r = r->next;
		if (!r->move && r->ant)
		{
			r->next->ant = r->ant;
			r->next->move = 1;
			r->ant = 0;
			r->move = 0;
//			ft_printf("L%d-%s ", r->next->ant, r->next->room);
			print_ants(&r->next->ant, r->next->room, lemin, 1);
			end(&(r->next), lemin);
		}
	}
}

void	push_old_ants(t_routes **routes, t_lemin **lemin)
{
	t_routes	*rs;
	t_route		*r;

	rs = *routes;
	while (routes_is_ampty(routes))
	{
		if (move_all_old(&rs, lemin))
		{
			move_all_null(&rs, lemin);
			ft_printf("\n");
		}
		r = rs->route->next;
		move_old_route(&r, lemin);
		rs = rs->next;
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
		print_ants(&r->next->ant, r->next->room, lemin, 1);
//		ft_printf("L%d-%s ", r->next->ant, r->next->room);
		end(&(r->next), lemin);
		r = rs->route;
		flag == 1 ? ft_printf("\n") : 0;
	}
}

void	print_lemin(t_routes **routes, t_lemin **lemin, int ant)
{
	print_stdin(lemin);
	if ((*lemin)->pack_routes->count_routes >= 1 && (*routes)->len_route > 1)
	{
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
		(*routes)->next ? ft_printf("\n") : 0;
	}
	else
		print_start_end(routes, lemin, 1);
}
