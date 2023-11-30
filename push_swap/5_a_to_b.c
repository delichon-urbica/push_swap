/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:33:56 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 18:10:57 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, t_instruct next_move, int limit)
{
	while ((*a)->value != next_move.value)
	{
		if (next_move.rotate)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
	if ((*b)->value < limit)
		rotate(b, 'b');
}

t_instruct	first_match(t_stack *stack, int ceiling)
{
	t_instruct	first;

	first.rotate = true;
	first.index = -1;
	while (stack->index <= (stack_size(stack) / 2))
	{
		if (stack->value < ceiling)
		{
			first.index = stack->index;
			first.value = stack->value;
			return (first);
		}
		stack = stack->next;
	}
	return (first);
}

t_instruct	last_match(t_stack *stack, int ceiling)
{
	t_instruct	last;

	last.rotate = false;
	last.index = -1;
	while (stack->index < (stack_size(stack) / 2))
		stack = stack->next;
	while (stack)
	{
		if (stack->value < ceiling)
		{
			last.index = stack->index;
			last.value = stack->value;
		}
		stack = stack->next;
	}
	return (last);
}

t_instruct	best_move(t_stack *stack, int ceiling)
{
	int				middle;
	t_instruct		first;
	t_instruct		last;

	first = first_match(stack, ceiling);
	last = last_match(stack, ceiling);
	middle = (stack_size(stack) / 2);
	if (first.index >= 0 && middle - first.index > last.index - middle)
		return (first);
	else
		return (last);
}

void	a_to_b(t_stack **a, t_stack **b, int length)
{
	int				ceiling;
	int				formula;
	t_instruct		next_value;

	formula = get_formula(length);
	ceiling = min_value(*a);
	while (stack_size(*a) > 3)
	{
		ceiling += (formula * 2);
		if (ceiling > third_max_value(*a))
			ceiling = third_max_value(*a);
		next_value = best_move(*a, ceiling);
		while (next_value.index >= 0 && stack_size(*a) > 3)
		{
			push_to_b(a, b, next_value, ceiling - formula);
			next_value = best_move(*a, ceiling);
		}
	}
}
