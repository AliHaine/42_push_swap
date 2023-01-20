
#include "../../push_swap.h"

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
