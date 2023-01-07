#include "../../push_swap.h"

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
}
