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

void	ft_fillarr(t_stack *a, int size)
{
	int	i;
	int	j;

	a->arr = malloc(sizeof(int) * (a->chunk_end - a->chunk_start - size + 1));
	i = a->chunk_start + 1;
	j = 0;
	while (i < a->chunk_end - 1)
	{
		if (a->stack[i] > a->stack[i + 1] || a->stack[i] < a->stack[i - 1])
		{
			a->arr[j] = a->stack[i];
			j++;
		}
		i++;
	}
}

void	ft_lis(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	popò;
	int	temp;
	int	temp2;
	int	temp3;

	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		temp = 0;
		l = i + 1;
		temp3 = 0;
		while (j < a->size)
		{
			if (a->stack[j] > a->stack[i])
			{
				while (l <= j)
				{
					if (l == j)
					{
						temp++;
						k2 = j;
					}					
					if (a->stack[j] < a->stack[l])
					{
						popò = j;
						temp2 = temp;
						break ;
					}
					l++;
				}
			}
			j++;
			if (j == a->size && l != j)
			{
				j = popò;
				temp3 = temp;
				temp = temp2;
				k = k2;
			}
			if (temp > temp3)
			{
				temp3 = temp;
				k = k2;
			}
		}
		if (temp3 > a->chunk_size)
		{
			a->chunk_size = temp3;
			a->chunk_start = i;
			a->chunk_end = k;
		}
		i++;
	}
	ft_fillarr(a, size);
}
