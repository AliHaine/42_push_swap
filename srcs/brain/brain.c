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

//Prepare le pile A a recevoir une value provenant de pile B
void set_toreceive_a(int spam, t_core *core, int place)
{
	if (place >= core->p1->size / 2)
		action_spammer("rra", spam, core);
	else
		action_spammer("ra", spam, core);
}

void	set_topush_b(int spam, int index, t_core *core) {
	if (index >= core->p2->size / 2)
	{
		action_spammer("rrb", spam, core);
	}
	else
		action_spammer("rb", spam, core);
}

//Repositionne correctement la pile A apres la reception de la valeur de la pile B
void	action_to_a(int spam, t_core *core, int place, int i)
{
	if (place >= core->p1->size / 2)
	{
		//push_elem(2, core);
		action_spammer("ra", spam + 1 + i, core);
	}
	else
	{
		//push_elem(2, core);
		action_spammer("rra", spam, core);
	}
}

void	set_to_last(t_core *core)
{
	push_elem(2, core);
	rotate_elem(1, core);
}

void	brain(t_core *core)
{
	t_cont *cont;
	int saveca;
	int i = 0;

	while (core->p2->size > 0) {
		//struct_test(core->p1);
		cont = get_cont_from_index(core->p2, get_total_cost(core));
		//printf("value = %d ", cont->val);
		set_topush_b(costb(cont->index, core->p2) - 1, cont->index, core);
		saveca = costa(cont, core->p1);
		int place = find_place(core->p1, core->p2->first->nn);
		//printf("ca = %d place = %d\n", saveca, place);
		if (saveca == 1)
			set_to_last(core);
		else
		{
			if (saveca > 0)
				set_toreceive_a(saveca / 2, core, place);
			push_elem(2, core);
			while (grep_worth_val(core) == true)
			{
				push_elem(2, core);
				i++;
			}
			action_to_a((saveca / 2), core, place, i);
			i = 0;
		}
	}
}
