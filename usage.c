
#include "lem_in.h"

void	ft_error(int id)
{
	if (id == 1 || id == 2)
	{
		id == 1 ? ft_printf("ERROR\n") : 0;
		id == 2 ? ft_printf("ERROR\n") : 0;
		exit(0);
	}
}

void	print_ants(int *ant, char *s, t_lemin **lemin, int id)
{
	char	*end;

	end = is_end(lemin);
	if (!id)
		ft_printf(RED"L%d-%s "END, *ant, s);
	if (s && id && ft_strcmp(end, s))
		ft_printf(GRN"L%d-%s "END, *ant, s);
	if (s && !ft_strcmp(end, s))
		ft_printf(BLU"L%d-%s "END, *ant, s);
}

void	*free_twodem_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

int		move_all_old(t_routes **routes, t_lemin **lemin)
{
	t_routes	*rs;
	t_route		*r;

	rs = (*routes);
	while (rs)
	{
		r = rs->route->next;
		while (r->next->room)
		{
			if (!r->move && r->ant)
				return (0);
			r = r->next;
		}
		rs = rs->next;
	}
	return (1);
}

void	move_all_null(t_routes **routes, t_lemin **lemin)
{
	t_routes	*rs;
	t_route		*r;

	rs = (*routes);
	while (rs)
	{
		r = rs->route->next;
		while (r->next->room)
		{
			if (r->move)
				r->move = 0;
			r = r->next;
		}
		rs = rs->next;
	}
}
