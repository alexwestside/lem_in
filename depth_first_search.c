
#include "lem_in.h"


void make_route(t_routes **routes, char **visit)
{
	t_routes *rs;
	t_route *r;
	int i = 0;

	rs = (*routes);
	while (rs->next)
		rs = rs->next;
	rs->next = (t_routes *)malloc(sizeof(t_routes));
	rs->next->route = (t_route *)malloc(sizeof(t_route));
	rs->next->route->len_route = 0;
	rs->next->route->room = NULL;
	rs->next->route->next = NULL;
	r = rs->route;
	while (visit[i])
	{
		r->room = visit[i];
		r->next = (t_route *)malloc(sizeof(t_route));
		r->next->room = NULL;
		r->next->next = NULL;
		r = r->next;
		rs->route->len_route++;
		i++;
	}
}

int check_in_visit(char *room, char **visit)
{
	int i = 0;

	while (visit[i])
	{
		if (!ft_strcmp(room, visit[i]))
			return (1);
		i++;
	}
	return (0);
}

void write_in_visit(char *room, char **visit)
{
	int i = 0;

	while (visit[i])
		i++;
	visit[i] = room;
}

void fill_connect_in_queue(t_room *room, char **visit, char **queue)
{
	t_connect *connect;
	int i = 0;

	connect = room->connect;
	while (connect)
	{
		if (!check_in_visit(connect->room->name, visit))
		{
			write_in_visit(connect->room->name, visit);
			queue[i] = connect->room->name;
			return;
		}
		connect = connect->next;
	}
}

void check_fill_visit(char **visit, char *queue)
{
	int i = 0;

	while (visit[i])
	{
		if (visit[i] == queue)
			return;
		i++;
	}
	visit[i] = queue;
}

void dfs(t_lemin **lemin)
{
	int i = 0;
//	t_route route;
	t_room *room;

	if (check_visit_end(lemin, (*lemin)->queue[i]))
		return (make_route(&((*lemin)->routes), (*lemin)->visit));
//	while ((*lemin)->queue[i])
//	{
		room = (*lemin)->room;
		while (room->name)
		{
			if (!ft_strcmp((*lemin)->queue[i], room->name))
			{
//				(*lemin)->visit[i] = (*lemin)->queue[i];
				check_fill_visit((*lemin)->visit, (*lemin)->queue[i]);
				fill_connect_in_queue(room, (*lemin)->visit, (*lemin)->queue);
				dfs(lemin);
				write(1, "1", 10);

			}
			room = room->next;
		}
//		i++;
//	}

}