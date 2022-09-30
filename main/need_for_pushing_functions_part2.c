/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_for_pushing_functions_part2.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:34:02 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 15:41:10 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_var_ra_rb_or_var_rb_rra(t_arguments *glb, t_stack *tmp_b)
{
	if (glb->final_score_min == tmp_b->var_ra_rb)
	{
		executing_ra_rb(glb, tmp_b);
		push_a(&glb->head_a, &glb->head_b);
	}
	else if (glb->final_score_min == tmp_b->var_rb_rra)
	{
		executing_rb_rra(glb, tmp_b);
		push_a(&glb->head_a, &glb->head_b);
	}
}

void	choose_var_rra_rrb_or_var_rrb_ra(t_arguments *glb, t_stack *tmp_b)
{
	if (glb->final_score_min == tmp_b->var_rra_rrb)
	{
		executing_rra_rrb(glb, tmp_b);
		push_a(&glb->head_a, &glb->head_b);
	}
	else if (glb->final_score_min == tmp_b->var_rrb_ra)
	{
		executing_rrb_ra(glb, tmp_b);
		push_a(&glb->head_a, &glb->head_b);
	}
}

void	detecting_num_for_push(t_arguments *glb)
{
	t_stack	*tmp_b;

	tmp_b = glb->head_b;
	while (tmp_b != NULL)
	{
		if (tmp_b->final_score == glb->final_score_min)
		{
			if (glb->final_score_min == tmp_b->var_ra_rb
				|| glb->final_score_min == tmp_b->var_rb_rra)
			{
				choose_var_ra_rb_or_var_rb_rra(glb, tmp_b);
				break ;
			}
			else if (glb->final_score_min == tmp_b->var_rra_rrb
				|| glb->final_score_min == tmp_b->var_rrb_ra)
			{
				choose_var_rra_rrb_or_var_rrb_ra(glb, tmp_b);
				break ;
			}
		}
		tmp_b = tmp_b->next;
	}
}

void	last_sort_for_stack_a(t_arguments *glb)
{
	t_stack	*a_walker;
	int		i;

	a_walker = glb->head_a;
	i = 1;
	while (a_walker->num != glb->min)
	{
		a_walker = a_walker->next;
		i++;
	}
	while (glb->head_a->num != glb->min)
	{
		if (i > (glb->size_a / 2 + 1))
		{
			reverse_rotate_a(&glb->head_a);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate_a(&glb->head_a);
			write(1, "ra\n", 3);
		}
	}
}
