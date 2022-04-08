/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:15:30 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/08 14:58:51 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted360(t_stack *a)
{
	int	i;
	int	max;

	if (a->size == 1 || a->size == 0)
		return (1);
	i = 1;
	max = ft_return_index(a, ft_max(a));
	while (i <= max && i < a->size)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (0);
		i++;
	}
	i++;
	while (i < a->size && i < a->size)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (0);
		i++;
	}
	if (a->stack[0] < a->stack[i - 1])
		return (0);
	return (1);
}

