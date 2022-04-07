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

void	ft_optimal(t_stack *a, t_stack *b)
{
	int	i;
	int	pos_a;
	int	pos_b;
	int	j;
	int	nofmoves;
	int	off;

	i = 0;
	pos_a = 0;
	pos_b = 0;
	nofmoves = a->size + b->size;
	off = 0;
	if (a->size % 2 == 0)
		off = 1;
	while (i < b->size)
	{
		j = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j == -1)
			j = ft_return_index(a, ft_min(a));
		if (j > a->size / 2 + off)
		{
			if (i > b->size / 2 + off)
			{
				if (j > i)
				{
					if (nofmoves > (a->size - i))
					{
						nofmoves = b->size - i;
						pos_a = j;
						pos_b = i;
					}
				}
				else
				{
					if (nofmoves > b->size - j)
					{
						nofmoves = a->size - j;
						pos_a = j;
						pos_b = i;
					}
				}
			}
			else
			{
				//if ((j - i) / a->size > b->size / 2 + off)
				//{
				//	if (nofmoves > j)
				//	{
				//		nofmoves = j;
				//		pos_a = j;
				//		pos_b = i;
				//		pos_a = 878787;
				//	}
				//}
				//else
				//{
					if (j - i < a->size - j)
					{
						if (nofmoves > j)
						{
							nofmoves = j;
							pos_a = j;
							pos_b = i;
						}
					}
					else if (b->size - (i + a->size - j) < i)
					{
						if (nofmoves > b->size - i)
						{
							nofmoves = b->size - i;
							pos_a = j;
							pos_b = i;
						}
					}
					else if (nofmoves > i + (a->size - j))
					{
						nofmoves = i + (a->size - j);
						pos_a = j;
						pos_b = i;
					}
				//}
			}
		}
		else
		{
			if (i > b->size / 2 + off)
			{
				//if ((i - j) / b->size > a->size / 2 + off)
				//{
				//	if (nofmoves > i)
				//	{
				//		nofmoves = i;
				//		pos_a = j;
				//		pos_b = i;
				//	}
				//}
				//else
				//{
					if (i - j < b->size - i)
					{
						if (nofmoves > i)
						{
							nofmoves = i;
							pos_a = j;
							pos_b = i;
						}
					}
					else if (a->size - (j + b->size - i) < j)
					{
						if (nofmoves > a->size - j)
						{
							nofmoves = a->size - j;
							pos_a = j;
							pos_b = i;
						}
					}
		/*			else if (j + b->size - i <  + off)
					{
						if (nofmoves > b->size - j)
						{
							nofmoves = b->size - j;
							pos_a = j;
							pos_b = i;
						}
					}
		*/			else if (nofmoves > j + (b->size - i))
					{
						nofmoves = j + (b->size - i);
						pos_a = j;
						pos_b = i;
					}
				//}
			}
			else
			{
				if (j > i)
				{
					if (nofmoves > j)
					{
						nofmoves = j;
						pos_a = j;
						pos_b = i;
					}
				}
				else
				{
					if (nofmoves > i)
					{
						nofmoves = i;
						pos_a = j;
						pos_b = i;
					}
				}
			}
		}
		i++;
	}
	a->pos_a = pos_a;
	a->pos_b = pos_b;
}
