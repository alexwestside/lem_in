
#include "lem_in.h"

void *free_twodem_str(char **s)
{
	int i = 0;

	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

void free_pack_routes(t_pack_routes **pack_routes)
{
	t_pack_routes *prs;
	t_route *r;
	int i;

	prs = *pack_routes;
	while ((*pack_routes)->next)
	{
		i = -1;
		while (prs->next->next)
			prs = prs->next;
		if (prs->next->routes->route->room)
		{
			free(prs->next->routes);
			prs->next->routes = NULL;
//			prs->next->count_routes = 0;
			free(prs->next);
			prs->next = NULL;
		}
		else
		{
			free(prs->next->routes->route);
			free(prs->next->routes);
			free(prs->next);
			prs->next = NULL;
		}
		prs = *pack_routes;
	}
	prs = NULL;
	(*pack_routes)->routes = NULL;
	(*pack_routes)->routes = 0;
	free((*pack_routes));
	(*pack_routes) = NULL;
}

void free_route(t_route **route)
{
	t_route *r;

	r = *route;
	while ((*route)->next)
	{
		while (r->next->next)
			r = r->next;
		free(r->next->room);
		r->next->room = NULL;
		free(r->next);
		r->next = NULL;
		r = *route;
	}
	r = NULL;
	free((*route)->room);
	(*route)->room = NULL;
	free(*route);
}

void free_routes(t_routes **routes)
{
	t_routes *rs;
	t_route *r;

	rs = *routes;
	while ((*routes)->next)
	{
		while (rs->next->next)
			rs = rs->next;
		r = rs->next->route;
		free_route(&r);
		rs->next->route = NULL;
		rs->next->prev = NULL;
		free(rs->next);
		rs->next = NULL;
		rs = *routes;
	}
	rs = NULL;
	r = NULL;
	free_route(&(*routes)->route);
	(*routes)->route = NULL;
	free(*routes);
	*routes = NULL;
}

void free_connect(t_connect **connect)
{
	t_connect *c;

	c = *connect;
	if (c)
	{
		while ((*connect)->next)
		{
			while (c->next->next)
				c = c->next;
			c->next->room = NULL;
			free(c->next);
			c->next = NULL;
			c = *connect;
		}
		c = NULL;
		(*connect)->room = NULL;
		free(*connect);
	}
}

void free_room(t_room **room)
{
	t_room *r;

	r = *room;
	while ((*room)->next)
	{
		while (r->next->next)
			r = r->next;
		free_connect(&r->next->connect);
		free(r->next->name);
		r->next->name = NULL;
		free(r->next->x);
		r->next->x = NULL;
		free(r->next->y);
		r->next->y = NULL;
		r->next->connect = NULL;
		free(r->next);
		r->next = NULL;
		r = *room;
	}
	r = NULL;
	free((*room)->name);
	(*room)->name = NULL;
	free((*room)->x);
	(*room)->x = NULL;
	free((*room)->y);
	(*room)->y = NULL;
	free_connect(&(*room)->connect);
	(*room)->connect = NULL;
	free(*room);
}

void free_lemin(t_lemin **lemin)
{
	free_twodem_str((*lemin)->std_in);
	(*lemin)->std_in = NULL;
	free_twodem_str((*lemin)->queue);
	(*lemin)->queue = NULL;
	free_twodem_str((*lemin)->visit);
	(*lemin)->visit = NULL;
	free_pack_routes(&(*lemin)->pack_routes);
	free_routes(&(*lemin)->routes);
	free_room(&(*lemin)->room);
	(*lemin)->room = NULL;
}