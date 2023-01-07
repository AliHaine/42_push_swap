#include "../../push_swap.h"

void	free_struct(t_core *core)
{
	t_cont *iterator = core->p1->first;
	t_cont *tofree;
	while (iterator)
	{
		if (iterator->next == NULL)
			break;
		tofree = iterator;
		iterator = iterator->next;
		free(tofree);
	}
	free(iterator);
}

void	init_struct_def_val(t_core *core)
{
	core->p1->first = NULL;
	core->p1->last = NULL;
	core->p2->first = NULL;
	core->p2->last = NULL;
	core->p1->size = 0;
	core->p2->size = 0;
}

void	update_index(struct s_pile *p, int i)
{
	t_cont *iterator;

	iterator = p->first;
	while (iterator)
	{
		iterator->index = iterator->index + i;
		iterator = iterator->next;
	}
}

bool	copy_cont(t_pile *copy, t_pile *paste, short mode)
{
	t_cont *cont;

	cont = malloc(sizeof(t_cont));
	if (!cont)
		return (false);
	cont->val = copy->first->val;
	cont->nn = copy->first->nn;

}

t_cont*	get_cont_from_index(struct s_pile *p, int index)
{
	t_cont *iterator;

	iterator = p->first;
	while (iterator)
	{
		if (iterator->index == index)
			return (iterator);
		iterator = iterator->next;
	}
	return (0);
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

void	struct_test(t_pile *p)
{
	t_cont *iterator = p->first;
	while (iterator)
	{
		printf("val = %d ", iterator->val);
		printf("index = %d\n", iterator->index);
		if (iterator->prev) {
			printf("prev val = %d ", iterator->prev->val);
			printf("prev index = %d\n", iterator->prev->index);
		}
		iterator = iterator->next;
	}
}