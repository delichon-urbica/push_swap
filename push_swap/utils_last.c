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
	while (stack && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*last_node(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
