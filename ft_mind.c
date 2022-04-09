/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:25:05 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:25:05 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_mid_upper(t_stack *a, t_stack *b, int index, int pos_a)
{
	while (index > 0 && pos_a > 0)
	{
		ft_rr(a, b, 1);
		index--;
		pos_a--;
	}
	while (index > 0)
	{
		ft_rb(b, 1);
		index--;
	}
	while (pos_a > 0)
	{
		ft_ra(a, 1);
		pos_a--;
	}
}

static void	ft_mid_lower(t_stack *a, t_stack *b, int index, int pos_a)
{
	while (index < b->size && pos_a < a->size)
	{
		ft_rrr(a, b, 1);
		index++;
		pos_a++;
	}
	while (index < b->size)
	{
		ft_rrb(b, 1);
		index++;
	}
	while (pos_a < a->size)
	{
		ft_rra(a, 1);
		pos_a++;
	}
}

void	ft_pos_upper(t_stack *a, t_stack *b, int index, int pos_a)
{
	if (pos_a - index < a->size - pos_a)
		ft_pos_upper_2(a, b, index, pos_a);
	else if (b->size - index - (a->size - pos_a) < index)
		ft_pos_upper_3(a, b, index, pos_a);
	else
	{
		while (pos_a < a->size)
		{
			ft_rra(a, 1);
			pos_a++;
		}
		while (index > 0)
		{
			ft_rb(b, 1);
			index--;
		}
	}
}

static void	ft_roll_it(t_stack *a)
{
	int	index;

	index = ft_return_index(a, ft_min(a));
	if (index <= a->size / 2 + 1)
	{
		while (issorted(a) != 1)
			ft_ra(a, 1);
	}
	else
	{
		while (issorted(a) != 1)
			ft_rra(a, 1);
	}
}

void	ft_mind(t_stack *a, t_stack *b, int off)
{
	int	index;
	int	pos_a;

	if (off == 1)
		ft_lis(a, b);
	while (b->size > 0)
	{
		ft_optimal(a, b);
		index = a->pos_b;
		pos_a = a->pos_a;
		if (index <= b->size / 2 && pos_a <= a->size / 2)
			ft_mid_upper(a, b, index, pos_a);
		else if (index > b->size / 2 && pos_a > a->size / 2)
			ft_mid_lower(a, b, index, pos_a);
		else
		{
			if (index > b->size / 2 && pos_a <= a->size / 2)
				ft_index_upper(a, b, index, pos_a);
			else
				ft_pos_upper(a, b, index, pos_a);
		}
		ft_pa(a, b, 1);
	}
	ft_roll_it(a);
}
