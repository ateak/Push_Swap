/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_init_and_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:44:24 by ateak             #+#    #+#             */
/*   Updated: 2022/02/22 20:56:32 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*glb_init_and_num_parsing(t_arguments *glb, long *arr,
									int argc, char **argv)
{
	int	i;
	int	j;

	glb->head_a = NULL;
	glb->head_b = NULL;
	glb->size_a = argc - 1;
	glb->size_b = 0;
	glb->min = 0;
	glb->max = 0;
	glb->mid = 0;
	glb->final_score_min = 0;
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

int	check_sorted_stack(long *arr, long *sorted_arr, int argc)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i != argc - 2)
	{
		if (arr[i] == sorted_arr[i])
			flag++;
		i++;
	}
	if (flag == argc - 2)
		return (1);
	else
		return (0);
}

void	search_min_max_mid(t_arguments *glb, long *sorted_arr, int argc)
{
	glb->min = sorted_arr[0];
	glb->max = sorted_arr[argc - 2];
	glb->mid = sorted_arr[(argc - 2) / 2];
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

void	arg_checking(long *arr, t_arguments *glb, int argc)
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
	if (check_sorted_stack(arr, sorted_arr, argc))
		exit(EXIT_SUCCESS);
	if (argc == 3 && !(check_sorted_stack(arr, sorted_arr, argc)))
	{
		write(1, "sa\n", 3);
		exit(EXIT_SUCCESS);
	}
	search_min_max_mid(glb, sorted_arr, argc);
	free(sorted_arr);
}
