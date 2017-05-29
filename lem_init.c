
#include "lem_in.h"

void init_connect(t_connect **connect)
{
	(*connect) = (t_connect *)malloc(sizeof(t_connect));
//	(*connect)->room =(t_room *)malloc(sizeof(t_room));
	init_room(&((*connect)->room));
	(*connect)->next = NULL;
}

void init_room(t_room **room)
{
	*room = (t_room *)malloc(sizeof(t_room));
	(*room)->id_room = 0;
	(*room)->name = NULL;
	(*room)->x = 0;
	(*room)->y = 0;
	(*room)->connect = NULL;
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->ants = 0;
	(*room)->next = NULL;
}

void init_routes(t_routes **routes)
{
	*routes = (t_routes *)malloc(sizeof(t_routes));
	(*routes)->len_route = -1;
	(*routes)->next = NULL;
	(*routes)->prev = NULL;
	(*routes)->route = (t_route *)malloc(sizeof(t_route));
	(*routes)->route->room = NULL;
	(*routes)->route->ant = 0;
	(*routes)->route->next = NULL;
}

void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next)
{
	*lemin = (t_lemin *)malloc(sizeof(t_lemin));

	(*lemin)->std_in = (char **)malloc(sizeof(char *) * 2);
	(*lemin)->std_in[1] = NULL;
	(*lemin)->queue = NULL;
	(*lemin)->visit = NULL;

//	(*lemin)->room = (t_room *)malloc(sizeof(t_room));
	init_room(&((*lemin)->room));
	init_routes(&((*lemin)->routes));
//	(*lemin)->routes = (t_routes* )malloc(sizeof(t_routes));

	(*lemin)->ants = ants;
//	(*lemin)->name = name;
	(*lemin)->next = next;
//	free(name);
}

void init_queue_visit(t_lemin **lemin, int len)
{
	int i ;

	i = -1;
	(*lemin)->queue = (char **)malloc(sizeof(char *) * (len * len));
	while (++i < len)
		(*lemin)->queue[i] = NULL;
	(*lemin)->queue[len] = NULL;
	i = -1;
	(*lemin)->visit = (char **)malloc(sizeof(char *) * (len + 1));
	while (++i < len)
		(*lemin)->visit[i] = NULL;
	(*lemin)->visit[len] = NULL;
//	(*lemin)->route = (char **)malloc(sizeof(char *) * (len + 1));
//	while (++i < len)
//		(*lemin)->route[i] = NULL;
//	(*lemin)->route[len] = NULL;
}
