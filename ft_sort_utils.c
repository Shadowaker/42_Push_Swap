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

int	ft_count(t_stack *arr, int start)
{
	int	i;

	i = 0;
	while (start < arr->size)
		i++;
	return (i);
}

int	ft_upperpart(t_stack *arr, int min)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < arr->size / 4)
	{
		tmp = ft_upper(arr, min);
		if (ft_return_index(arr, tmp) <= arr->size / 2)
			j++;
		min = tmp;
		i++;
	}
	if (j >= (arr->size / 4) / 2)
		return (1);
	return (0);
}

int	ft_downpart(t_stack *arr, int min)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < arr->size / 4)
	{
		tmp = ft_upper(arr, min);
		if (ft_return_index(arr, tmp) > arr->size / 2)
			j++;
		min = tmp;
		i++;
	}
	if (j >= (arr->size / 4) / 2)
		return (1);
	return (0);
}

void	ft_optimal(t_stack *a, t_stack *b)
{
	int	i;
	int	pos_a;
	int pos_b;
	int	j;
	int nofmoves;

	i = 0;
	pos_a = 0;
	nofmoves = a->size + b->size;
	while (i < a->size)
	{
		j = ft_return_index(b, ft_lower(b, a->stack[i]));
		if (j == -1)
			j = ft_return_index(b, ft_max(b));
		if (j < (b->size / 2))
		{
			if (i > a->size / 2)
			{
				if (nofmoves > ((a->size - i) + (b->size - j)))
				{
					nofmoves = (a->size - i) + (b->size - j);
					pos_a = i;
					pos_b = j;
				}
			}
			else
			{
				if (j - i > b->size)
				{
					if (nofmoves > j)
					{
						nofmoves = j;
						pos_a = i;
						pos_b = j;
					}
				}
				else
					if (nofmoves > i + (b->size - j))
					{
						nofmoves = i + (b->size - j);
						pos_a = i;
						pos_b = j;
					}
			}
		}
		else
			if (nofmoves > j + i)
			{
				nofmoves = j + i;
				pos_a = i;
				pos_b = j;
			}
		i++;
	}
	a->pos_a = pos_a;
	a->pos_b = pos_b;
}
