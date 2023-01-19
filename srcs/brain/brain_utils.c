#include "../../push_swap.h"

int	costb(int index, t_pile *p2)
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
		return (p2->size - iterator->index + 2);
	return (iterator->index);
}

int	costa(t_cont *iterator, t_pile *p1)
{
	t_cont *compa;


	if (iterator->nn < p1->first->nn)
		return (0);
	else if (iterator->nn > p1->last->nn)
		return (1);
	compa = p1->first->next;
	while (compa)
	{
		if (iterator->nn < compa->nn && iterator->nn > compa->prev->nn)
		{
			if (compa->index >= p1->size / 2)
			{
				return (((p1->size - (compa->prev->index)) * 2));
			}
			return ((compa->index - 1) * 2);
		}
		compa = compa->next;
	}
	return (0);
}

void	set_topush_bb(int spam, int index, t_core *core) {
	if (index >= core->p2->size / 2)
	{
		action_spammer("rrb", spam, core);
	}
	else
		action_spammer("rb", spam, core);
}

bool grep_worth_val(t_core *core)
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

int	get_total_cost(t_core *core)
{
	int ca;
	int	cb;
	int *cost;
	int i = 0;
	int minval;
	t_cont *iterator;

	cost = malloc(sizeof(int) * core->p2->size);
	iterator = core->p2->first;
	while (iterator)
	{
		ca = costa(iterator, core->p1);
		cb = costb(iterator->index, core->p2);
		cost[i] = ca + cb;
		iterator = iterator->next;
		i++;
	}
	cost[i] = 0;
	i = 0;
	minval = cost[i];
	while (cost[i++])
	{
		if (cost[i] < minval & cost[i] != 0)
			minval = cost[i];
	}
	i = 0;
	while (cost[i] != minval)
		i++;
	free(cost);
	return i + 1;
}