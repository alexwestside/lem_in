
#include "lem_in.h"

int atoi_lemin(char *str)
{
	int num;

	num = 0;
	*str == '-' ? str++ : 0;
	while (*str)
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (str[0] == '-' ? num * -1 : num);
}

int if_is_digit_sign_str(char *s)
{
	if (*s == '-' || *s == '+')
		if (!if_is_digit_str(s + 1))
			return (0);
	return (1);
}

int if_is_digit_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int if_is_alpha_str(char *s)
{
	char *p;

	p = s;
	while (*p)
	{
		if (!ft_isalpha(*s))
			return (0);
		p++;
	}
	return (1);
}

int if_is_alnum_str(char *s)
{
	char *p;

	p = s;
	if (!p)
		return (0);
	while (*p)
	{
		if (!ft_isalpha(*p) && !ft_isdigit(*p))
		{
			p = NULL;
			return (0);
		}
		p++;
	}
	p = NULL;
	return (1);
}


int limit_int(long int n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int count_ants(char *s)
{
	long int n;

	n = 0;
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (limit_int(n) ? 1 : 0);
}

int check_start_end(t_lemin **lemin, char *line)
{
	char **s;

	s = (*lemin)->std_in;
	while (ft_strcmp(*s, line))
		s++;
	s--;
	if (!ft_strcmp(*s, "##start") || !ft_strcmp(*s, "##end"))
		return (1);
	return (0);
}

void free_visit_and_queue(char **visit, char **queue)
{
	while (*visit)
	{
		*visit = NULL;
		visit++;
	}
	while (*queue)
	{
		*queue = NULL;
		queue++;
	}
}

void print_1(t_lemin *lemin)
{
	t_routes *rs;
	t_route *r;
	int route = 1;

	rs = lemin->routes;
	while (rs)
	{
		ft_printf("Route #%d, Len = %d, Links: ", route, rs->len_route);
		route++;
		r = rs->route;
		while (r->room)
		{
			ft_printf("%s", r->room);
			if (ft_strcmp(r->room, "f"))
				ft_printf(" - ");
			r = r->next;
		}
		ft_printf("\n");
		rs = rs->next;
	}
}

void print_2(t_routes *routes)
{
	t_routes *rs;
	t_route *r;

	rs = routes;
	while (rs->next->route->room)
		rs = rs->next;
	r = rs->route;
	while (r->room)
	{
		ft_printf("%s - ", r->room);
		r = r->next;
	}
	ft_printf("\n");
}

void print_3(t_routes *routes)
{
	t_route *r;

	r = routes->route;
	while (r->next)
	{
		ft_printf("%s - ", r->room);
		r = r->next;
	}
	ft_printf("\n");
}

void print_4(t_lemin **lemin)
{
	t_pack_routes *prs;
	t_routes *rs;
	t_route *r;

	ft_printf("\n\n");
	prs = (*lemin)->pack_routes;
	while (prs)
	{
		rs = prs->routes;
		while (rs)
		{
			r = rs->route;
			while (r->next)
			{
				ft_printf("%s - ", r->room);
				r = r->next;
			}
			rs = rs->next;
			ft_printf("\n");
		}
		prs = prs->next;
		ft_printf("\n");
	}
}