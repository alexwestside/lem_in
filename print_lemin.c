
//ft_printf("L%d-%s ", ant, r->room);

#include "lem_in.h"

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
	char *end;

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
			r->next->ant = r->ant;
			r->ant = 0;
			ft_printf("L%d-%s ", r->next->ant, r->next->room);
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

void push_one_route(t_routes **routes, t_lemin **lemin)
{
	t_routes *rs;
	t_route *r;
	int ant;
	int flag;

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
				break;
			r = r->next;
		}
		if (r->ant == ant)
			flag = 1;
		r->next->ant = r->ant;
		r->ant = 0;
		ft_printf("L%d-%s ", r->next->ant, r->next->room);
		end(&(r->next), lemin);
		r = rs->route;
		if (flag == 1)
			ft_printf("\n");
	}
}

void print_stdin(t_lemin **lemin)
{
	char **str;

	str = (*lemin)->std_in;
	while (*str)
	{
		ft_printf("%s\n", *str);
		str++;
	}
	ft_printf("\n");
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
	(*routes)->next ? push_old_ants(routes, lemin) : push_one_route(routes, lemin);
}