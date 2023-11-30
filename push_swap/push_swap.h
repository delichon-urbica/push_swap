/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:58 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/27 13:53:46 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instruct {
	int		value;
	int		index;
	t_bool	rotate;
}	t_instruct;

int				main(int argc, char *argv[]);
int				stack_size(t_stack *stack);
int				min_value(t_stack *stack);
int				max_value(t_stack *stack);
int				third_max_value(t_stack *stack);
int				get_formula(int length);
int				map_number(int length, char *argv[], int i);
void			update_index(t_stack **stack);
void			clear_stack(t_stack **stack);
void			print_cmd(char *str);
void			push(t_stack **src, t_stack **dest, char c);
void			swap(t_stack **stack, char c);
void			rotate(t_stack **stack, char c);
void			reverse_rotate(t_stack **stack, char c);
void			sort_three(t_stack **stack);
void			sort_big(t_stack **a, int length);
void			a_to_b(t_stack **a, t_stack **b, int length);
void			b_to_a(t_stack **a, t_stack **b);
t_bool			is_sorted(t_stack *stack);
t_bool			check_input(int argc, char *argv[]);
t_stack			*init_stack(int n, char *argv[]);
t_stack			*last_node(t_stack *stack);
t_stack			*second_last_node(t_stack *stack);

#endif