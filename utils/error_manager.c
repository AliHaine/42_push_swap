#include "../push_swap.h"

static	void put_char(char *msg)
{
	int i;

	i = 0;
	while (msg[i])
	{
		write (1, &msg[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	error_manager(char *msg, t_core *core)
{
	write (1, "Error\n", 6);
	put_char(msg);
	free_struct(core);
	exit(1);
}
