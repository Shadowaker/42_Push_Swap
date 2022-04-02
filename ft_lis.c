/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/02 01:55:49 by dridolfo         ###   ########.fr       */
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
	//int	*answ;

	lis = malloc(sizeof(int) * a->size * 5);
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
	//answ = malloc(sizeof(int) * (k + 1));
	i = a->size - 1;
	tmp = k;
	int j = 0;
	while (i >= 0)
	{
		if (inds[i] == tmp)
		{
			a->arr[tmp] = a->stack[i];
			printf("culo %d - %d - %d\n", tmp, inds[i], a->arr[tmp]);
			fflush(0);
			tmp--;
			j++;
		}
		i--;
	}
	a->chunk_size = k + 1;

	//int	j = tmp + 1;
	//int	l = 0;
	//int	m = 0;
	//a->arr = malloc((sizeof(int) * a->chunk_size));
	/*
	while (l < a->chunk_size)
	{
		//a->arr[l] = answ[j];
		printf("%d - %d - %d\n", a->arr[l], a->chunk_size, j);
		fflush(0);
		l++;
	}*/
	//sleep(10);
	//free(lis);
	//free(answ);
	//free(inds);
}

void	ft_lis(t_stack *a, t_stack *b)
{
	int	size;
	show_stack(a, "A\n");
	size = 1;
	ft_lis_lis(a);
	int	i = 0;
	while (i < a->chunk_size)
	{
		printf("%d\n", a->arr[i]);
		i++;
	}
	//exit(0);
	ft_pushinit(a, b);
}
