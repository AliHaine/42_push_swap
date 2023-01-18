#include "../../push_swap.h"

/*static void	sort_a(t_core *core, int needtobe)
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
}*/

static int	find_place(t_pile *p, int nn)
{
	t_cont *iterator;

	if (nn < p->first->nn)
		return (1);
	else if (nn > p->last->nn)
		return (p->size + 1);
	iterator = p->first->next;
	while (iterator)
	{
		if (nn < iterator->nn && nn > iterator->prev->nn)
			return (iterator->index);
		iterator = iterator->next;
	}
	printf("Aucun resultat\n");
	return (0);
}

void set_toreceive_a(int spam, t_core *core, int place)
{
	if (place >= core->p1->size / 2)
	{
		action_spammer("rra", spam - 1, core);
	}
	else
		action_spammer("ra", spam - 1, core);
}

void	set_topush_b(int spam, int index, t_core *core) {
	if (index >= core->p2->size / 2)
		action_spammer("rrb", spam, core);
	else
		action_spammer("rb", spam, core);
}

void	action_to_a(int spam, t_core *core, int place)
{
	if (spam == 1)
	{
		push_elem(2, core);
		rotate_elem(1, core);
	}
	else if (place >= core->p1->size / 2)
	{
		push_elem(2, core);
		action_spammer("ra", spam, core);
	}
	else
	{
		push_elem(2, core);
		action_spammer("rra", spam - 1, core);
	}
}

void	brain(t_core *core)
{
	/*int	nn;
	int i = 0;
	int needtobe;*/
	t_cont *cont;
	int saveca;

	while (core->p2->size > 0) {
		struct_test(core->p1);
		cont = get_cont_from_index(core->p2, get_total_cost(core));
		printf("value = %d ", cont->val);
		set_topush_b(costb(cont->index, core->p2) - 1, cont->index, core);
		saveca = costa(cont, core->p1);
		int place = find_place(core->p1, core->p2->first->nn);
		printf("ca = %d place = %d\n", saveca, place);
		set_toreceive_a(saveca, core, place);
		//push_elem(2, core);
		action_to_a(saveca, core, place);
		//action_spammer("rra", saveca - 1, core);
		//printf("%d\n", core->p2->size);
	}

	/*while (core->p2->size > 0)
	{
		nn = core->p2->first->nn;
		needtobe = find_place(core->p1, nn);
		sort_a(core, needtobe);
		i++;
	}*/
}
