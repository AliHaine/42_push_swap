#include "../../push_swap.h"

static void	sort_a(t_core *core, int needtobe)
{
	int save = needtobe;

	if (needtobe == 1)
		push_elem(2, core);
	else if (needtobe == 2)
	{
		push_elem(2, core);
		swap_elem(1, core);
	}
	else if (needtobe == core->p1->size + 1)
	{
		push_elem(2, core);
		rotate_elem(1, core);
	}
	else if (needtobe == core->p1->size)
	{
		reverse_rotate_elem(1, core);
		push_elem(2, core);
		rotate_elem(1, core);
		rotate_elem(1, core);
	}
	else
	{
		if (core->p1->size / 2 >= needtobe)
		{
			while (save > 1)
			{
				rotate_elem(1, core);
				save--;
			}
			push_elem(2, core);
			while (save != needtobe)
			{
				reverse_rotate_elem(1, core);
				save++;
			}
		}
		else
		{
			while (save != core->p1->size + 1)
			{
				reverse_rotate_elem(1, core);
				save++;
				if (save == 100)
					return;
			}
			push_elem(2, core);
			while (save != needtobe - 1)
			{
				rotate_elem(1, core);
				save--;
			}
		}
	}
}

static int	find_place(t_pile *p, int nn)
{
	t_cont *iterator;

	if (nn < p->first->nn)
		return (1);
	else if (nn > p->last->nn)
	{
		return (p->size + 1);
	}
	iterator = p->first->next;
	while (iterator)
	{
		if (nn < iterator->nn && nn > iterator->prev->nn)
		{
			return (iterator->index);
		}
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
	while (core->p2->size > 0)
	{
		nn = core->p2->first->nn;
		needtobe = find_place(core->p1, nn);
		sort_a(core, needtobe);
		i++;
	}
}
