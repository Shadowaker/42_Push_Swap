/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/28 21:08:16 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_chunk(t_stack *a)
{
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->size - 1)
	{
		j = 0;
		k = i;
		while (a->stack[i] < a->stack[i + 1])
		{
			i++;
			j++;
		}
		if (j > tmp)
		{
			tmp = j;
			a->chunk_start = k;
			a->chunk_end = i;
		}
		i++;
	}
}

void	ft_lis(t_stack *a)
{
	int	*arr;
	int	i;
	int	j;
	int	k;
	int	x;

	arr = malloc(sizeof(int) * a->size);
	i = 0;
	x = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < i)
		{
			if (a->stack[j] > a->stack[i])
			{
				k = 0;
				while (k < x)
				{
					if (arr[k] == a->stack[j])
						break ;
					x++;
				}
				if (k == x)
				{
					arr[k] = a->stack[j];
					x++;
				}
			}
			j++;
		}
		i++;
	}
}
