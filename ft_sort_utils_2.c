/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:15:30 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/03 18:10:28 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted360(t_stack *a)
{
	int	i;
	int	max;

	if (a->size == 1 || a->size == 0)
		return (1);
	i = 1;
	max = ft_return_index(a, ft_max(a));
	while (i <= max && i < a->size)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (0);
		i++;
	}
	i++;
	while (i < a->size && i < a->size)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (0);
		i++;
	}
	if (a->stack[0] < a->stack[i - 1])
		return (0);
	return (1);

}

int	ft_sigma(t_stack *a, t_stack *b, int min_a, int min_b)
{
	int	off_a;
	int	off_b;

	off_a = ft_return_index(a, min_a);
	off_b = ft_return_index(b, min_b);
	if (off_a < a->size / 2 && off_b < b->size / 2)
		return (0);
	else if (off_a > a->size / 2 && off_b > b->size / 2)
		return (1);
	else if (off_a < a->size / 2 && off_b > b->size / 2)
		return (2);
	else if (off_a > a->size / 2 && off_b < b->size / 2)
		return (3);
	return (-1);
}

void	ft_o_set(t_stack *a, t_stack *b, int o)
{
	int	i;

	if (o == 0)
	{
		i = ft_return_index(b, ft_min(b));
		if (i < b->size / 2)
		{
			while (i--)
			{
				ft_rb(b);
				write(1, "rb\n", ft_strlen("rb\n"));
			}
		}
		else
		{
			while (i < b->size)
			{
				ft_rrb(b);
				write(1, "rrb\n", ft_strlen("rrb\n"));
				i++;
			}
		}
	}
	else
		ft_o_set_a(a);
}

void	ft_o_set_a(t_stack *a)
{
	int	i;

	i = ft_return_index(a, ft_min(a));
	if (i < a->size / 2)
	{
		while (i > 0)
		{
			ft_ra(a);
			write(1, "ra\n", ft_strlen("ra\n"));
			i--;
		}
	}
	else
	{
		while (i < a->size)
		{
			ft_ra(a);
			write(1, "rra\n", ft_strlen("rra\n"));
			i++;
		}
	}
}
