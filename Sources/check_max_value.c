/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:18 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_index(t_node *stack_a, t_node *b, int max, t_node *node)
{
	int		index;
	int		i;

	i = 0;
	while (node->next != stack_a)
	{
		if (b->nb > node->nb)
		{
			if (node->nb > max)
			{
				max = node->nb;
				index = i;
			}
		}
		node = node->next;
		i++;
	}
	if (b->nb > node->nb)
		if (node->nb > max)
			index = i;
	return (index);
}

int	is_max(t_node *stack_a, t_node *b)
{
	t_node	*node;
	int		max;

	node = stack_a;
	while (node->next != stack_a)
	{
		if (node->nb > b->nb)
			return (-1);
		node = node->next;
	}
	if (node->nb > b->nb)
		return (-1);
	node = stack_a;
	max = -2147483648;
	return (find_index(stack_a, b, max, node));
}
