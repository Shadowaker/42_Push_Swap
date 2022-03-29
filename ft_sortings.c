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

static void	ft_push_arr(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	off;

	off = 0;
	j = 0;
	while (j < a->chunk_size)
	{
		if (a->stack[i] == a->arr[j])
		{
			ft_pb(a, b);
			write(1, "pb\n", ft_strlen("pb\n"));
			a->chunk_end -= 1;
			off = 1;
			break ;
		}
		j++;
	}
	if (off == 0)
	{
		ft_ra(a);
		write(1, "ra\n", ft_strlen("ra\n"));
		a->chunk_end -= 1;
	}
}

void	ft_pushinit(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->chunk_start)
	{
		ft_pb(a, b);
		write(1, "pb\n", ft_strlen("pb\n"));
		a->chunk_start -= 1;
		a->chunk_end -= 1;
	}
	while (i <= a->chunk_end)
		ft_push_arr(a, b, i);
	while (i < a->size - a->chunk_size)
	{
		ft_pb(a, b);
		write(1, "pb\n", ft_strlen("pb\n"));
	}
}

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
	int	j;
	int	k;
	int	index;
	int	temp;

	nofmoves = a->size + b->size;
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
	if (ft_check2(a, b, i - 1, nofmoves) != -1)
		index = ft_check2(a, b, i - 1, nofmoves);
	return (index);
}
