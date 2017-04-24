
#ifndef LEM_IN_LEM_IN_H_H
#define LEM_IN_LEM_IN_H_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#import "libft/ft_printf.h"

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
	char				*name;
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
	char				**std_in;
	int 				ants;

//	int					id_room;
	struct s_room		*room;
	struct s_route		*rout;
	struct s_lemin 		*next;
}						t_lemin;




void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next);
void init_room(t_room **room);
void read_and_valid(t_lemin **lemin, char ***std_in);
char **ft_realloc(char ***std_in, unsigned long int len);
unsigned long int two_dem_strlen(char **s);
void read_stdin(t_lemin **lemin, char *line, int fd);


int if_is_digit_str(char *s);
int limit_int(long int n);
int count_ants(char *s);

int type_num_ants(char *str);
int type_room(char *str);
int type_start_end(char *str);
int type_connect(char *str);
int type_comment(char *str);



void valid_ants(t_lemin **lemin, int ants);
void valid_start_end(t_lemin **lemin);
int if_is_alpha_str(char *s);
int if_is_alnum_str(char *s);
void valid_connect(t_lemin **lemin, char *line);
void valid_room(t_lemin **lemin, char *line);


void ft_error(int id);










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


#endif //LEM_IN_LEM_IN_H_H
