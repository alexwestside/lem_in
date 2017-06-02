
#ifndef LEM_IN_LEM_IN_H_H
# define LEM_IN_LEM_IN_H_H

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define END   "\x1B[0m"

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct				s_route
{
	char 					*room;
	int						ant;
	int 					move;
	struct s_route			*next;
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
	char					*x;
	char					*y;
	struct s_connect		*connect;
	int						start;
	int 					end;
	struct s_room			*next;
}							t_room;

typedef struct				s_lemin
{
	char					**std_in;
	char					**queue;
	char					**visit;
	int 					ants;
	struct s_room			*room;
	struct s_routes			*routes;
	struct s_pack_routes	*pack_routes;
	struct s_lemin 			*next;
}							t_lemin;

void						init_lemin(t_lemin **lemin, int ants, char *name, t_lemin *next);
void						init_room(t_room **room);
void						read_and_valid(t_lemin **lemin, char ***std_in);
char						**ft_realloc(char ***std_in, unsigned long int len);
unsigned long int			two_dem_strlen(char **s);
int							read_stdin(t_lemin **lemin, char *line, int fd, int *i);

int							count_ants(char *s);
int							type_num_ants(char *str);
int							type_room(char *str);
int							type_start_end(char *str);
int							type_connect(char *str);
int							type_comment(char *str);

int							valid_ants(t_lemin **lemin, int ants, char *line);
int							valid_start_end(t_lemin **lemin, char *line, int fd, int *i);
int							valid_connect(t_lemin **lemin, char *line, char **str, t_room *room);
//int							valid_room(t_lemin **lemin, char *line);
int		valid_room(t_lemin **lemin, char *line, char **str);
int							valid_room_name(t_lemin **lemin, char *s);

void						write_ants(t_lemin **lemin, char *line);
void						write_room(t_lemin **lemin, char *line, int start, int end);
void						write_connect(t_lemin **lemin, char *line, char **str);
void						write_connect_if(char **str, t_room **room, t_connect **connect);
void						write_check_start_end(t_lemin **lemin, char *line, int fd, int *i);
int							check_start_end(t_lemin **lemin, char *line);

void						need_data_check(t_lemin **lemin);
void						simple_data_check(t_lemin **lemin);
int							hard_data_check(t_lemin **lemin, int j, char **queue, char **visit);
void						hard_data_check_1(char **queue, t_connect **connect, t_room **room);
void						init_queue_visit(t_lemin **lemin, int len);
int							check_visit_end(t_lemin **lemin, char *s);
int							check_visit(char *name, char **visit);
void						rewrite_queue(char ***queue);
void						fill_queue(t_connect *connect, char ***queue);
void						find_start(t_lemin **lemin, char ***queue);

void						dfs(t_lemin **lemmin, t_room *next_room);
void						re_fill_visit(char **visit);
t_room						*find_next_room(t_lemin **lemin, char *room);
void						fill_visit(char **visit, char *room);
int							choose_link(char **visit, char *room);
void						make_route(char **visit, t_routes **routes);
void						make_route_other(t_routes **rs);

void						make_route_pack(t_lemin **lemin);
void						make_pack_routes(t_lemin **lemin);
int							check_cross1(t_routes **routes, t_route *route);
int							check_cross2(t_route *r1, t_route *r2);
void						add_route(t_routes **routes, t_routes *rs);
void						init_pack_routes(t_lemin **lemin);
void						init_pack_routes_if(t_lemin **lemin);
void						sort_routes(t_lemin **lemin, int i);
void						sort_routes_if(t_routes **tmp, t_routes **rs, int *i);

void						make_a_choice(t_lemin **lemin);
t_pack_routes				*routes_choice(t_lemin **lemin, int moves, int tmp);
void						routes_choice_if(int *moves, int *tmp, t_pack_routes **choice, t_pack_routes **prs);
void						fill_count_routes(t_lemin **lemin);

void						print_lemin(t_routes **routes, t_lemin **lemin, int ant);
void						print_stdin(t_lemin **lemin);
void						push_one_route(t_routes **routes, t_lemin **lemin, int flag, int ant);
void						push_old_ants(t_routes **routes, t_lemin **lemin);
void						end(t_route **room, t_lemin **lemin);
int							route_is_ampty(t_route *route);
int							routes_is_ampty(t_routes **routes);
void						move_old_ants(t_routes **routes, t_lemin **lemin);
void						move_old_ants_1(t_route **route, t_lemin **lemin);
void						move_new_ants(t_routes **routes, t_lemin **lemin, int *ant);
void						check_ant_in_end(t_route **route, t_lemin **lemin);
char						*is_end(t_lemin **lemin);
void						print_ants(int *ant, char *s, t_lemin **lemin, int id);
int							move_all_old(t_routes **routes, t_lemin **lemin);
void						move_all_null(t_routes **routes, t_lemin **lemin);
void						move_old_route(t_route **route, t_lemin **lemin);

int							if_is_alnum_str(char *s);
int							if_is_digit_str(char *s);
int							if_is_digit_sign_str(char *s);
int							atoi_lemin(char *str);
int							limit_int(long int n);
void						init_connect(t_connect **connect);
void						*free_twodem_str(char **s);
void						*free_visit_and_queue(char **visit, char **queue);
void						ft_error(int id);

void print_2(t_routes *routes);
void print_4(t_lemin **lemin);
void print_3(t_routes *routes);
void print_1(t_lemin *lemin);

#endif //LEM_IN_LEM_IN_H_H
