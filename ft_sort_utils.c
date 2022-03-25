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
