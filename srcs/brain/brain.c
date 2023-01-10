#include "../../push_swap.h"

static void	sort_a(t_core *core, int needtobe)
{
	if (needtobe == 1)
		push_elem(2, core);
	else if (needtobe == 2)
	{
		push_elem(2, core);
		swap_elem(1, core);
	}
	else if (needtobe == core->p1->size)
	{
		push_elem(2, core);
		rotate_elem(1, core);
	}
	else if (needtobe == core->p1->size - 1)
	{
		reverse_rotate_elem(1, core);
		push_elem(2, core);
		rotate_elem(1, core);
		rotate_elem(1, core);
	}
}

static int	find_place(t_pile *p, int nn)
{
	t_cont *iterator;

	if (nn < p->first->nn)
		return (1);
	else if (nn > p->last->nn)
		return (p->size);
	iterator = p->first->next;
	while (iterator)
	{
		printf("value %d\n", iterator->nn);
		if (nn < iterator->nn && nn > iterator->prev->nn)
			return (iterator->index);
		iterator = iterator->next;
	}
	printf("Aucun resultat\n");
	return (0);
}

void	brain(t_core *core)
{
	int	nn;
	int i =0;
	int needtobe;
	while (core->p2->size > 1)
	{
		printf("------------%d------------\n", i);
		struct_test_re(core->p1);
		printf("\n");
		struct_test_re(core->p2);
		nn = core->p2->first->nn;
		needtobe = find_place(core->p1, nn);
		sort_a(core, needtobe);
		i++;
	}
}
