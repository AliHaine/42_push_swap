/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:43:25 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/21 15:43:27 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

bool	is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (true);
	return (false);
}

bool	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (is_digit(s[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	get_number(char *s)
{
	int	nbr;

	nbr = ft_atoi(s);
	return (nbr);
}