/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:30:47 by ateak             #+#    #+#             */
/*   Updated: 2022/02/23 13:35:23 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_from_b_to_a(t_arguments *glb)
{
	while (glb->size_b > 0)
	{
		finding_ra_rb_rra_rrb_score_for_each_num(glb);
		scoring_variants(glb);
		final_scoring(glb);
		finding_final_score_min(glb);
		detecting_num_for_push(glb);
		glb->size_b--;
		glb->size_a++;
	}
	last_sort_for_stack_a(glb);
}

int	main(int argc, char **argv)
{
	t_arguments	*glb;
	long		*arr;

	if (argc < 2)
		exit (EXIT_FAILURE);
	arr = (long *)malloc(sizeof(long) * (argc - 1));
	if (arr == NULL)
		ft_exit();
	glb = (t_arguments *)malloc(sizeof(t_arguments));
	if (glb == NULL)
		ft_exit();
	glb_init_and_num_parsing(glb, arr, argc, argv);
	arg_checking(arr, glb, argc);
	creating_stack_a(glb, arr, argc);
	free(arr);
	creating_stack_b(glb);
	if (!(glb->head_a->num == glb->min && glb->head_a->next->num == glb->mid))
		sorting_min_max_mid(glb);
	pushing_from_b_to_a(glb);
	exit(EXIT_SUCCESS);
}
