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

void	action_spammer(char *str, int count, t_core *core)
{
	while (count > 0)
	{
		if (is_str_contains(str, "pa"))
			push_elem(2, core);
		else if (is_str_contains(str, "pb"))
			push_elem(1, core);
		else if (is_str_contains(str, "ra"))
			rotate_elem(1, core);
		else if (is_str_contains(str, "rb"))
			rotate_elem(2, core);
		else if (is_str_contains(str, "rr"))
			rotate_elem(3, core);
		else if (is_str_contains(str, "rra"))
			reverse_rotate_elem(1, core);
		else if (is_str_contains(str, "rrb"))
			reverse_rotate_elem(2, core);
		else if (is_str_contains(str, "rrr"))
			reverse_rotate_elem(3, core);
		else if (is_str_contains(str, "sa"))
			swap_elem(1, core);
		else if (is_str_contains(str, "sb"))
			swap_elem(2, core);
		count--;
	}
}

void	struct_test(t_pile *p)
{
	t_cont *iterator = p->first;
	if (p->first)
		printf("first = %d ", p->first->val);
	if (p->last)
		printf("last = %d\n", p->last->val);
	while (iterator)
	{
		printf("val = %d ", iterator->val);
		printf("index = %d ", iterator->index);
		printf("nn = %d\n", iterator->nn);
		iterator = iterator->next;
	}
}

void	struct_test_re(t_pile *p)
{
	t_cont *iterator = p->last;
	if (p->last)
		printf("first = %d ", p->first->val);
	if (p->first)
		printf("last = %d\n", p->last->val);
	while (iterator)
	{
		printf("val = %d ", iterator->val);
		printf("index = %d ", iterator->index);
		printf("nn = %d\n", iterator->nn);
		iterator = iterator->prev;
	}
}