/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:52:09 by ateak             #+#    #+#             */
/*   Updated: 2022/02/23 18:12:56 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while ((i < len) && (s1[i] == s2[i]))
		if (s1[i++] == 0)
			return (0);
	if (i == len)
		return (0);
	return (s1[i] - s2[i]);
}
