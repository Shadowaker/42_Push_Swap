/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:55:46 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/30 22:16:54 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_offset(t_stack *a, int count, int index)
{
	int	i;

	i = 0;
	while (index >= 0)
	{
		if (a->array[index] == count)
			return (i);
		else
		{
			i++;
			index--;
		}
	}
	return (0);
}

void	confront(t_stack *a)
{
	int	i;
	int	temp_count;
	int	index;

	i = 0;
	temp_count = a->chunk_size;
	index = a->size - 1;
	while (temp_count > 0)
	{
		i = count_offset(a, temp_count, index);
		index = index - i;
		a->arr[temp_count - 1] = a->stack[index];
		temp_count -= 1;
	}
}
