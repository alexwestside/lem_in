
#include "lem_in.h"

void			fill_count_routes(t_lemin **lemin)
{
	t_pack_routes	*prs;
	t_routes		*rs;

	prs = (*lemin)->pack_routes;
	while (prs)
	{
		if (prs->routes->route->room)
		{
			rs = prs->routes;
			while (rs)
			{
				prs->count_routes++;
				rs = rs->next;
			}
		}
		prs = prs->next;
	}
}

void routes_choice_if(int *moves, int *tmp, t_pack_routes **choice, t_pack_routes **prs)
{
	if (*moves && *tmp < *moves)
	{
		*moves = *tmp;
		*choice = *prs;
	}
	if (!(*moves))
	{
		*moves = *tmp;
		*choice = *prs;
	}
}

t_pack_routes	*routes_choice(t_lemin **lemin)
{
	t_pack_routes	*choice;
	t_routes		*rs;
	t_pack_routes	*prs;
	int				moves;
	int				tmp;

	choice = NULL;
	moves = 0;
	tmp = 0;
	prs = (*lemin)->pack_routes;
	while (prs)
	{
		if (prs->routes->route->room)
		{
			rs = prs->routes;
			while (rs)
			{
				tmp += ((*lemin)->ants / prs->count_routes) * rs->len_route;
				rs = rs->next;
			}
			routes_choice_if(&moves, &tmp, &choice, &prs);
//			if (moves && tmp < moves)
//			{
//				moves = tmp;
//				choice = prs;
//			}
//			if (!moves)
//			{
//				moves = tmp;
//				choice = prs;
//			}
		}
		prs = prs->next;
	}
	return (choice);
}

void			make_a_choice(t_lemin **lemin)
{
	t_pack_routes	*choice;

	fill_count_routes(lemin);
	choice = routes_choice(lemin);
	print_lemin(&(choice->routes), lemin, 1);
}
