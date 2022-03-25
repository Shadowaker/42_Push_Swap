/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:25:13 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/23 17:50:02 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	create_it(int size)
{
	t_stack	arr;

	arr.stack = ft_calloc(size, 4);
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		*res;

	if (argc > 1)
	{
		a = ft_parser(argc, argv);
		if (a.size != -1)
		{
			b = create_it(a.size);
		}
		else
			write(1, "Error\n", ft_strlen("Error\n"));
	}
	res = ft_lis(&a);
	printf("%d %d\n", res[0], res[1]);
	ft_pushinit(&a, &b);
	i = ft_check(&a, &b, 0);
	printf("%d\n", i);
	printf("--------------------------------\n");
	show_stacks(&a, &b);
}
