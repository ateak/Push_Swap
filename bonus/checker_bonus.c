/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:35:43 by ateak             #+#    #+#             */
/*   Updated: 2022/02/26 13:06:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	checking_sorted_stack(t_arguments *glb)
{
	t_stack	*tmp;

	tmp = glb->head_a;
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
		{
			write(1, "KO\n", 3);
			exit (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	if (glb->size_b == 0)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	write(1, "KO\n", 3);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_arguments	*glb;
	long		*arr;
	char		*instruction;

	if (argc < 2)
		exit(EXIT_FAILURE);
	arr = (long *)malloc(sizeof(long) * (argc - 1));
	if (arr == NULL)
		ft_exit();
	glb = (t_arguments *)malloc(sizeof(t_arguments));
	if (glb == NULL)
		ft_exit();
	glb_init_and_num_parsing(glb, arr, argc, argv);
	arguments_checking(arr, argc);
	creating_stack_a(glb, arr, argc);
	free(arr);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		ft_compare(instruction, glb, ft_strlen(instruction));
		instruction = get_next_line(0);
	}
	checking_sorted_stack(glb);
}
