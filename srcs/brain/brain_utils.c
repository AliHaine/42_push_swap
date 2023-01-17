#include "../../push_swap.h"

/*static int	find_place(t_pile *p, int nn)
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
		//printf("iterator\n");
		if (nn < iterator->nn && nn > iterator->prev->nn)
		{

			return (iterator->index);
		}
		iterator = iterator->next;
	}
	printf("Aucun resultat\n");
	return (0);
}*/

static int	costb(int index, t_pile *p2)
{
	t_cont *iterator;

	iterator = p2->first;
	while (iterator)
	{
		if (iterator->index == index)
			break ;
		iterator = iterator->next;
	}
	if (iterator->index >= p2->size / 2)
		return (p2->size - iterator->index);
	return (iterator->index);
}

static int	costa(t_cont *iterator, t_pile *p1)
{
	t_cont *compa;


	if (iterator->nn < p1->first->nn)
		return (0);
	else if (iterator->nn > p1->last->nn)
		return (2);
	compa = p1->first->next;
	while (compa)
	{
		if (iterator->nn < compa->nn && iterator->nn > compa->prev->nn)
		{
			if (iterator->index >= p1->size / 2)
			{
				printf("cost a val = %d, ca cb = %d %d\n", iterator->val, p1->size, iterator->index);
				return (((p1->size - iterator->index) * 2) + 1);
			}
			return (compa->index);
		}
		compa = compa->next;
	}
	return (0);
}

int	get_total_cost(t_core *core)
{
	int ca;
	int	cb;
	int *cost;
	int i = 0;
	t_cont *iterator;

	cost = malloc(sizeof(int) * core->p2->size);
	iterator = core->p2->first;
	while (iterator)
	{
		ca = costa(iterator, core->p1);
		cb = costb(iterator->index, core->p2);
		printf("val = %d, ca cb = %d %d\n", iterator->val, ca, cb);
		cost[i] = ca + cb;
		iterator = iterator->next;
		i++;
	}
	i = 0;
	struct_test(core->p1);
	printf("\n");
	struct_test(core->p2);
	while (cost[i])
	{
		printf("ttc = %d\n", cost[i]);
		i++;
	}
	return ca + cb;
}