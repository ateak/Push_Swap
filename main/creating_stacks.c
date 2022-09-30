/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:50:31 by ateak             #+#    #+#             */
/*   Updated: 2022/02/22 20:24:41 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	creating_stack_a(t_arguments *glb, long *arr, int argc)
{
	int	i;

	glb->head_a = create_node(arr[0]);
	i = 1;
	while (i != argc - 1)
	{
		push_back(&glb->head_a, arr[i]);
		i++;
	}
}

void	creating_stack_b_part2(t_arguments *glb)
{
	if (glb->head_a->num > glb->mid)
	{
		push_b(&glb->head_a, &glb->head_b);
		write(1, "pb\n", 3);
		glb->size_a -= 1;
		glb->size_b += 1;
	}
	else
	{
		push_b(&glb->head_a, &glb->head_b);
		write(1, "pb\n", 3);
		if (glb->size_b > 0)
		{
			rotate_b(&glb->head_b);
			write(1, "rb\n", 3);
		}
		glb->size_a -= 1;
		glb->size_b += 1;
	}
}

void	creating_stack_b(t_arguments *glb)
{
	while (glb->size_a != 3)
	{
		if (glb->head_a->num == glb->min
			|| glb->head_a->num == glb->max
			|| glb->head_a->num == glb->mid)
		{
			rotate_a(&glb->head_a);
			write(1, "ra\n", 3);
		}
		else
			creating_stack_b_part2(glb);
	}
}

void	sorting_min_max_mid(t_arguments *glb)
{
	if (glb->head_a->num == glb->max && glb->head_a->next->num == glb->mid)
	{
		swap_a(&glb->head_a);
		write(1, "sa\n", 3);
	}
	else if (glb->head_a->num == glb->min && glb->head_a->next->num == glb->max)
	{
		swap_a(&glb->head_a);
		write(1, "sa\n", 3);
	}	
	else if (glb->head_a->num == glb->mid && glb->head_a->next->num == glb->min)
	{
		swap_a(&glb->head_a);
		write(1, "sa\n", 3);
	}
}
