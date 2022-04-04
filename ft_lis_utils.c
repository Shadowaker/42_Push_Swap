/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:51:19 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/04 18:56:57 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinarray(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	val_id(t_stack *a)
{
	if (isinarray(a->stack, a->size, 0) == 0)
		return (0);
	if (isinarray(a->stack, a->size, INT_MIN) == 0)
		return (INT_MIN);
	if (isinarray(a->stack, a->size, INT_MAX) == 0)
		return (INT_MAX);
	if (isinarray(a->stack, a->size, 10000) == 0)
		return (10000);
	return (99999);
}

int	*balloc(int size, int val)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = val;
		i++;
	}
	return (arr);
}
