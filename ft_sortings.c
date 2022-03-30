/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:15 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:34:15 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushinit(t_stack *a, t_stack *b)
{
	int	j;

	while (a->chunk_size != a->size)
	{
		j = 0;
		while (j < a->chunk_size)
		{
			if (a->stack[0] == a->arr[j])
			{
				ft_ra(a);
				write(1, "ra\n", ft_strlen("ra\n"));
				break ;
			}
			j++;
		}
		if (j == a->chunk_size)
		{
			ft_pb(a, b);
			write(1, "pb\n", ft_strlen("pb\n"));
		}
	}
}

static int	ft_check2(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	k;
	int	temp;
	int	index;
	int	temp2;

	temp2 = nofmoves;
	while (++i <= b->size)
	{
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (i > k)
			temp = a->size - k + 2;
		else
			temp = b->size - i + 1;
		if (temp < nofmoves)
			index = i - 1;
		if (temp < nofmoves)
			nofmoves = temp;
	}
	if (temp2 == nofmoves)
		index = -1;
	return (index);
}

int	ft_check(t_stack *a, t_stack *b, int i)
{
	int	nofmoves;
	int	k;
	int	index;
	int	temp;

	nofmoves = a->size + b->size;
	if (b->size == 2)
		return (0);
	while (++i <= b->size / 2)
	{
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (i < k)
			temp = k;
		else
			temp = i;
		if (temp < nofmoves)
			index = i;
		if (temp < nofmoves)
			nofmoves = temp;
	}
	if (ft_check2(a, b, i - 1, nofmoves) != -1)
		index = ft_check2(a, b, i - 1, nofmoves);
	return (index);
}
