
//ft_printf("L%d-%s ", ant, r->room);

#include "lem_in.h"

int full_route(t_routes *routes)
{
	t_routes *rs;
	t_route *r;

	rs = routes;
	while (rs)
	{
		r = rs->route->next;
		while (rs->len_route--)
		{
			if (r->ant)
				r = r->next;
		}
		if (!r->next->room)
			return (0);
		rs = rs->next;
	}
	return (1);
}

int no_move(t_routes *routes, int len)
{
	t_routes *rs;
	t_route *r;

	rs = routes;
	while (rs)
	{
		r = rs->route->next;
		while (r->room)
		{
			if ((!r->ant && r->next->ant))
				return (0);
			if (!r->ant && !r->next->ant)
				return (0);
			if (r->ant)
				break;
			r = r->next;
		}
		rs = rs->next;
	}
	return (1);
}

char *is_start(t_lemin **lemin)
{
	t_room *room;

	room = (*lemin)->room;
	while (room)
	{
		if (room->start)
			break;
		room = room->next;
	}
	return (room->name);
}

char *is_end(t_lemin **lemin)
{
	t_room *room;

	room = (*lemin)->room;
	while (room)
	{
		if (room->end)
			break;
		room = room->next;
	}
	return (room->name);
}

void check_ant_in_end(t_route **route, t_lemin **lemin)
{
	t_route *r;
//	char *start;
	char *end;

//	start = is_start(lemin);
	end = is_end(lemin);
	r = (*route);
	while (r->next)
	{
		if (!ft_strcmp(r->room, end))
		{
			r->ant = 0;
			return;
		}
		r = r->next;
	}
}

void move_ant(t_route **route, t_lemin **lemin)
{
	t_route *r;

	r = (*route);
	while (r->next->ant)
		r = r->next;
	r->next->ant = r->ant;
	r->ant = 0;
	ft_printf("L%d-%s ", r->next->ant, r->next->room);
	check_ant_in_end(route, lemin);
}

//void print_lemin(t_pack_routes *pack_routes, int count_routes, int ant, t_lemin **lemin)
//{
//	t_routes *rs;
//	t_route *r;
//
//	rs = pack_routes->routes;
//	while (rs && ant <= (*lemin)->ants)
//	{
//		r = rs->route->next;
//		if (!r->ant)
//		{
//			r->ant = ant;
//			ft_printf("L%d-%s ", ant, r->room);
//			ant++;
//		}
//		else
//			move_ant(&r, lemin);
//		rs = rs->next;
//		if (!rs)
//		{
//			rs = pack_routes->routes;
//			if (no_move(pack_routes->routes, pack_routes->count_routes))
//				ft_printf("\n");
//		}
//	}
//
//}


//void move_ant_new(t_pack_routes **pack_routes, t_lemin **lemin, int *ant)
//{
//	t_routes *rs;
//	t_route *r;
//
//	rs = (*pack_routes)->routes;
//	if (*ant <= (*lemin)->ants)
//	{
//		while (rs)
//		{
//			r = rs->route->next;
//			if (!r->ant)
//			{
//				r->ant = *ant;
//				ft_printf("L%d-%s ", *ant, r->room);
//				(*ant)++;
//			}
//			rs = rs->next;
//		}
//		ft_printf("\n");
//	}
//	return;
//}
//
//void move_ant_old(t_pack_routes **pack_routes, t_lemin **lemin)
//{
//	t_routes *rs;
//	t_route *r;
//
//	rs = (*pack_routes)->routes;
//	while (rs)
//	{
//		r = rs->route->next;
////		while (r->next->ant)
////			r = r->next;
//		if (r->ant)
//		{
//			while (r->next->ant)
//				r = r->next;
//			r->next->room ? r->next->ant = r->ant : 0;
//			r->ant = 0;
//			r->next->room ? ft_printf("L%d-%s ", r->next->ant, r->next->room) : 0;
//			check_ant_in_end(&(*pack_routes)->routes->route, lemin);
//			rs = rs->next;
//			if (!rs)
//				rs = (*pack_routes)->routes;
//		}
//		else
//			break;
//	}
//}
//
//int if_ampty(t_pack_routes *pack_routes)
//{
//	t_routes *rs;
//	t_route *r;
//
//	rs = pack_routes->routes;
//	while (rs)
//	{
//		r = rs->route->next;
//		while (r->room)
//		{
//			if (!r->ant)
//				r = r->next;
//			else
//				return (0);
//		}
//		rs = rs->next;
//	}
//	return (1);
//}

//void print_lemin(t_pack_routes *pack_routes, int count_routes, int ant, t_lemin **lemin)
//{
//	move_ant_new(&pack_routes, lemin, &ant);
//	move_ant_old(&pack_routes, lemin);
//	while (!if_ampty(pack_routes))
//	{
//		move_ant_new(&pack_routes, lemin, &ant);
//		move_ant_old(&pack_routes, lemin);
//	}
//}

void move_new_ants(t_routes **routes, t_lemin **lemin, int *ant)
{
	t_routes *rs;
	t_route *r;

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

void move_old_ants(t_routes **routes, t_lemin **lemin)
{
	t_routes *rs;
	t_route *r;

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
			break;
	}
}


int routes_is_ampty(t_routes **routes)
{
	t_routes *rs;
	t_route *r;

	rs = (*routes);
	while (rs)
	{
		r = rs->route;
		while (r->next->room)
		{
			if (r->ant)
				return (1);
			r = r->next;
		}
		rs = rs->next;
	}
	return (0);
}

int route_is_ampty(t_route *route)
{
	t_route *r;

	r = route;
	while (r->next->room)
	{
		if (r->ant)
			return (1);
		r = r->next;
	}
	return (0);
}

void end(t_route **room, t_lemin **lemin)
{
	char *end;

	if ((*room)->room)
	{
		end = is_end(lemin);
		if (!ft_strcmp((*room)->room, end))
			(*room)->ant = 0;
	}
	return;
}

void push_old_ants(t_routes **routes, t_lemin **lemin)
{
	t_routes *rs;
	t_route *r;

	rs = (*routes);
	while (routes_is_ampty(routes))
	{
		r = rs->route->next;
		if (route_is_ampty(r))
		{
			while (r->next->room)
			{
				if (r->ant && !r->next->ant)
					break;
				r = r->next;
			}
//			while (r->next->ant)
//				r = r->next;
//			if (r->next->ant)
			r->next->ant = r->ant;
			r->ant = 0;
			ft_printf("L%d-%s ", r->next->ant, r->next->room);
//			check_ant_in_end(&(*routes)->route, lemin);
			end(&(r->next), lemin);
		}
		rs = rs->next;
		if (!rs)
		{
			rs = (*routes);
			ft_printf("\n");
		}
	}
}

void print_stdin(t_lemin **lemin)
{




}

void print_lemin(t_routes **routes, t_lemin **lemin, int ant)
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
//	while (routes_is_ampty(routes))
	push_old_ants(routes, lemin);
}