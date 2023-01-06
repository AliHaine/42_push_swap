#include "../../push_swap.h"

bool	init_struct(int n, struct s_core *core)
{
	t_cont pile
	return (true);
}

bool create_new_cont(int n, struct s_core *core)
{
	t_cont *cont;

	cont = malloc(sizeof(*cont));
	if (cont == NULL)
		return (false);
	cont->next = NULL;
	if (core->p1->first == NULL)
		core->p1->first = cont;
	cont->val = n;
	cont->index = pile_size(core->p1);
}
