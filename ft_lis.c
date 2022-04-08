/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/08 22:35:41 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_and_r(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

void	ft_lis_lis(t_stack *a, int *lis, int *inds)
{
	int	i;
	int	k;
	int	tmp;

	i = 1;
	k = -1;
	while (i < a->size)
	{
		inds[i] = s_and_r(lis, 0, i, a->stack[i]);
		if (k < inds[i])
			k = inds[i];
		i++;
	}
	i = a->size - 1;
	tmp = k;
	while (i >= 0)
	{
		if (inds[i] == tmp)
		{
			a->arr[tmp] = a->stack[i];
			tmp--;
		}
		i--;
	}
	a->chunk_size = k + 1;
}

void	ft_lis(t_stack *a, t_stack *b)
{
	int	*lis;
	int	*inds;

	lis = malloc(sizeof(int) * (a->size * 2));
	if (!lis)
		error_handler(2);
	ft_memset(lis, 10000, a->size * 2);
	inds = malloc(sizeof(int) * (a->size + 1));
	if (!inds)
		error_handler(2);
	ft_memset(inds, 0, a->size + 1);
	inds[0] = 0;
	lis[0] = a->stack[0];
	ft_lis_lis(a, lis, inds);
	free(lis);
	free(inds);
	ft_pushinit(a, b);
}
