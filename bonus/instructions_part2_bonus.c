/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:33:20 by ateak             #+#    #+#             */
/*   Updated: 2022/02/26 13:07:34 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_a(t_stack **head_a)
{
	t_stack	*tmp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	tmp = *head_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head_a;
	*head_a = (*head_a)->next;
	tmp->next->next = NULL;
}

void	rotate_b(t_stack **head_b)
{
	t_stack	*tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = *head_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head_b;
	*head_b = (*head_b)->next;
	tmp->next->next = NULL;
}

void	reverse_rotate_a(t_stack **head_a)
{
	t_stack	*tmp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	tmp = *head_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *head_a;
	*head_a = tmp->next;
	tmp->next = NULL;
}

void	reverse_rotate_b(t_stack **head_b)
{
	t_stack	*tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = *head_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *head_b;
	*head_b = tmp->next;
	tmp->next = NULL;
}
