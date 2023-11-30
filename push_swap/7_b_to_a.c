/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:11 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 18:19:25 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruct	find_move(t_stack *stack, int match)
{
	t_instruct	node;

	node.rotate = true;
	node.index = 0;
	while (stack)
	{
		if (stack->value == match)
		{
			node.index = stack->index;
			node.value = stack->value;
			if (node.index >= (stack_size(stack) / 2))
				node.rotate = false;
			return (node);
		}
		stack = stack->next;
	}
	return (node);
}

void	send_to_a(t_stack **a, t_stack **b, t_instruct next_move)
{
	if ((*b)->value == next_move.value)
		push(b, a, 'a');
	else
	{
		while ((*b)->value != next_move.value)
		{
			if (next_move.rotate)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack			*last;
	t_instruct		next_value;

	while (stack_size(*b) > 0)
	{
		next_value = find_move(*b, max_value(*b));
		send_to_a(a, b, next_value);
	}
	last = last_node(*a);
	while (last->value < (*a)->value)
	{
		reverse_rotate(a, 'a');
		last = last_node(*a);
	}
}
