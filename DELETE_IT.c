//
// Created by Olexandr Rizhiy on 5/29/17.
//

#include "lem_in.h"

void	print_1(t_lemin *lemin)
{
	t_routes	*rs;
	t_route		*r;
	int			route;

	route = 1;
	rs = lemin->routes;
	while (rs)
	{
		ft_printf("Route #%d, Len = %d, Links: ", route, rs->len_route);
		route++;
		r = rs->route;
		while (r->room)
		{
			ft_printf("%s", r->room);
			if (ft_strcmp(r->room, "f"))
				ft_printf(" - ");
			r = r->next;
		}
		ft_printf("\n");
		rs = rs->next;
	}
}

void print_2(t_routes *routes)
{
	t_routes *rs;
	t_route *r;

	rs = routes;
	while (rs->next->route->room)
		rs = rs->next;
	r = rs->route;
	while (r->room)
	{
		ft_printf("%s - ", r->room);
		r = r->next;
	}
	ft_printf("\n");
}

void print_3(t_routes *routes)
{
	t_route *r;

	r = routes->route;
	while (r->next)
	{
		ft_printf("%s - ", r->room);
		r = r->next;
	}
	ft_printf("\n");
}

void print_4(t_lemin **lemin)
{
	t_pack_routes *prs;
	t_routes *rs;
	t_route *r;

	ft_printf("\n\n");
	prs = (*lemin)->pack_routes;
	while (prs)
	{
		rs = prs->routes;
		while (rs)
		{
			r = rs->route;
			while (r->next)
			{
				ft_printf("%s - ", r->room);
				r = r->next;
			}
			rs = rs->next;
			ft_printf("\n");
		}
		prs = prs->next;
		ft_printf("\n");
	}
}