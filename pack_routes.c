
#include "lem_in.h"

void sort_routes(t_lemin **lemin, int i)
{
	t_routes *routes;
	t_routes *tmp;

	while (i)
	{
		i = 0;
		routes = (*lemin)->routes;
		while (routes)
		{
			if (routes->next)
			{
				if (routes->len_route > routes->next->len_route)
				{
					tmp = routes->next;
					tmp->prev = routes->prev;
					tmp->next ? tmp->next->prev = routes : 0;
					routes->next = tmp->next;
					tmp->next = routes;
					routes->prev ? routes->prev->next = tmp : 0;
					routes->prev = tmp;
					routes = tmp;
					i = 1;
				}
				routes = routes->next;
			}
			else
				break;
		}
	}
	ft_printf("\n");
	print_1(*lemin);
}

void init_pack_routes(t_lemin **lemin)
{
	t_pack_routes *pack_routes;

	pack_routes = (*lemin)->pack_routes;
	if (!pack_routes)
	{
		(*lemin)->pack_routes = (t_pack_routes *) malloc(sizeof(t_pack_routes));
		(*lemin)->pack_routes->count_routes = 0;
		(*lemin)->pack_routes->next = NULL;
		(*lemin)->pack_routes->routes = (t_routes *) malloc(sizeof(t_routes));
		(*lemin)->pack_routes->routes->next = NULL;
		(*lemin)->pack_routes->routes->prev = NULL;
		(*lemin)->pack_routes->routes->len_route = -1;
		(*lemin)->pack_routes->routes->route = (t_route *) malloc(sizeof(t_route));
		(*lemin)->pack_routes->routes->route->next = NULL;
		(*lemin)->pack_routes->routes->route->room = NULL;
	}
	else
	{
		while(pack_routes->next)
			pack_routes = pack_routes->next;
		pack_routes->next = (t_pack_routes *) malloc(sizeof(t_pack_routes));
		pack_routes->next->count_routes = 0;
		pack_routes->next->next = NULL;
		pack_routes->next->routes = (t_routes *) malloc(sizeof(t_routes));
		pack_routes->next->routes->next = NULL;
		pack_routes->next->routes->prev = NULL;
		pack_routes->next->routes->len_route = -1;
		pack_routes->next->routes->route = (t_route *) malloc(sizeof(t_route));
		pack_routes->next->routes->route->next = NULL;
		pack_routes->next->routes->route->room = NULL;
	}
}

void add_route(t_routes **routes, t_routes *rs)
{
	t_routes *prs;
	t_route *r;

	prs = (*routes);
	while (prs->next)
		prs = prs->next;
	prs->next = (t_routes *)malloc(sizeof(t_routes));
	prs->next->next = NULL;
	prs->next->prev = prs;
	prs->next->route = (t_route *)malloc(sizeof(t_route));
	prs->next->route->room = NULL;
	prs->next->route->next = NULL;
	prs->next->len_route= 0;
	prs->next->route = rs->route;
	prs->next->len_route = rs->len_route;
}

int check_cross2(t_route *r1, t_route *r2)
{
	t_route *r2_;
	int i = 0;

	while (r1->next)
	{
		r2_ = r2;
		while (r2_->next->next)
		{
			if (i && r2_->next->next && !ft_strcmp(r1->room, r2_->room))
				return (0);
			r2_ = r2_->next;
			i++;
		}
		r1 = r1->next;
	}
	return (1);
}

int check_cross1(t_routes **routes, t_route *route)
{
	t_routes *rs;
	t_route *r1;
	t_route *r2;
//	int i = 0;

	rs = (*routes);
	r2 = route;
	while (rs)
	{
		r1 = rs->route;
		if (check_cross2(r1, r2))
			rs = rs->next;
		else
			return (0);
	}
	return (1);
}

void make_pack_routes(t_lemin **lemin)
{
	t_routes *routes;
	t_routes *rs;
	t_pack_routes *pack_routes;

	routes = (*lemin)->routes;
	pack_routes = (*lemin)->pack_routes;
	while (routes)
	{
		pack_routes->routes->route = routes->route;
		pack_routes->routes->len_route = routes->len_route;

		rs = (*lemin)->routes;
		while (rs)
		{
			if (check_cross1(&(pack_routes->routes), rs->route))
				add_route(&(pack_routes->routes), rs);
			rs = rs->next;
		}
		routes = routes->next;
		init_pack_routes(lemin);
		pack_routes	= pack_routes->next;
	}
}

void make_route_pack(t_lemin **lemin)
{
	int i = 1;
	sort_routes(lemin, i);
	(*lemin)->pack_routes = NULL;
	init_pack_routes(lemin);
	make_pack_routes(lemin);
	print_4(lemin);


}