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

int	ft_min_(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr[0];
	while (i < size)
	{
		if (arr[i] < tmp)
			tmp = arr[i];
		i++;
	}
	return (tmp);
}

void	ft_pushinit(t_stack *a, t_stack *b)
{
	int	j;
	int	c;
	int	i;

	i = 0;
	c = a->size;
	while (i < c)
	{
		j = 0;
		while (j < a->chunk_size)
		{
			if (a->stack[0] == a->arr[j])
			{
				if (ft_upper(a, b->stack[0]) == a->stack[0] && b->size > 0)
				{
					ft_pa(a, b);
					ft_rr(a, b);
					write(1, "pa\nrr\n", ft_strlen("pa\nrr\n"));
				}
				ft_rr(a, b);
				write(1, "rr\n", ft_strlen("rr\n"));
				break ;
			}
			j++;
		}
		if (j == a->chunk_size)
		{
			ft_pb(a, b);
			write(1, "pb\n", ft_strlen("pb\n"));
		}
		if (ft_issorted360(a) == 1)
			break ;
		i++;
	}
}

static int	ft_check2(t_stack *a, t_stack *b, int i, int nofmoves)
{
	int	k;
	int	temp;
	int	index;
	int	temp2;
	int	j;

	temp2 = nofmoves;
	index = -1;
	while (++i < b->size)
	{
		j = ft_return_index(a, ft_lower(a, b->stack[i]));
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j < k && i > j)
		{
			temp = a->size - k + 1;
			a->offset = 1;
		}
		else if (j > k && i > k)
		{
			temp = a->size - j + 1;
			a->offset = 0;
		}
		else if (j < k && i > k)
		{
			temp = b->size - i + 1;
			a->offset = 1;
		}
		else
		{
			temp = b->size - i + 1;
			a->offset = 0;
		}
		if (temp < nofmoves)
			index = i;
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
	int	j;

	nofmoves = a->size + b->size;
	if (b->size <= 2)
		return (0);
	while (++i <= b->size / 2)
	{
		j = ft_return_index(a, ft_lower(a, b->stack[i]));
		k = ft_return_index(a, ft_upper(a, b->stack[i]));
		if (j < k && i < j)
		{
			temp = j;
			a->offset = 0;
		}
		else if (j > k && i < k)
		{
			temp = k;
			a->offset = 1;
		}
		else if (j < k && i < j)
		{
			temp = i;
			a->offset = 0;
		}
		else
		{
			temp = i;
			a->offset = 1;
		}
		if (temp < nofmoves)
			index = i;
		if (temp < nofmoves)
			nofmoves = temp;
	}
	if (ft_check2(a, b, i - 1, nofmoves) != -1)
		index = ft_check2(a, b, i - 1, nofmoves);
	return (index);
}

int	ft_checkeroni(t_stack *a, t_stack *b, int i)
{
	int	nofmoves;
	int	j;
	int	k;
	int	index;
	int	temp;

	nofmoves = a->size + b->size;
	while (i <= b->size / 2 + 1)
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
		{
			nofmoves = temp;
			index = i;
		}
		i++;
	}
	i--;
	while (i <= b->size)
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
		{
			nofmoves = temp;
			index = i - 1;
		}
		i++;
	}
	return (index);
}
