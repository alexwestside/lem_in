
#include "lem_in.h"

//void make_route(t_routes **routes, char **visit)
//{
//	t_routes *rs;
//	t_route *r;
//	int i = 0;
//
//	if ((*routes))
//	{
//		rs = (*routes);
//		while (rs->next)
//			rs = rs->next;
//		rs->next = (t_routes *) malloc(sizeof(t_routes));
//		rs->next->next = NULL;
//		rs->next->len_route = -1;
//		rs->next->route = (t_route *) malloc(sizeof(t_route));
//		rs->next->route->room = NULL;
//		rs->next->route->next = NULL;
//		r = rs->route;
//		while (visit[i])
//		{
//			r->room = visit[i];
//			r->next = (t_route *) malloc(sizeof(t_route));
//			r->next->room = NULL;
//			r->next->next = NULL;
//			r = r->next;
//			rs->len_route++;
//			i++;
//		}
//	}
//	print_2((*routes));
//}
//
//int check_route(char **visit)
//{
//
//
//	return (1);
//}
//
//void dfs(t_lemin **lemin)
//{
//	t_room *room;
//
//	if (check_route((*lemin)->visit))
//	{
//		make_route(&((*lemin)->routes), (*lemin)->visit);
//		return;
//	}
//	room = (*lemin)->room;
//
//
//
//
//
//
//
//}

void make_route(t_routes **routes, char **visit)
{
	t_routes *rs;
	t_route *r;
	int i = 0;

	if ((*routes))
	{
		rs = (*routes);
		while (rs->next)
			rs = rs->next;
		rs->next = (t_routes *) malloc(sizeof(t_routes));
		rs->next->next = NULL;
		rs->next->len_route = -1;
		rs->next->route = (t_route *) malloc(sizeof(t_route));
		rs->next->route->room = NULL;
		rs->next->route->next = NULL;
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
	}
	print_2((*routes));
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

void write_in_visit(char *room, char **visit, char **queue)
{
	int i = 0;

	while (visit[i] != queue[0])
		i++;
	visit[i + 1] = room;
	i += 2;
	while (visit[i])
	{
		visit[i] = NULL;
		i++;
	}
//	while (visit[i])
//		i++;
//	visit[i] = room;
}

void refill_queue(char **queue, char **visit)
{
	int i = 0;

	if (queue[0])
	{
		while (ft_strcmp(visit[i], queue[0]))
			i++;
		queue[0] = visit[i - 1];
	}
	else
		return;
}

int check_rout(/*char *room, */char **visit, t_routes *routes)
{
	t_routes *rs;
	t_route *r;
	int i = 0;

	rs = routes;
	if (rs->route->room)
	{
		while (rs->route->room)
		{
			r = rs->route;
			if (r->room)
			{
				while (r->room)
				{
					if (!visit[i])
						return (0);
					if (!ft_strcmp(visit[i], r->room))
					{
						i++;
						r = r->next;
					}
					else
						break;
				}

				rs = rs->next;
			}
		}
	}
	return (1);
}

int fill_connect_in_queue(t_room *room, char **visit, char **queue, t_routes *routes)
{
	t_connect *connect;
	int i = 0;

	connect = room->connect;
	while (connect)
	{
		if (!check_in_visit(connect->room->name, visit))
		{
			write_in_visit(connect->room->name, visit, queue);
			if (check_rout(/*connect->room->name, */visit, routes))
			{
				queue[i] = connect->room->name;
				return (1);
			}
			else
				return (0);
		}
		connect = connect->next;
	}
	refill_queue(queue, visit);
	return (0);
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
	int j = 0;
//	t_route route;
	t_room *room;

	if (check_visit_end(lemin, (*lemin)->queue[i]) && check_rout((*lemin)->visit, (*lemin)->routes))
		return (make_route(&((*lemin)->routes), (*lemin)->visit));
	room = (*lemin)->room;
	while (room->name)
	{
		if ((*lemin)->queue[i])
		{
			if (!ft_strcmp((*lemin)->queue[i], room->name))
			{
				check_fill_visit((*lemin)->visit, (*lemin)->queue[i]);
				if (fill_connect_in_queue(room, (*lemin)->visit, (*lemin)->queue, (*lemin)->routes))
				{
					dfs(lemin);
					room = (*lemin)->room;
					refill_queue((*lemin)->queue, (*lemin)->visit);
					dfs(lemin);
				}
				else
					return;
			}
			room = room->next;
		}
		else
			return;
	}
}