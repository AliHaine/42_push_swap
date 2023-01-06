#include "../../push_swap.h"

bool	init_struct(int n, struct s_core *core)
{
	t_cont pile
	return (true);
}

void	load_main(char **argv, struct s_core *core)
{
	int	i;
	int	n;

	i = 0;
	while (argv[i])
	{
		n = get_number(argv[i]);
		if (init_struct(n, core) == false)
			//call struct free
			//exit
			break;
		i++;
	}
}
