/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:46 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 16:23:34 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*temp;

	temp = (*src);
	(*src) = (*src)->next;
	temp->next = (*dest);
	(*dest) = temp;
	update_index(src);
	update_index(dest);
	if (c == 'a')
		print_cmd("pa");
	else
		print_cmd("pb");
}

void	swap(t_stack **stack, char c)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->index = 1;
	(*stack)->next = (*stack)->next->next;
	second->next = *stack;
	second->index = 0;
	(*stack) = second;
	if (c == 'a')
		print_cmd("sa");
	else
		print_cmd("sb");
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = last_node(*stack);
	last->next = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	update_index(stack);
	if (c == 'a')
		print_cmd("ra");
	else
		print_cmd("rb");
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*second_last;
	t_stack	*temp;

	last = last_node(*stack);
	second_last = second_last_node(*stack);
	second_last->next = NULL;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	update_index(stack);
	if (c == 'a')
		print_cmd("rra");
	else
		print_cmd("rrb");
}
