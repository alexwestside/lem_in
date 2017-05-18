
#include "lem_in.h"

void make_route(char **visit, t_routes **routes)
{
	t_routes *rs;
	t_route *r;
	int i = 0;

	rs = (*routes);
	while (rs->next)
		rs = rs->next;
	r = rs->route;
	while (visit[i])
	{
		r->room = visit[i];
		r->next = (t_route *) malloc(sizeof(t_route));
		r->next->room = NULL;
		r->next->next = NULL;
		r = r->next;
		rs->len_route++;
		i++;
	}
	rs->next = (t_routes *)malloc(sizeof(t_routes));
	rs->next->route = NULL;
	rs->next->len_route = -1;
	rs->next->next = NULL;
	rs->next->prev = rs;
	rs->next->route = (t_route *)malloc(sizeof(t_route));
	rs->next->route->room = NULL;
	rs->next->route->next = NULL;
}

int choose_link(char **visit, char *room)
{
	int i = 0;
	while (visit[i])
	{
		if (!ft_strcmp(visit[i], room))
			return (0);
		i++;
	}
	return (1);
}

void fill_visit(char **visit, char *room)
{
	int i = 0;
	while (visit[i])
		i++;
	visit[i] = room;
}

t_room *find_next_room(t_lemin **lemin, char *room)
{
	t_room *next_room;

	next_room = (*lemin)->room;
	while (next_room->name)
	{
		if (!ft_strcmp(next_room->name, room) && choose_link((*lemin)->visit, room))
			break;
		next_room = next_room->next;
	}
	return (next_room);
}

void re_fill_visit(char **visit)
{
	int i = 0;
	while (visit[i])
		i++;
	visit[i - 1] = NULL;
}

void dfs(t_lemin **lemmin, t_room *next_room)
{
	t_connect *connect;

	fill_visit((*lemmin)->visit, next_room->name);
	if (next_room->end)
	{
		make_route((*lemmin)->visit, &((*lemmin)->routes));
		re_fill_visit((*lemmin)->visit);
		return;
	}
	connect = next_room->connect;
	while (connect)
	{
		if (choose_link((*lemmin)->visit, connect->room->name))
			dfs(lemmin, find_next_room(lemmin, connect->room->name));
		connect = connect->next;
	}
	re_fill_visit((*lemmin)->visit);
}
