#include "../../push_swap.h"

/*static int	find_place(t_pile *p, int nn)
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
		{
			return (iterator->index);
		}
		iterator = iterator->next;
	}
	printf("Aucun resultat\n");
	return (0);
}

static int	get_sprt_cost(t_pile *p, int nn)
{
	int cost;
	t_cont *iterator;

	cost = 0;
	if (nn > p->size)
	{
		iterator = p->last;
		while (iterator->index != nn)
		{
			iterator = iterator->prev;
			cost++;
		}
	}
	else
	{
		iterator = p->first;
		while (iterator->index != nn)
		{
			iterator = iterator->next;
			cost++;
		}
	}
	//printf("cost = %d, nn = %d\n", cost, nn);
	return (cost);
}

int get_worth(t_core *core)
{
	int ac;
	int bc;
	int tc;
	int val;

	int ac2;
	int bc2;
	int tc2;
	int val2;

	bc = 1;
	ac = find_place(core->p1, core->p2->first->nn);
	tc = ac + bc;
	val = core->p2->first->val;
	bc = 2;
	ac = find_place(core->p1, core->p2->last->nn);
	tc = ac + bc;
	val = core->p2->last->val;
	if ()


	return (val);

}*/