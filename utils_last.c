/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:51:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 17:52:55 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*second_last_node(t_stack *stack)
{
	t_stack	*second_last;

	second_last = stack;
	while (second_last && second_last->next->next)
		second_last = second_last->next;
	return (second_last);
}

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}
