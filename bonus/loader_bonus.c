/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:45:53 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/27 15:45:55 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	load_main_bonus(char **argv, struct s_core *core, int i)
{
	long long int	n;

	while (argv[i])
	{
		if (is_number(argv[i]) == false)
			error_manager(ERROR_NOT_NBR, core);
		n = get_number(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		if (is_val_alr(n, core->p1) == true)
			error_manager(ERROR_ALR_NBR, core);
		if (!create_new_cont(n, core->p1))
			return (0);
		i++;
	}
	return (1);
}
