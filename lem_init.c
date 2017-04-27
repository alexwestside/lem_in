
#include "lem_in.h"

void init_connect(t_connect **connect)
{
	(*connect) = (t_connect *)malloc(sizeof(t_connect));
	(*connect)->room =(t_room *)malloc(sizeof(t_room));
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

void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next)
{
	*lemin = (t_lemin *)malloc(sizeof(t_lemin));

	(*lemin)->std_in = (char **)malloc(sizeof(char *) * 2);
	(*lemin)->std_in[1] = NULL;
	(*lemin)->queue = NULL;
	(*lemin)->visit = NULL;

	(*lemin)->room = (t_room *)malloc(sizeof(t_room));
	init_room(&((*lemin)->room));
	(*lemin)->rout = (t_route* )malloc(sizeof(t_route));

	(*lemin)->ants = ants;
//	(*lemin)->name = name;
	(*lemin)->next = next;
}

void init_queue_visit(t_lemin **lemin, int len)
{
	int i ;

	i = -1;
	(*lemin)->queue = (char **)malloc(sizeof(char *) * len + 1);
	while (++i < len)
		(*lemin)->queue[i] = NULL;
	(*lemin)->queue[len] = NULL;
	i = -1;
	(*lemin)->visit = (char **)malloc(sizeof(char *) * len + 1);
	while (++i < len)
		(*lemin)->queue[i] = NULL;
	(*lemin)->visit[len] = NULL;
}
