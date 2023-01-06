//
// Created by Ali Yagmur on 1/2/23.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct		s_cont
{
	int				val;
	int				index;
	int				nn;
	struct s_cont	*next;
}					t_cont;

typedef struct		s_pile
{
	struct s_cont	*cont;
	struct s_cont	*last;
	struct s_cont	*first;
}					t_pile;

typedef struct		s_core
{
	struct s_pile	*p1;
	struct s_pile	*p2;
}					t_core;

void	load_main(char **argv, struct s_core *core);
int		ft_atoi(char *s);
bool	is_digit(char c);
bool	is_number(char *s);
int		get_number(char *s);
void	init_struct_def_val(struct s_core *core);
int		pile_size(struct s_pile *p);
bool	is_val_alr(int i, struct s_pile *p);

#endif
