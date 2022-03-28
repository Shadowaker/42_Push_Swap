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
	int	i;
	int	size;

	i = 0;
	size = a->chunk_end - a->chunk_start + 1;
	//printf("%d----%d------%d\n", a->chunk_start, a->chunk_end, size);
	while (i < a->chunk_start)
	{
		ft_pb(a, b);
		write(1, "pb\n", ft_strlen("pb\n"));
		a->chunk_start -= 1;
		a->chunk_end -= 1;
	}
	while (i <= a->chunk_end)
	{
		ft_ra(a);
		write(1, "ra\n", ft_strlen("ra\n"));
		a->chunk_end -= 1;
	}
	while (i < a->size - size)
	{
		ft_pb(a, b);
		write(1, "pb\n", ft_strlen("pb\n"));
	}
}
/*
static int	ft_check2(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	k;
	int	j;
	int	temp;
	int	index;
	int	temp2;

	temp2 = nofmoves;
	while (i++ <= b->size)
	{
		j = ft_return_index(a, ft_lower(a, b->stack[i]));
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j < k && i > j)
			temp = a->size - k + 2;
		else if (j > k && i > k)
			temp = a->size - j + 1;
		else
			temp = b->size - i + 1;
		if (temp < nofmoves)
			nofmoves = temp;
		if (temp < nofmoves)
			index = i - 1;
	}
	if (temp2 == nofmoves)
		index = -1;
	return (index);
}
*/
int	ft_check(t_stack *a, t_stack *b, int i)
{
	int	nofmoves;
	int	j;
	int	k;
	int	index;
	int	temp;

	nofmoves = a->size + b->size;
	/*
	if (b->size < 3)
		return (0);*/
	while (++i <= b->size / 2)
	{
		j = ft_return_index(a, ft_lower(a, b->stack[i]));
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j < k && i < j)
			temp = j + 1;
		else if (j > k && i < k)
			temp = k;
		else
			temp = i;
		if (temp < nofmoves)
			index = i;
		if (temp < nofmoves)
			nofmoves = temp;
	}
	//i--;
	while (++i < b->size)
	{
		j = ft_return_index(a, ft_lower(a, b->stack[i]));
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j < k && i > j)
			temp = a->size - k + 2;
		else if (j > k && i > k)
			temp = a->size - j + 1;
		else
			temp = b->size - i + 1;
		if (temp < nofmoves)
			index = i;
		if (temp < nofmoves)
			nofmoves = temp;
	}
	// if (temp2 == nofmoves)
	// 	index = -1;
	// return (index);
	// if (ft_check2(a, b, i - 1, nofmoves) != -1)
	// 	index = ft_check2(a, b, i - 1, nofmoves);
	return (index);
}
