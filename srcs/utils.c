/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:43:40 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/21 15:43:42 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_str(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (1, &msg[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

bool	is_str_contains(char *src, char *val)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (val[i] != src[i])
			return (false);
		i++;
	}
	return (true);
}

void	action_writter(char *ac)
{
	static int	i = 0;

	if (is_str_contains(ac, "sa") || is_str_contains(ac, "sb"))
	{
		if (i == 0)
		{
			if (is_str_contains(ac, "sb"))
				put_str("sb");
			else
				put_str("sa");
		}
		else
			i--;
	}
	else if (is_str_contains(ac, "ss"))
	{
		put_str("ss");
		i++;
	}
	else if (is_str_contains(ac, "pa"))
		put_str("pa");
	else if (is_str_contains(ac, "pb"))
		put_str("pb");
	else if (is_str_contains(ac, "ra") || is_str_contains(ac, "rb"))
	{
		if (i == 0)
		{
			if (is_str_contains(ac, "rb"))
				put_str("rb");
			else
				put_str("ra");
		}
		else
			i--;
	}
	else if (is_str_contains(ac, "rr"))
	{
		put_str("rr");
		i++;
	}
	else if (is_str_contains(ac, "rra") || is_str_contains(ac, "rrb"))
	{
		if (i == 0)
		{
			if (is_str_contains(ac, "rrb"))
				put_str("rrb");
			else
				put_str("rra");
		}
		else
			i--;
	}
	else if (is_str_contains(ac, "rrr"))
	{
		put_str("rrr");
		i++;
	}
}

int	ft_atoi(char *s)
{
	int		i;
	int		result;
	short	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		result = (result + (s[i] - '0')) * 10;
		i++;
	}
	return ((result / 10) * sign);
}

void	error_manager(char *msg, t_core *core)
{
	write(1, "Error\n", 6);
	put_str(msg);
	free_struct(core);
	exit(1);
}
