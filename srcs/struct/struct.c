#include "../../push_swap.h"

void	reverse_rotate_elem(short mode, t_core *core)
{
	t_pile *target;

	target = core->p2;
	if (mode == 1)
		target = core->p1;
	update_index(target, 1);
	target->first->prev = target->last;
	target->last = target->last->prev;
	target->first->prev->next = target->first;
	target->first = target->first->prev;
	target->first->prev = NULL;
	target->last->next = NULL;
	target->first->index = 1;
	if (mode == 3)
		reverse_rotate_elem(1, core);
}

void	rotate_elem(short mode, t_core *core)
{
	t_pile *target;
	target = core->p2;
	if (mode == 1)
		target = core->p1;
	update_index(target, -1);
	target->last->next = target->first;
	target->first = target->first->next;
	target->last->next->prev = target->last;
	target->last = target->last->next;
	target->last->next = NULL;
	target->first->prev = NULL;
	target->last->index = target->last->prev->index + 1;
	if (mode == 3)
		rotate_elem(1, core);
}

void	push_elem(short mode, t_core *core)
{
	t_cont *tmp;
	t_pile *r;
	t_pile *g;

	tmp = NULL;
	r = core->p2;
	g = core->p1;
	if (mode == 2)
	{
		r = core->p1;
		g = core->p2;
	}
	if (g->first->next != NULL)
		tmp = g->first->next;
	if (r->first == NULL)
	{
		r->first = g->first;
		r->first->next = NULL;
		r->last = g->first;
	}
	else
	{
		update_index(r, 1);
		r->first->prev = g->first;
		r->first->prev->next = r->first;
		r->first = r->first->prev;
	}
	r->first->prev = NULL;
	g->first = tmp;
	g->first->prev = NULL;
	r->size++;
	g->size--;
	update_index(g, -1);
}

void	swap_elem(short mode, t_core *core)
{
	t_cont *tmp;
	t_pile *target;

	target = core->p2;
	if (mode == 1)
		target = core->p1;
	tmp = target->first->next;
	target->first->next = tmp->next;
	tmp->next = target->first;
	target->first = tmp;
	target->first->index = 1;
	target->first->next->index = 2;
	if (mode == 3)
		swap_elem(2, core);
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
