/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack_a_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:45:50 by ateak             #+#    #+#             */
/*   Updated: 2022/02/23 18:48:05 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*create_node(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->num = num;
	node->next = NULL;
	return (node);
}

void	push_back(t_stack **list, int num)
{
	t_stack	*new_element;
	t_stack	*tmp;

	new_element = create_node(num);
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_element;
}

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
