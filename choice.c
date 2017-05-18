
#include "lem_in.h"

void sort_routes(t_lemin **lemin, int i)
{
	t_routes *routes;
	t_routes *tmp;

	while (i)
	{
		i = 0;
		routes = (*lemin)->routes;
		while (routes)
		{
			if (routes->next)
			{
				if (routes->len_route > routes->next->len_route)
				{
					tmp = routes->next;
					tmp->prev = routes->prev;
					tmp->next ? tmp->next->prev = routes: 0;
					routes->next = tmp->next;
					tmp->next = routes;
					routes->prev ? routes->prev->next = tmp : 0;
					routes->prev = tmp;
					routes = tmp;
					i = 1;
				}
				routes = routes->next;
			}
			else
				break;
		}
	}
	ft_printf("\n");
	print_1(*lemin);
}

void init_pack_routes(t_lemin **lemin)
{
	(*lemin)->pack_routes = (t_pack_routes *)malloc(sizeof(t_pack_routes));
	(*lemin)->pack_routes->next = NULL;
	(*lemin)->pack_routes->routes = (t_routes *)malloc(sizeof(t_routes));
	(*lemin)->pack_routes->routes->next = NULL;
	(*lemin)->pack_routes->routes->prev = NULL;
	(*lemin)->pack_routes->routes->len_route = -1;
	(*lemin)->pack_routes->routes->route = (t_route *)malloc(sizeof(t_route));
	(*lemin)->pack_routes->routes->route->next = NULL;
	(*lemin)->pack_routes->routes->route->room = NULL;
}

void make_route_pack(t_lemin **lemin)
{
	int i = 1;
	sort_routes(lemin, i);
	init_pack_routes(lemin);







}