/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_for_pushing_functions_part1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:42:50 by ateak             #+#    #+#             */
/*   Updated: 2022/02/26 16:56:52 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra_score(t_stack *tmp_a, t_stack *tmp_b, t_arguments *glb)
{
	t_stack	*a_walker;

	while (tmp_a->num != glb->min)
		tmp_a = tmp_a->next;
	while (1)
	{
		if (tmp_b->num < tmp_a->num)
			break ;
		tmp_a = tmp_a->next;
		if (tmp_a == NULL)
			tmp_a = glb->head_a;
	}
	a_walker = glb->head_a;
	while (a_walker != tmp_a)
	{
		a_walker = a_walker->next;
		tmp_b->ra_score++;
	}
	tmp_b->rra_score = glb->size_a - tmp_b->ra_score;
}

void	finding_ra_rb_rra_rrb_score_for_each_num(t_arguments *glb)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*b_walker;

	tmp_a = glb->head_a;
	tmp_b = glb->head_b;
	while (tmp_b != NULL)
	{
		tmp_a = glb->head_a;
		tmp_b->ra_score = 0;
		tmp_b->rb_score = 0;
		tmp_b->rra_score = 0;
		tmp_b->rrb_score = 0;
		ra_rra_score(tmp_a, tmp_b, glb);
		b_walker = glb->head_b;
		while (b_walker != tmp_b)
		{
			b_walker = b_walker->next;
			tmp_b->rb_score++;
		}
		tmp_b->rrb_score = glb->size_b - tmp_b->rb_score;
		tmp_b = tmp_b->next;
	}	
}

void	scoring_variants(t_arguments *glb)
{
	t_stack	*tmp_b;

	tmp_b = glb->head_b;
	tmp_b->var_ra_rb = 0;
	tmp_b->var_rb_rra = 0;
	tmp_b->var_rra_rrb = 0;
	tmp_b->var_rrb_ra = 0;
	while (tmp_b != NULL)
	{
		tmp_b->var_ra_rb = tmp_b->ra_score + tmp_b->rb_score;
		if (tmp_b->ra_score == tmp_b->rb_score)
			tmp_b->var_ra_rb = tmp_b->ra_score;
		tmp_b->var_rb_rra = tmp_b->rb_score + tmp_b->rra_score;
		tmp_b->var_rra_rrb = tmp_b->rra_score + tmp_b->rrb_score;
		if (tmp_b->rra_score == tmp_b->rrb_score)
			tmp_b->var_rra_rrb = tmp_b->rra_score;
		tmp_b->var_rrb_ra = tmp_b->rrb_score + tmp_b->ra_score;
		tmp_b->var_arr[0] = tmp_b->var_ra_rb;
		tmp_b->var_arr[1] = tmp_b->var_rb_rra;
		tmp_b->var_arr[2] = tmp_b->var_rra_rrb;
		tmp_b->var_arr[3] = tmp_b->var_rrb_ra;
		tmp_b = tmp_b->next;
	}
}

void	final_scoring(t_arguments *glb)
{
	t_stack	*tmp_b;
	int		i;

	tmp_b = glb->head_b;
	i = 0;
	while (tmp_b != NULL)
	{
		tmp_b->final_score = tmp_b->var_arr[0];
		i = 1;
		while (i < 4)
		{
			if (tmp_b->final_score > tmp_b->var_arr[i])
				tmp_b->final_score = tmp_b->var_arr[i];
			i++;
		}
		tmp_b = tmp_b->next;
	}
}

void	finding_final_score_min(t_arguments *glb)
{
	t_stack	*tmp_b;

	tmp_b = glb->head_b;
	glb->final_score_min = tmp_b->final_score;
	while (tmp_b != NULL)
	{
		if (glb->final_score_min > tmp_b->final_score)
			glb->final_score_min = tmp_b->final_score;
		tmp_b = tmp_b->next;
	}
}
