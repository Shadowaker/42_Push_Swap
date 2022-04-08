/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:43 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:22:43 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(int error)
{
	if (error == 0)
		write(1, "Error.\n", ft_strlen("Error.\n"));
	else if (error == 1)
		write(1, "Error.\nNot enough arguments\n",
			ft_strlen("Error.\nNot enough arguments\n"));
	else if (error == 2)
		write(1, "Error.\nMalloc error: not enough memory\n",
			ft_strlen("Error.\nMalloc error: not enough memory\n"));
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

static void	sort_it(t_stack *a, t_stack *b)
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		a = ft_parser(argc, argv);
		if (a.size != -1)
		{
			b = create_it(a.size);
			if (a.size > 1 && (issorted(&a) == 0))
				sort_it(&a, &b);
			free(a.arr);
			free(a.stack);
			free(b.stack);
		}
		else
			error_handler(0);
	}
	else
		error_handler(1);
}
