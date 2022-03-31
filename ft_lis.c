/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/31 20:57:26 by dridolfo         ###   ########.fr       */
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

void	ft_lis_lis(t_stack *a)
{
	int	*lis;
	int	*inds;
	int	i;
	int	k;
	int	tmp;
	int	*answ;

	lis = malloc(sizeof(int) * a->size);
	inds = malloc(sizeof(int) * a->size);
	inds[0] = 0;
	lis[0] = a->stack[0];
	i = 1;
	while (i++ < a->size)
		lis[i] = 10000;
	i = 1;
	k = -1;
	while (i < a->size)
	{
		inds[i] = s_and_r(lis, 0, i, a->stack[i]);
		if (k < inds[i])
			k = inds[i];
		i++;
	}
	answ = malloc(sizeof(int) * (k + 1));
	i = a->size - 1;
	tmp = k;
	while (i >= 0)
	{
		if (inds[i] == tmp)
		{
			answ[tmp] = a->stack[i];
			tmp--;
		}
		i--;
	}
	a->chunk_size = k;
	int	j = tmp + 1;
	int	l = 0;
	a->arr = malloc((sizeof(int) * a->chunk_size));
	while (l < a->chunk_size)
	{
		a->arr[l] = answ[j];
		printf("%d - %d \n", a->arr[l], a->chunk_size);
		j++;
		l++;
	}
	free(lis);
	free(answ);
	free(inds);
}

void	ft_lis(t_stack *a, t_stack *b)
{
	int	size;

	size = 1;
	ft_lis_lis(a);
	ft_pushinit(a, b);
}
