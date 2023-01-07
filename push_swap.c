#include "push_swap.h"

int main (int argc, char **argv)
{
	t_core core;

	t_pile p1;
	t_pile p2;

	core.p1 = &p1;
	core.p2 = &p2;
	if (argc < 2)
		return (0);
	init_struct_def_val(&core);
	load_main(argv, &core);
	struct_test(core.p1);
	swap_elem(0, &core);
	write(1, "\n", 1);
	struct_test(core.p1);

	return (0);
}