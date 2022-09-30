/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:45:50 by ateak             #+#    #+#             */
/*   Updated: 2022/02/21 15:50:23 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
