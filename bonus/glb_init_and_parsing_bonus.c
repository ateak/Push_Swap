/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_init_and_parsing_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:44:24 by ateak             #+#    #+#             */
/*   Updated: 2022/02/23 19:17:42 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	*glb_init_and_num_parsing(t_arguments *glb, long *arr,
									int argc, char **argv)
{
	int	i;
	int	j;

	glb->head_a = NULL;
	glb->head_b = NULL;
	glb->size_b = 0;
	i = 1;
	j = 0;
	while (i != argc)
	{
		arr[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (arr);
}

long	*copy_arr_into_sorted_arr(long *arr, long *sorted_arr, int argc)
{
	int	i;

	i = 0;
	while (i != argc - 1)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	return (sorted_arr);
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

void	arguments_checking(long *arr, int argc)
{
	long	*sorted_arr;
	int		i;

	sorted_arr = (long *)malloc(sizeof(long) * (argc - 1));
	if (sorted_arr == NULL)
		ft_exit();
	copy_arr_into_sorted_arr(arr, sorted_arr, argc);
	selection_sort(sorted_arr, argc - 1);
	i = 0;
	while (i != argc - 2)
	{
		if (sorted_arr[i] == sorted_arr[i + 1])
			ft_exit();
		i++;
	}
	free(sorted_arr);
}
