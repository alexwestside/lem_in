
#ifndef LEM_IN_LEM_IN_H_H
#define LEM_IN_LEM_IN_H_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#import "libft/ft_printf.h"


typedef struct	s_stdin
{
	char **std_in;

}				t_stdin;

int main();
void ft_read_write(t_stdin **input);
char **ft_realloc(char ***std_in, unsigned long int len);
unsigned long int ft_two_dem_strlen(char **s);
void ft_input_valid(char **str);
















#endif //LEM_IN_LEM_IN_H_H
