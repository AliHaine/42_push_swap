/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:43:18 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/21 15:43:19 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_helper(t_core *core, t_cont *n2, t_cont *n3)
{
	if (core->p1->first->nn > n2->nn && n2->nn < n3->nn
		&& core->p1->first->nn < n3->nn)
		swap_elem(1, core);
	else if (core->p1->first->nn > n2->nn && n2->nn < n3->nn
		&& core->p1->first->nn > n3->nn)
	{
		reverse_rotate_elem(1, core);
		reverse_rotate_elem(1, core);
	}
	else
		reverse_rotate_elem(1, core);
}

void	sort_base_pile(t_core *core)
{
	t_cont	*n2;
	t_cont	*n3;

	n2 = core->p1->first->next;
	n3 = core->p1->first->next->next;
	if (core->p1->first->nn < n2->nn && n2->nn < n3->nn)
		return ;
	else if (core->p1->first->nn < n2->nn && n2->nn > n3->nn
		&& core->p1->first->nn < n3->nn)
	{
		reverse_rotate_elem(1, core);
		swap_elem(1, core);
	}
	else if (core->p1->first->nn > n2->nn && n2->nn > n3->nn)
	{
		rotate_elem(1, core);
		swap_elem(1, core);
	}
	else
		sort_helper(core, n2, n3);
}

static void	set_base_pile(t_core *core)
{
	int	size;
	int	i;

	size = core->p1->size / 2;
	i = 0;
	while (1)
	{
		if (core->p1->first->nn <= size)
		{
			push_elem(1, core);
			i++;
			if (i == size)
				break ;
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

static void	set_nn(struct s_pile *p1, int size, int i, int low)
{
	t_cont	*iterator;

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
				set_nn_helper(p1, &size, &iterator, i);
				break ;
			}
			iterator = iterator->next;
		}
	}
}

/*int load_main_splitter(char *argv, struct s_core *core)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == false)
			error_manager(ERROR_NOT_NBR, core);
		n = get_number(argv[i]);
		if (is_val_alr(n, core->p1) == true)
			error_manager(ERROR_ALR_NBR, core);
		if (!create_new_cont(n, core->p1))
			return (0);
		i++;
	}
	set_nn(core->p1, 1, 0, 0);
	if (core->p1->size == 3)
		return (1);
	if (is_sort(core->p1) == true)
		return (0);
	set_base_pile(core);
	sort_base_pile(core);
	return (1);
}*/

int	load_main(char **argv, struct s_core *core)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == false)
			error_manager(ERROR_NOT_NBR, core);
		n = get_number(argv[i]);
		if (is_val_alr(n, core->p1) == true)
			error_manager(ERROR_ALR_NBR, core);
		if (!create_new_cont(n, core->p1))
			return (0);
		i++;
	}
	set_nn(core->p1, 1, 0, 0);
	if (core->p1->size == 3)
		return (1);
	if (is_sort(core->p1) == true)
		return (0);
	set_base_pile(core);
	sort_base_pile(core);
	return (1);
}
