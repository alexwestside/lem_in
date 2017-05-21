
#include "lem_in.h"

void fill_count_routes(t_lemin **lemin)
{
	t_pack_routes *prs;
	t_routes *rs;

	prs = (*lemin)->pack_routes;
	while (prs)
	{
		rs = prs->routes;
		while (rs)
		{
			prs->count_routes++;
			rs = rs->next;
		}
		prs = prs->next;
	}
}

t_routes *routes_choice(t_lemin **lemin)
{
	t_routes *choice;
	t_routes *rs;
	t_pack_routes *prs;
	int moves;
	int tmp;

	choice = NULL;
	moves = 0;
	tmp = 0;
	prs = (*lemin)->pack_routes;
	while (prs)
	{
		rs = prs->routes;
		while (rs)
		{
			tmp += ((*lemin)->ants / prs->count_routes) * rs->len_route;
			rs = rs->next;
		}
		if (moves && tmp < moves)
		{
			moves = tmp;
			choice = prs->routes;
		}
		if (!moves)
		{
			moves = tmp;
			choice = prs->routes;
		}
		prs = prs->next;
	}
	return (choice);
}

void make_a_choice(t_lemin **lemin)
{
	t_routes *rs;

	fill_count_routes(lemin);
	rs = routes_choice(lemin);


}