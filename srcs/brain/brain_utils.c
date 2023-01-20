#include "../../push_swap.h"

void	set_topush_bb(int spam, int index, t_core *core) {
	if (index >= core->p2->size / 2)
	{
		action_spammer("rrb", spam, core);
	}
	else
		action_spammer("rb", spam, core);
}

bool is_less_nn(int nn, t_pile *p)
{
	t_cont *iterator;

	iterator = p->first;
	while (iterator)
	{
		if (iterator->nn < nn)
			return (false);
		iterator = iterator->next;
	}
	return (true);
}

bool is_bigger_nn(int nn, t_pile *p)
{
	t_cont *iterator;

	iterator = p->first;
	while (iterator)
	{
		if (iterator->nn > nn)
			return (false);
		iterator = iterator->next;
	}
	return (true);
}

//Apres avoir Push un element sur Pile A, verifie si il ne peut as profiter pour push d'autres elements qui seraient
//compris entre la derniere valeur dans Pile A et la premiere valeur dans Pile A (aui est la valeur precedemment push
//Si il s'avere au'une valeur proche dans la Pile B peut etre send, alors il met la dite valeur en haut de la pile B
//Afin au'elle puisse etre push immediatement
bool sncf_grp(t_core *core)
{
	t_cont *iterator;
	int i = 0;

	iterator = core->p2->first;
	while (i++ < 10)
	{
		if (iterator->nn < core->p1->first->nn && iterator->nn > core->p1->last->nn)
		{
			set_topush_bb(iterator->index - 1, iterator->index - 1, core);
			return (true);
		}
	}
	return (false);
}