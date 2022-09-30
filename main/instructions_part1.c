/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:45 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 15:32:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head_a)
{
	t_stack	*tmp;

	tmp = (*head_a)->next->next;
	(*head_a)->next->next = *head_a;
	*head_a = (*head_a)->next;
	(*head_a)->next->next = tmp;
}

void	swap_b(t_stack **head_b)
{
	t_stack	*tmp;

	tmp = (*head_b)->next->next;
	(*head_b)->next->next = *head_b;
	*head_b = (*head_b)->next;
	(*head_b)->next->next = tmp;
}

void	push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = *head_a;
	*head_a = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = *head_b;
	*head_b = tmp;
}
