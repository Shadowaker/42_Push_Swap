/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:26 by dridolfo          #+#    #+#             */
/*   Updated: 2022/03/23 17:54:05 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_chunk(t_stack *a)
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

int	*ft_lis(t_stack *a)
{
	int	*res;

	res = malloc(sizeof(int) * 2);
	ft_find_chunk(a);
	res[0] = 1;
	res[1] = 0;
	return (res);
}
