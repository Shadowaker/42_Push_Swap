/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:33:56 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_both_upper_half(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	j;

	j = ft_return_index(a, ft_upper(a, b->stack[i]));
	if (j == -1)
		j = ft_return_index(a, ft_min(a));
	if (a->size - j > b->size - i)
	{
		if (nofmoves > (a->size - j))
			nofmoves = a->size - j;
	}
	else
	{
		if (nofmoves > b->size - i)
			nofmoves = b->size - i;
	}
	return (nofmoves);
}

static int	ft_both_lower_half(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	j;

	j = ft_return_index(a, ft_upper(a, b->stack[i]));
	if (j == -1)
		j = ft_return_index(a, ft_min(a));
	if (j > i)
	{
		if (nofmoves > j)
			nofmoves = j;
	}
	else
	{
		if (nofmoves > i)
			nofmoves = i;
	}
	return (nofmoves);
}

int	ft_filter_1(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	j;
	int	tmp;

	tmp = nofmoves;
	j = ft_return_index(a, ft_upper(a, b->stack[i]));
	if (j == -1)
		j = ft_return_index(a, ft_min(a));
	if (i > b->size / 2)
		tmp = ft_both_upper_half(a, b, i, nofmoves);
	else
		tmp = i + (a->size - j);
	return (tmp);
}

int	ft_filter_2(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	j;
	int	tmp;

	tmp = nofmoves;
	j = ft_return_index(a, ft_upper(a, b->stack[i]));
	if (j == -1)
		j = ft_return_index(a, ft_min(a));
	if (i > b->size / 2)
		tmp = j + (b->size - i);
	else
		tmp = ft_both_lower_half(a, b, i, nofmoves);
	return (tmp);
}
