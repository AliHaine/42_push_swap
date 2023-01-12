#include "../../push_swap.h"

void sort_base_pile(t_core *core)
{
	t_cont *n2;
	t_cont *n3;

	n2 = core->p1->first->next;
	n3 = core-> p1->first->next->next;

	if (core->p1->first->nn < n2->nn && n2->nn < n3->nn)
		return ;
	else if (core->p1->first->nn < n2->nn && n2->nn > n3->nn)
		reverse_rotate_elem(1, core);
	else if (core->p1->first->nn > n2->nn && n2->nn > n3->nn)
	{
		swap_elem(1, core);
		reverse_rotate_elem(1, core);
	}
	else if (core->p1->first->nn > n2->nn && n2->nn < n3->nn && core->p1->first->nn < n3->nn)
		swap_elem(1, core);
	else if (core->p1->first->nn > n2->nn && n2->nn < n3->nn && core->p1->first->nn > n3->nn)
	{
		swap_elem(1, core);
		reverse_rotate_elem(1, core);
		reverse_rotate_elem(1, core);
		swap_elem(1, core);
	}
	else
	{
		reverse_rotate_elem(1, core);
		swap_elem(1, core);
	}
}

static void	set_base_pile(t_core *core)
{
	int	size;
	int i;

	size = core->p1->size / 2;
	i = 0;
	while (1)
	{
		if (core->p1->first->nn <= size)
		{
			push_elem(1, core);
			i++;
			if (i == size)
				break;
		}
		else
			rotate_elem(1, core);
	}
	size = core->p1->size;
	while (size != 3)
	{
		push_elem(1, core);
		size--;
	}
}

static void	set_nn(struct s_pile *p1, int size, int i)
{
	int low;
	t_cont *iterator;

	iterator = p1->first;
	while (size - 1 < p1->size)
	{
		while (iterator->nn != 0)
			iterator = iterator->next;
		i = iterator->index;
		low = iterator->val;
		iterator = p1->first;
		while (1)
		{
			if (iterator->val < low && iterator->nn == 0)
			{
				i = iterator->index;
				low = iterator->val;
			}
			if (iterator->next == NULL)
			{
				get_cont_from_index(p1, i)->nn = size;
				iterator= p1->first;
				size++;
				break;
			}
			iterator = iterator->next;
		}
	}
}

void	load_main(char **argv, struct s_core *core)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == false)
			error_manager(error_not_nbr, core);
		n = get_number(argv[i]);
		if (is_val_alr(n, core->p1) == true)
			error_manager(error_alr_nbr, core);
		create_new_cont(n, core->p1);
		i++;
	}
	set_nn(core->p1, 1, 0);
	if (core->p1->size == 3)
		return;
	set_base_pile(core);
	sort_base_pile(core);
}
