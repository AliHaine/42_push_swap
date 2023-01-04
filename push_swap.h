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

typedef struct		s_pile
{
	int				val;
	int				index;
	int				need;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_core
{
	struct s_pile	*p1;
	struct s_pile	*p2;
	struct s_pile	*last;
	struct s_pile	*first;
}					t_core;

void	load_main(char **argv, struct s_core *core);
bool	is_digit(int c);

#endif
