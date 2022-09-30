/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:52:09 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 15:55:37 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

long	*selection_sort(long *num, int size)
{
	int	min;
	int	temp;
	int	i;
	int	j;

	min = 0;
	temp = 0;
	i = 0;
	j = 0;
	while (i != size)
	{
		min = i;
		j = i + 1;
		while (j != size)
		{
			if (num[j] < num[min])
				min = j;
			j++;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
		i++;
	}
	return (num);
}

int	ft_isdigit(int l)
{
	if (l >= 48 && l <= 57)
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *s)
{
	int		sign;
	long	answ;

	sign = 1;
	answ = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\v' \
		|| *s == '\f' || *s == '\r' || *s == '\t'))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	if (!ft_isdigit(*s))
		ft_exit();
	while (*s >= '0' && *s <= '9')
	{
		answ = answ * 10 + *s - 48;
		if (answ * sign > INT_MAX || answ * sign < INT_MIN)
			ft_exit();
		s++;
	}
	if (*s != '\0')
		ft_exit();
	return (sign * answ);
}
