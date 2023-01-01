//
// Created by Ali Yagmur on 1/2/23.
//

#ifndef PUSH_SWAP_H

typedef struct		s_pile
{
	struct s_pile	*next;
	int				val;
}					t_pile;

typedef struct		s_core
{
	struct s_pile	*p1;
	struct s_pile	*p2;
	struct s_pile	*last;
	struct s_pile	*first;
	struct s_pile	*pos;
}					t_core;

#define PUSH_SWAP_H

#endif
