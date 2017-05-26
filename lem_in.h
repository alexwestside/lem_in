
#ifndef LEM_IN_LEM_IN_H_H
#define LEM_IN_LEM_IN_H_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#import "libft/ft_printf.h"

typedef struct				s_route
{
	char 					*room;
	int						ant;
//	int						len_route;
	struct s_route			*next;
	struct s_route			*prev;
}							t_route;

typedef struct				s_routes
{
	struct s_route			*route;
	int						len_route;
	struct s_routes			*next;
	struct s_routes			*prev;
}							t_routes;

typedef struct 				s_pack_routes
{
	struct s_routes			*routes;
	int						count_routes;
	struct s_pack_routes	*next;

}							t_pack_routes;

typedef struct				s_connect
{
	struct s_room			*room;
	struct s_connect 		*next;
}							t_connect;

typedef struct				s_room
{
	char					*name;
	int						*id_room;
	char					*x;
	char					*y;
	struct s_connect		*connect;
	int						start;
	int 					end;
	int						ants;
	struct s_room			*next;

}							t_room;

typedef struct				s_lemin
{
	char					**std_in;
	char					**queue;
	char					**visit;
	char					**route;
	int 					ants;

//	int						id_room;
	struct s_room			*room;
	struct s_routes			*routes;
	struct s_pack_routes	*pack_routes;

	struct s_lemin 			*next;
}							t_lemin;




void init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next);
void init_room(t_room **room);
void read_and_valid(t_lemin **lemin, char ***std_in);
char **ft_realloc(char ***std_in, unsigned long int len);
unsigned long int two_dem_strlen(char **s);
int read_stdin(t_lemin **lemin, char *line, int fd, int *i);


int if_is_digit_str(char *s);
int if_is_digit_sign_str(char *s);
int atoi_lemin(char *str);


int limit_int(long int n);
void init_connect(t_connect **connect);


int count_ants(char *s);


int type_num_ants(char *str);
int type_room(char *str);
int type_start_end(char *str);
int type_connect(char *str);
int type_comment(char *str);


int valid_ants(t_lemin **lemin, int ants, char *line);
int valid_start_end(t_lemin **lemin, char *line, int fd, int *i);
int if_is_alpha_str(char *s);
int if_is_alnum_str(char *s);
int valid_connect(t_lemin **lemin, char *line);
int valid_room(t_lemin **lemin, char *line);
int valid_room_name(t_lemin **lemin, char *s);


void write_ants(t_lemin **lemin, char *line);
void write_room(t_lemin **lemin, char *line, int start, int end);
void write_connect(t_lemin **lemin, char *line);
void write_check_start_end(t_lemin **lemin, char *line, int fd, int *i);
int check_start_end(t_lemin **lemin, char *line);


void need_data_check(t_lemin **lemin);
void simple_data_check(t_lemin **lemin);
int hard_data_check(t_lemin **lemin);
void init_queue_visit(t_lemin **lemin, int len);
int check_visit_end(t_lemin **lemin, char *s);
int check_visit(char *name, char **visit);
void rewrite_queue(char ***queue);
void fill_queue(t_connect *connect, char ***queue);
void find_start(t_lemin **lemin, char ***queue);


void free_visit_and_queue(char **visit, char **queue);


void dfs(t_lemin **lemmin, t_room *next_room);
void re_fill_visit(char **visit);
t_room *find_next_room(t_lemin **lemin, char *room);
void fill_visit(char **visit, char *room);
int choose_link(char **visit, char *room);
void make_route(char **visit, t_routes **routes);

void make_route_pack(t_lemin **lemin);

void make_a_choice(t_lemin **lemin);

void print_lemin(t_routes **routes, t_lemin **lemin, int ant);
void print_stdin(t_lemin **lemin);
void push_one_route(t_routes **routes, t_lemin **lemin);
void push_old_ants(t_routes **routes, t_lemin **lemin);
void end(t_route **room, t_lemin **lemin);
int route_is_ampty(t_route *route);
int routes_is_ampty(t_routes **routes);
void move_old_ants(t_routes **routes, t_lemin **lemin);
void move_new_ants(t_routes **routes, t_lemin **lemin, int *ant);
void check_ant_in_end(t_route **route, t_lemin **lemin);
char *is_end(t_lemin **lemin);

void ft_error(int id);

void print_1(t_lemin *lemin);
void print_2(t_routes *routes);
void print_3(t_routes *routes);
void print_4(t_lemin **lemin);





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
