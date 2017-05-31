
#include "lem_in.h"

void	ft_error(int id)
{
	if (id == 1 || id == 2)
	{
		id == 1 ? ft_printf("EMPTY stream INPUT!!!\n") : 0;
		id == 2 ? ft_printf("NOT a VALID input!!!\n") : 0;
		exit(0);
	}
}

void	print_ants(int *ant, char *s, t_lemin **lemin, int id)
{
	char	*end;

	end = is_end(lemin);
	if (!id)
		ft_printf(RED"L%d-%s "END, *ant, s);
	if (!ft_strcmp(end, s))
		ft_printf(BLU"L%d-%s "END, *ant, s);
	else
		ft_printf(GRN"L%d-%s "END, *ant, s);
}

void	*free_twodem_str(char **s)
{
	int	i = 0;

	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}
