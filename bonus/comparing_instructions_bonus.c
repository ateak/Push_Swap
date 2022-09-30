/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparing_instructions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:17:07 by ateak             #+#    #+#             */
/*   Updated: 2022/02/24 11:43:10 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_compare_addition(char *instruction, t_arguments *glb, size_t len)
{
	if (!ft_strncmp(instruction, "ra\n", len) && len == 3)
		rotate_a(&glb->head_a);
	else if (!ft_strncmp(instruction, "rb\n", len) && len == 3)
		rotate_b(&glb->head_b);
	else if (!ft_strncmp(instruction, "rr\n", len) && len == 3)
	{
		rotate_a(&glb->head_a);
		rotate_b(&glb->head_b);
	}
	else if (!ft_strncmp(instruction, "rra\n", len) && len == 4)
		reverse_rotate_a(&glb->head_a);
	else if (!ft_strncmp(instruction, "rrb\n", len) && len == 4)
		reverse_rotate_b(&glb->head_b);
	else if (!ft_strncmp(instruction, "rrr\n", len) && len == 4)
	{
		reverse_rotate_a(&glb->head_a);
		reverse_rotate_b(&glb->head_b);
	}
}

void	ft_compare(char *instruction, t_arguments *glb, size_t len)
{
	if (!ft_strncmp(instruction, "sa\n", len) && len == 3)
		swap_a(&glb->head_a);
	else if (!ft_strncmp(instruction, "sb\n", len) && len == 3)
		swap_b(&glb->head_b);
	else if (!ft_strncmp(instruction, "ss\n", len) && len == 3)
	{
		swap_a(&glb->head_a);
		swap_b(&glb->head_b);
	}
	else if (!ft_strncmp(instruction, "pa\n", len) && len == 3)
		push_a(&glb->head_a, &glb->head_b, glb);
	else if (!ft_strncmp(instruction, "pb\n", len) && len == 3)
		push_b(&glb->head_a, &glb->head_b, glb);
	else if ((!ft_strncmp(instruction, "ra\n", len) && len == 3)
		|| (!ft_strncmp(instruction, "rb\n", len) && len == 3)
		|| (!ft_strncmp(instruction, "rr\n", len) && len == 3)
		|| (!ft_strncmp(instruction, "rra\n", len) && len == 4)
		|| (!ft_strncmp(instruction, "rrb\n", len) && len == 4)
		|| (!ft_strncmp(instruction, "rrr\n", len) && len == 4))
		ft_compare_addition(instruction, glb, len);
	else
		ft_exit();
	free(instruction);
}
