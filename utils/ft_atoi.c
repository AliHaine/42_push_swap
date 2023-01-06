#include "../push_swap.h"

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
	return (result * sign);
}
