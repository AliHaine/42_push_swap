#include "../../push_swap.h"

bool	init_struct(char *s, struct s_core *core)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_digit(s[i]) == false)
			return (false);

		i++;
	}
	return (true);
}


void	load_main(char **argv, struct s_core *core)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (init_struct(argv[i], core) == false)
			//call struct free
			//exit
			break;
		i++;
	}
}
