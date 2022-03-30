/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/30 22:17:15 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_arr_lis(int n)
{
	int	i;
	int	*arr;

	i = 0;
	arr = calloc(sizeof(int), n);
	while (i < n)
	{
		arr[i] = 1;
		i++;
	}
	return (arr);
}

int	*ft_lis_3(t_stack *a, int n)
{
	int	*lis;
	int	*array;
	int	i;
	int	j;

	lis = fill_arr_lis(n);
	array = fill_arr_lis(n);
	i = 0;
	while (++i < n)
	{
		j = -1;
		while (++j < i)
		{
			if (a->stack[j] < a->stack[i] && (lis[j] + 1) > lis[i])
			{
				lis[i] = lis[j] + 1;
				array[i]++;
			}
		}
	}
	free(lis);
	return (array);
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
	a->chunk_size = size;
	a->arr = malloc(sizeof(int) * size);
	a->array = ft_lis_3(a, a->size);
	confront(a);
	ft_pushinit(a, b);
}
