
#include "lem_in.h"

void	init_pack_routes_if(t_lemin **lemin)
{
	(*lemin)->pack_routes = (t_pack_routes *)malloc(sizeof(t_pack_routes));
	(*lemin)->pack_routes->count_routes = 0;
	(*lemin)->pack_routes->next = NULL;
	(*lemin)->pack_routes->routes = (t_routes *)malloc(sizeof(t_routes));
	(*lemin)->pack_routes->routes->next = NULL;
	(*lemin)->pack_routes->routes->prev = NULL;
	(*lemin)->pack_routes->routes->len_route = -1;
	(*lemin)->pack_routes->routes->route = (t_route *)malloc(sizeof(t_route));
	(*lemin)->pack_routes->routes->route->next = NULL;
	(*lemin)->pack_routes->routes->route->room = NULL;
}

void	init_pack_routes(t_lemin **lemin)
{
	t_pack_routes	*pack_routes;

	pack_routes = (*lemin)->pack_routes;
	if (!pack_routes)
		init_pack_routes_if(lemin);
	else
	{
		while (pack_routes->next)
			pack_routes = pack_routes->next;
		pack_routes->next = (t_pack_routes *)malloc(sizeof(t_pack_routes));
		pack_routes->next->count_routes = 0;
		pack_routes->next->next = NULL;
		pack_routes->next->routes = (t_routes *)malloc(sizeof(t_routes));
		pack_routes->next->routes->next = NULL;
		pack_routes->next->routes->prev = NULL;
		pack_routes->next->routes->len_route = -1;
		pack_routes->next->routes->route = (t_route *)malloc(sizeof(t_route));
		pack_routes->next->routes->route->next = NULL;
		pack_routes->next->routes->route->room = NULL;
	}
}

void	add_route(t_routes **routes, t_routes *rs)
{
	t_routes	*prs;

	prs = (*routes);
	while (prs->next)
		prs = prs->next;
	prs->next = (t_routes *)malloc(sizeof(t_routes));
	prs->next->next = NULL;
	prs->next->prev = prs;
	prs->next->len_route = 0;
	prs->next->route = rs->route;
	prs->next->len_route = rs->len_route;
}

void	make_route_other(t_routes **rs)
{
	(*rs)->next = (t_routes *)malloc(sizeof(t_routes));
	(*rs)->next->route = NULL;
	(*rs)->next->len_route = -1;
	(*rs)->next->next = NULL;
	(*rs)->next->prev = *rs;
	(*rs)->next->route = (t_route *)malloc(sizeof(t_route));
	(*rs)->next->route->room = NULL;
	(*rs)->next->route->room = 0;
	(*rs)->next->route->next = NULL;
}

void	make_route(char **visit, t_routes **routes)
{
	t_routes	*rs;
	t_route		*r;
	int			i;

	i = 0;
	rs = (*routes);
	while (rs->next)
		rs = rs->next;
	r = rs->route;
	while (visit[i])
	{
		r->room = ft_strdup(visit[i]);
		r->next = (t_route *)malloc(sizeof(t_route));
		r->next->room = NULL;
		r->next->ant = 0;
		r->next->move = 0;
		r->next->next = NULL;
		r = r->next;
		rs->len_route++;
		i++;
	}
	make_route_other(&rs);
}
