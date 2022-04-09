/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:15 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:34:15 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_hack(t_stack *a, t_stack *b)
{
	if (ft_upper(a, b->stack[0]) == a->stack[0] && b->size > 0)
	{
		ft_pa(a, b, 1);
		ft_rr(a, b, 1);
	}
}

void	ft_pushinit(t_stack *a, t_stack *b)
{
	int	j;
	int	c;
	int	i;

	i = 0;
	c = a->size;
	while (i < c)
	{
		j = 0;
		while (j < a->chunk_size)
		{
			if (a->stack[0] == a->arr[j])
			{
				ft_hack(a, b);
				ft_rr(a, b, 1);
				break ;
			}
			j++;
		}
		if (j == a->chunk_size)
			ft_pb(a, b, 1);
		if (ft_issorted360(a) == 1)
			break ;
		i++;
	}
}

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

void	ft_optimal(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	nofmoves;
	int	tmp;

	i = 0;
	nofmoves = a->size + b->size;
	while (i < b->size)
	{
		j = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j == -1)
			j = ft_return_index(a, ft_min(a));
		if (j > a->size / 2)
			tmp = ft_filter_1(a, b, i, nofmoves);
		else
			tmp = ft_filter_2(a, b, i, nofmoves);
		if (tmp < nofmoves)
		{
			nofmoves = tmp;
			a->pos_a = j;
			a->pos_b = i;
		}
		i++;
	}
}
