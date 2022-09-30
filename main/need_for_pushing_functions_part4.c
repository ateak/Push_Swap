/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_for_pushing_functions_part4.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:02:20 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 16:02:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	executing_rb_rra(t_arguments *glb, t_stack *tmp_b)
{
	int		i;
	int		j;

	i = tmp_b->rb_score;
	j = tmp_b->rra_score;
	while (i > 0)
	{
		rotate_b(&glb->head_b);
		write(1, "rb\n", 3);
		i--;
	}
	while (j > 0)
	{
		reverse_rotate_a(&glb->head_a);
		write(1, "rra\n", 4);
		j--;
	}		
}

void	executing_rrb_ra(t_arguments *glb, t_stack *tmp_b)
{
	int		i;
	int		j;

	i = tmp_b->rrb_score;
	j = tmp_b->ra_score;
	while (i > 0)
	{
		reverse_rotate_b(&glb->head_b);
		write(1, "rrb\n", 4);
		i--;
	}
	while (j > 0)
	{
		rotate_a(&glb->head_a);
		write(1, "ra\n", 3);
		j--;
	}		
}
