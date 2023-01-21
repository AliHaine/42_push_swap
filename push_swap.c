/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:42:13 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/21 15:42:15 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_a_sort(t_core *core)
{
	t_cont	*cont;

	cont = core->p1->first;
	while (cont)
	{
		if (cont->nn == 1)
			break ;
		cont = cont->next;
	}
	while (cont->index != 1)
	{
		if (cont->index >= core->p1->size / 2)
			reverse_rotate_elem(1, core);
		else
			rotate_elem(1, core);
	}
	if (cont->prev)
		rotate_elem(1, core);
}

static void	init_struct_def_val(t_core *core)
{
	core->p1->first = NULL;
	core->p1->last = NULL;
	core->p2->first = NULL;
	core->p2->last = NULL;
	core->p1->size = 0;
	core->p2->size = 0;
}

int	main(int argc, char **argv)
{
	t_core	core;
	t_pile	p1;
	t_pile	p2;

	core.p1 = &p1;
	core.p2 = &p2;
	if (argc < 2)
		return (0);
	init_struct_def_val(&core);
	load_main(argv, &core);
	brain(&core);
	make_a_sort(&core);
	free_struct(&core);
	return (0);
}
