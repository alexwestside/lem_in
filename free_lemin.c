
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

void free_pack_routes(t_pack_routes **pack_routes)
{
//	free(*pack_routes);
}

void free_route2(t_route **route)
{
	t_route *r;

	r = *route;
	while ((*route)->next)
	{
 		while (r->next->room)
			r = r->next;
		free(r->next);
		r->next = NULL;
		r->room = NULL;
		r = *route;
	}
//	free(*route);
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
		free_route2(&r);
		free(r);
		rs->next->prev = NULL;
		free(rs->next);
		rs->next = NULL;
		rs = *routes;
	}
	r = rs->route;
	free_route2(&r);
	free(rs->route);
	rs->route = NULL;
	free(*routes);
}


void free_connect(t_connect **connect)
{
	t_connect *c;

	c = *connect;
	while (c)
	{
		free(c->room->name);
		c = c->next;
	}
}

void free_room(t_room **room)
{
	t_room *r;

	r = *room;
	while (r)
	{
		free(r->name);
		free(r->x);
		free(r->y);
		free_connect(&(r->connect));
		r = r->next;
	}
//	free((*room));
}

void free_route(char **route)
{
	free_twodem_str(route);
}

void free_visit(char **visit)
{
	free_twodem_str(visit);
}

void free_queue(char **queue)
{
	free_twodem_str(queue);
}

void free_stdin(char **str)
{
	free_twodem_str(str);
}

void free_lemin(t_lemin **lemin)
{
	free_stdin((*lemin)->std_in);
	free_queue((*lemin)->queue);
	free_visit((*lemin)->visit);
	free_route((*lemin)->route);
	free_room(&(*lemin)->room);
	free_routes(&(*lemin)->routes);
	free_pack_routes(&(*lemin)->pack_routes);
}