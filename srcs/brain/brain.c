#include "../../push_swap.h"

static int	find_place_tolowes(t_pile *p)
{
	int minv;
	t_cont *iterator;

	iterator = p->first;
	minv = iterator->nn;
	while(iterator)
	{
		if (minv > iterator->nn)
			minv = iterator->nn;
		iterator = iterator->next;
	}
	iterator = p->first;
	while (iterator)
	{
		if (iterator->nn == minv)
			return ((iterator->index));
		iterator = iterator->next;
	}
	return (0);
}

static int	find_place_tobigger(t_pile *p)
{
	int max;
	t_cont *iterator;

	iterator = p->first;
	max = iterator->nn;
	while(iterator)
	{
		if (max < iterator->nn)
			max = iterator->nn;
		iterator = iterator->next;
	}
	iterator = p->first;
	while (iterator)
	{
		if (iterator->nn == max)
			return (iterator->index);
		iterator = iterator->next;
	}
	return (0);
}

//Cherche dans Pile A l'emplacement de la valeure nn donne en parametre
static int	find_place(t_pile *p, int nn)
{
	t_cont *iterator;

	if (is_less_nn(nn, p))
		return find_place_tolowes(p);
	if (is_bigger_nn(nn, p))
	{
		return (find_place_tobigger(p));
	}
	if (nn < p->first->nn && nn > p->last->nn)
		return (0);
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

//Prepare le Pile A a recevoir une value provenant de pile B
void set_toreceive_a(int spam, t_core *core, int place)
{
	if (place >= core->p1->size / 2)
	{
		action_spammer("rra", spam, core);
		while (1)
		{
			if (core->p1->last->nn < core->p2->first->nn)
				return;
			reverse_rotate_elem(1, core);
		}
	}
	else
	{
		action_spammer("ra", spam, core);
	}
}

//Prepare le Pile B a push une value vers Pile A
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
		action_spammer("ra", spam + 1 + i, core);
	}
	else
	{
		action_spammer("rra", spam, core);
	}
}

void	set_to_last(t_core *core)
{
	push_elem(2, core);
	rotate_elem(1, core);
}

void	set_to_alast(t_core *core)
{
	reverse_rotate_elem(1, core);
	push_elem(2, core);
}

void	brain(t_core *core)
{
	t_cont *cont;
	int saveca;
	int i = 0;

	while (core->p2->size > 0) {
		struct_test(core->p1);
		cont = get_cont_from_index(core->p2, get_total_cost(core));
		printf("value = %d ", cont->val);
		set_topush_b(costb(cont->index, core->p2) - 1, cont->index, core);
		saveca = costa(cont, core->p1);
		int place = find_place(core->p1, core->p2->first->nn);
		printf("ca = %d place = %d\n", saveca, place);
		if (saveca == 1)
			set_to_last(core);
		/*else if (saveca == 0 && place == core->p1->size - 1)
			set_to_alast(core);*/
		else
		{
			if (saveca > 0)
				set_toreceive_a(saveca / 2, core, place);
			push_elem(2, core);
			while (sncf_grp(core) == true)
			{
				push_elem(2, core);
				i++;
			}
			//action_to_a((saveca / 2), core, place, i);
			i = 0;
		}
	}
}
