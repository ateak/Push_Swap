/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:45 by ateak             #+#    #+#             */
/*   Updated: 2022/02/26 13:03:26 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_stack **head_a)
{
	t_stack	*tmp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	tmp = (*head_a)->next->next;
	(*head_a)->next->next = *head_a;
	*head_a = (*head_a)->next;
	(*head_a)->next->next = tmp;
}

void	swap_b(t_stack **head_b)
{
	t_stack	*tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = (*head_b)->next->next;
	(*head_b)->next->next = *head_b;
	*head_b = (*head_b)->next;
	(*head_b)->next->next = tmp;
}

void	push_a(t_stack **head_a, t_stack **head_b, t_arguments *glb)
{
	t_stack	*tmp;

	if (*head_b == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = *head_a;
	*head_a = tmp;
	glb->size_b--;
}

void	push_b(t_stack **head_a, t_stack **head_b, t_arguments *glb)
{
	t_stack	*tmp;

	if (*head_a == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = *head_b;
	*head_b = tmp;
	glb->size_b++;
}
