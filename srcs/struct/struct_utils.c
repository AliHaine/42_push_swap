#include "../../push_swap.h"

void	init_struct_def_val(struct s_core *core)
{
	core->p1->cont->next = NULL;
	core->p2->cont->next = NULL;
	core->p1->first = NULL;
	core->p1->last = NULL;
}

int	pile_size(struct s_pile *p)
{
	int	size;
	t_cont *iterator;

	size = 0;
	iterator = p->first;
	while (iterator)
	{
		iterator = iterator->next;
		size++;
	}
	return (size);
}

bool	is_val_alr(int i, struct s_pile *p)
{
	t_cont *iterator;

	iterator = p->first;
	while (iterator)
	{
		if (iterator->val == i)
			return (true);
		iterator = iterator->next;
	}
	return (false);
}
