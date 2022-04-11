/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:25:24 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/11 18:12:47 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(int error)
{
	if (error != -1)
		write(1, "\033[91mError\033[0m\n", ft_strlen("\033[91mError\033[0m\n"));
	exit(0);
}

t_stack	create_it(int size)
{
	t_stack	arr;

	arr.stack = ft_calloc(size, sizeof(int));
	ft_memset(arr.stack, 0, size * sizeof(int));
	arr.size = 0;
	return (arr);
}

int	issorted(t_stack *arr)
{
	int	i;

	i = 1;
	while (i < arr->size)
	{
		if (arr->stack[i - 1] > arr->stack[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_it(t_stack *a, t_stack *b)
{
	if (issorted(a) == 0)
	{
		if (a->size > 7)
			ft_mind(a, b, 1);
		else if (a->size > 3)
			ft_advanced_algorithm(a, b);
		else
			ft_basic_algorithm(a);
	}
}
