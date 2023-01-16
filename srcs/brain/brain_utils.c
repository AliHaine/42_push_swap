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