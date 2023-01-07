#include "../../push_swap.h"

void	push_elem(short mode, t_core *core)
{
	if (mode == 1)
	{
		create_new_cont(core->p1->first->val)
	}
}

void	swap_elem(short mode, t_core *core)
{
	t_cont *tempo;

	if (mode == 0 || mode == 3)
	{
		tempo = core->p1->first->next;
		core->p1->first->next = tempo->next;
		tempo->next = core->p1->first;
		core->p1->first = tempo;
		core->p1->first->index = 1;
		core->p1->first->next->index = 2;
		if (mode == 3)
			swap_elem(1, core);
	}
	else if (mode == 1)
	{
		tempo = core->p2->last->prev;
		core->p2->last->prev = tempo->prev;
		tempo->prev = core->p1->last;
		core->p2->last = tempo;
		core->p2->last->index = core->p2->size;
		core->p2->last->next->index = core->p2->size - 1;
	}
}

bool create_new_cont(int n, struct s_pile *p)
{
	t_cont *cont;

	cont = malloc(sizeof(*cont));
	if (cont == NULL)
		return (false);
	cont->next = NULL;
	cont->prev = NULL;
	if (p->first == NULL)
		p->first = cont;
	else
	{
		p->last->next = cont;
		cont->prev = p->last;
	}
	p->last = cont;
	cont->val = n;
	cont->index = p->size + 1;
	cont->nn = 0;
	p->size++;
	return (true);
}
