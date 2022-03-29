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

void	ft_fillarr(t_stack *a, int size)
{
	int	i;
	int	j;
	int	k;

	if (size == 1)
		return ;
	a->arr = malloc(sizeof(int) * (a->chunk_end - a->chunk_start - size + 1));
	a->chunk_size = a->chunk_end - a->chunk_start - size + 1;
	i = a->chunk_end;
	j = 0;
	while (i > a->chunk_start)
	{
		k = i - 1;
		if (a->stack[i] < a->stack[k])
		{
			while (a->stack[k] > a->stack[i] && k >= 0)
			{
				a->arr[j] = a->stack[k];
				j++;
				k--;
			}
			i = k + 1;
		}
		i--;
	}
}

void	ft_find_start(t_stack *a, int size)
{
	int	i;
	int	j;

	i = a->chunk_end;
	while (i > 1)
	{
		if (a->stack[i] > a->stack[i - 1])
			size--;
		else
		{
			j = i - 1;
			while (a->stack[j] > a->stack[i] && j >= 0)
				j--;
			i = j;
		}
		if (size == 0)
			a->chunk_start = i - 1;
		i--;
	}
}

int	ft_lis_2(t_stack *a, int n, int *max_ref)
{
	int	res;
	int	max_ending_here;
	int	i;

	res = 1;
	max_ending_here = 1;
	if (n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		res = ft_lis_2(a, i, max_ref);
		if (a->stack[i - 1] < a->stack[n - 1] && res + 1 > max_ending_here)
			max_ending_here = res + 1;
		i++;
	}
	if (*max_ref < max_ending_here)
	{
		a->chunk_end = i - 1;
		*max_ref = max_ending_here;
	}
	return (max_ending_here);
}

void	ft_lis(t_stack *a, t_stack *b)
{
	int	size;

	size = 1;
	ft_lis_2(a, a->size, &size);
	ft_fillarr(a, size);
	ft_find_start(a, size);
	ft_pushinit(a, b);
}
