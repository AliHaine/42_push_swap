#include "../../push_swap.h"

static void	sort_a(t_core *core, int needtobe)
{
	if (needtobe == 1)
	{
		push_elem(2, core);
	}
	else if (needtobe == 2)
	{
		push_elem(2, core);
		swap_elem(1, core);
	}
	else if (needtobe == core->p1->size + 1)
	{
		//printf("size = %d, nn = %d, max %d min %d, max %d min %d\n", core->p1->size, needtobe, core->p1->last->nn, core->p1->last->val, core->p2->first->nn, core->p2->first->val);
		push_elem(2, core);
		rotate_elem(1, core);
	}
	else if (needtobe == core->p1->size)
	{
		//reverse_rotate_elem(1, core);
		reverse_rotate_elem(1, core);
		push_elem(2, core);
		rotate_elem(1, core);
		//rotate_elem(1, core);
		rotate_elem(1, core);
	}
	else
	{
		rotate_elem(2, core);
	}
}

static int	find_place(t_pile *p, int nn)
{
	t_cont *iterator;

	if (nn < p->first->nn)
		return (1);
	else if (nn > p->last->nn)
	{
		printf(" nn actu = %d, nn = %d\n", nn, p->last->nn);
		return (p->size + 1);
	}
	iterator = p->first->next;
	while (iterator)
	{
		if (nn < iterator->nn && nn > iterator->prev->nn)
		{
			/*if (iterator->next == 0)
				return (iterator->index) - 1;*/
			//printf("value = %d, nn actu = %d, nn = %d, nn prev %d, %d index, %d size\n", iterator->val, iterator->nn, nn, iterator->next->index, iterator->index, p->size);
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
	while (core->p2->size > 1)
	{
		nn = core->p2->first->nn;
		needtobe = find_place(core->p1, nn);
		//printf(" = %d", needtobe);
		sort_a(core, needtobe);
		i++;
		if (i > 800)
			break ;
	}
}
