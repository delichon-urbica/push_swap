/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:40 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 18:06:34 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	duplicates(int *array, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (array[i] == c)
			return (true);
		i++;
	}
	return (false);
}

t_bool	is_integer(int n, char *argv[])
{
	int			*input;
	int			i;
	long int	j;
	t_bool		is_valid;

	is_valid = true;
	input = (int *)malloc(sizeof(int) * n);
	if (!input)
		return (false);
	i = 0;
	while (i < n)
	{
		j = ft_atoli(argv[i + 1]);
		if (j > INT_MAX || j < INT_MIN)
			is_valid = false;
		input[i] = j;
		if (duplicates(input, input[i], i))
			is_valid = false;
		i++;
	}
	free(input);
	return (is_valid);
}

t_bool	check_input(int n, char *argv[])
{
	int	i;

	i = 1;
	while (i <= n)
	{
		if (!is_number(argv[i]))
			return (false);
		i++;
	}
	if (!is_integer(n, argv))
		return (false);
	return (true);
}
