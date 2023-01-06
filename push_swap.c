#include "push_swap.h"

int main (int argc, char **argv)
{
	t_core core;

	if (argc < 2)
		return (0);
	init_struct_def_val(&core);
	load_main(argv, &core);

	return (0);
}