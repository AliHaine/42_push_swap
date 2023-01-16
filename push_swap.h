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

#define error_alr_nbr "Ce nombre est déjà défini"
#define error_not_nbr "Seul les nombres sont acceptes"

typedef struct		s_cont
{
	int				val;
	int				index;
	int				nn;
	struct s_cont	*next;
	struct s_cont	*prev;
}					t_cont;

typedef struct		s_pile
{
	struct s_cont	*cont;
	struct s_cont	*last;
	struct s_cont	*first;
	int 			size;
}					t_pile;

typedef struct		s_core
{
	struct s_pile	*p1;
	struct s_pile	*p2;
}					t_core;

void	load_main(char **argv, struct s_core *core);
void	sort_base_pile(t_core *core);
bool	is_str_contains(char *src, char *val);
void	action_writter(char *ac);
void	error_manager(char *msg, t_core *core);
int		ft_atoi(char *s);
bool	is_digit(char c);
bool	is_number(char *s);
int		get_number(char *s);
void	init_struct_def_val(t_core *core);
void	update_index(struct s_pile *p, int i);
void	free_struct(t_core *core);
t_cont*	get_cont_from_index(struct s_pile *p, int index);
void	reverse_rotate_elem(short mode, t_core *core);
void	rotate_elem(short mode, t_core *core);
void	push_elem(short mode, t_core *core);
void	swap_elem(short mode, t_core *core);
bool	create_new_cont(int n, struct s_pile *p);
bool	is_val_alr(int i, struct s_pile *p);
void	action_spammer(char *str, int count, t_core *core);
void	struct_test(t_pile *p);
void	struct_test_re(t_pile *p);
void	brain(t_core *core);
void	set_nn_to_tab(int *nn, t_core *core);
int		get_worth(t_core *core);

#endif
