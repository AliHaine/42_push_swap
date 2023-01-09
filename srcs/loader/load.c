#include "../../push_swap.h"

void	set_nn(struct s_pile *p1)
{
	int i;
	int size;
	int low;
	t_cont *iterator;

	size = 1;
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
	set_nn(core->p1);
}
