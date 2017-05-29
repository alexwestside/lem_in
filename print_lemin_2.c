
#include "lem_in.h"

void	check_ant_in_end(t_route **route, t_lemin **lemin)
{
	t_route	*r;
	char	*end;

	end = is_end(lemin);
	r = (*route);
	while (r->next)
	{
		if (!ft_strcmp(r->room, end))
		{
			r->ant = 0;
			return ;
		}
		r = r->next;
	}
}

int		routes_is_ampty(t_routes **routes)
{
	t_routes	*rs;
	t_route		*r;

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

int		route_is_ampty(t_route *route)
{
	t_route	*r;

	r = route;
	while (r->next->room)
	{
		if (r->ant)
			return (1);
		r = r->next;
	}
	return (0);
}

void	end(t_route **room, t_lemin **lemin)
{
	char	*end;

	if ((*room)->room)
	{
		end = is_end(lemin);
		if (!ft_strcmp((*room)->room, end))
			(*room)->ant = 0;
	}
	return ;
}

void	print_stdin(t_lemin **lemin)
{
	char	**str;

	str = (*lemin)->std_in;
	while (*str)
	{
		ft_printf("%s\n", *str);
		str++;
	}
	ft_printf("\n");
}
