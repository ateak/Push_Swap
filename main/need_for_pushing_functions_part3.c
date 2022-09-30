/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_for_pushing_functions_part3.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:41:47 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 15:41:48 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_addition(t_arguments *glb, t_stack *tmp_b)
{
	int	i;
	int	j;

	i = tmp_b->ra_score;
	j = tmp_b->rb_score;
	while (i > 0 && j > 0)
	{
		rotate_a(&glb->head_a);
		rotate_b(&glb->head_b);
		write(1, "rr\n", 3);
		i--;
		j--;
	}
	while (i > 0)
	{
		rotate_a(&glb->head_a);
		write(1, "ra\n", 3);
		i--;
	}
	while (j > 0)
	{
		rotate_b(&glb->head_b);
		write(1, "rb\n", 3);
		j--;
	}
}

void	executing_ra_rb(t_arguments *glb, t_stack *tmp_b)
{
	int		i;

	if (tmp_b->ra_score == tmp_b->rb_score)
	{
		i = tmp_b->ra_score;
		while (i > 0)
		{
			rotate_a(&glb->head_a);
			rotate_b(&glb->head_b);
			write(1, "rr\n", 3);
			i--;
		}
	}
	else if (tmp_b->ra_score != tmp_b->rb_score)
		ra_rb_addition(glb, tmp_b);
}

void	rra_rrb_addition(t_arguments *glb, t_stack *tmp_b)
{
	int	i;
	int	j;

	i = tmp_b->rra_score;
	j = tmp_b->rrb_score;
	while (i > 0 && j > 0)
	{
		reverse_rotate_a(&glb->head_a);
		reverse_rotate_b(&glb->head_b);
		write(1, "rrr\n", 4);
		i--;
		j--;
	}
	while (i > 0)
	{
		reverse_rotate_a(&glb->head_a);
		write(1, "rra\n", 4);
		i--;
	}
	while (j > 0)
	{
		reverse_rotate_b(&glb->head_b);
		write(1, "rrb\n", 4);
		j--;
	}
}

void	executing_rra_rrb(t_arguments *glb, t_stack *tmp_b)
{
	int		i;

	if (tmp_b->rra_score == tmp_b->rrb_score)
	{
		i = tmp_b->rra_score;
		while (i > 0)
		{
			reverse_rotate_a(&glb->head_a);
			reverse_rotate_b(&glb->head_b);
			write(1, "rrr\n", 4);
			i--;
		}
	}
	else if (tmp_b->rra_score != tmp_b->rrb_score)
		rra_rrb_addition(glb, tmp_b);
}
