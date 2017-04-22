
#ifndef LEM_IN_LEM_IN_H_H
#define LEM_IN_LEM_IN_H_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#import "libft/ft_printf.h"


//typedef struct	s_stdin
//{
//	char 		**std_in;
//	int 		start	: 1;
//	int 		end		: 1;
//	int 		ants	: 1;
//
//}				t_stdin;

typedef struct			s_connect
{
	struct s_room		*room;
	struct s_connect 	*next;
}						t_connect;

typedef struct			s_route
{


}						t_route;

typedef struct			s_room
{
	int					*id_room;
	char				*x;
	char				*y;
	struct s_connect	*connect;
	int					start;
	int 				end;
	int					ants;
	struct s_room		*next;

}						t_room;

typedef struct			s_lemin
{
//	char				*std_in;
	int 				ants;
	char				*name;
//	int					id_room;
	struct s_room		*room;
	struct s_route		*rout;
	struct s_lemin 		*next;
}						t_lemin;



int main();
void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next);
void init_room(t_room **room);
void read_and_valid(t_lemin **lemin, char ***std_in);
char **ft_realloc(char ***std_in, unsigned long int len);
unsigned long int two_dem_strlen(char **s);
void read_stdin(t_lemin **lemin, char *line);












//int main();
//void ft_read_write(t_stdin **input);
//char **ft_realloc(char ***std_in, unsigned long int len);
//unsigned long int ft_two_dem_strlen(char **s);
//void valid_sart_end(t_stdin **input);
//void ft_input_valid(t_stdin **input);
//void valid_sart_end(t_stdin **input);
//void valid_rooms(t_stdin **input);
//int valid_connect(char *s);
//int valid_ants(char *s);
//int ifisdigit_str(char **s);
//void valid_rooms_connect(t_stdin **input);
//
//void ft_input_valid(t_stdin **input, char *s);







void ft_error(int id);
















#endif //LEM_IN_LEM_IN_H_H
