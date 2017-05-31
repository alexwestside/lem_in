
#include "lem_in.h"

void	sort_routes_if(t_routes **tmp, t_routes **rs, int *i)
{
	*tmp = (*rs)->next;
	(*tmp)->prev = (*rs)->prev;
	(*tmp)->next ? (*tmp)->next->prev = *rs : 0;
	(*rs)->next = (*tmp)->next;
	(*tmp)->next = (*rs);
	(*rs)->prev ? (*rs)->prev->next = *tmp : 0;
	(*rs)->prev ? (*rs)->prev = *tmp : 0;
	*rs = *tmp;
	*i = 1;
}

void	sort_routes(t_lemin **lemin, int i)
{
	t_routes	*rs;
	t_routes	*tmp;

	while (i)
	{
		i = 0;
		rs = (*lemin)->routes;
		while (rs)
		{
			if (rs->next)
			{
				if (rs->len_route > rs->next->len_route)
					sort_routes_if(&tmp, &rs, &i);
				rs = rs->next;
			}
			else
				break ;
		}
	}
	tmp->next = NULL;
	free(tmp->route);
	free(tmp);
}

int		check_cross2(t_route *r1, t_route *r2)
{
	t_route	*r2_;
	int		i;

	i = 0;
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

int		check_cross1(t_routes **routes, t_route *route)
{
	t_routes	*rs;
	t_route		*r1;
	t_route		*r2;

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

void	make_pack_routes(t_lemin **lemin)
{
	t_routes		*routes;
	t_routes		*rs;
	t_pack_routes	*pack_routes;

	routes = (*lemin)->routes;
	pack_routes = (*lemin)->pack_routes;
	while (routes)
	{
		free(pack_routes->routes->route);
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
		pack_routes = pack_routes->next;
	}
}
