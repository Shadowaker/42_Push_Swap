/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mind_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:22:15 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/09 17:21:03 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index_upper_2(t_stack *a, t_stack *b, int index, int pos_a)
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

static void	ft_index_upper_3(t_stack *a, t_stack *b, int index, int pos_a)
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

void	ft_index_upper(t_stack *a, t_stack *b, int index, int pos_a)
{
	if (index - pos_a < b->size - index)
		ft_index_upper_3(a, b, index, pos_a);
	else if (a->size - pos_a - (b->size - index) < pos_a)
		ft_index_upper_2(a, b, index, pos_a);
	else
	{
		while (index < b->size)
		{
			ft_rrb(b, 1);
			index++;
		}
		while (pos_a > 0)
		{
			ft_ra(a, 1);
			pos_a--;
		}
	}
}

void	ft_pos_upper_2(t_stack *a, t_stack *b, int index, int pos_a)
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
	while (pos_a-- > 0)
	{
		ft_ra(a, 1);
		pos_a--;
	}
}

void	ft_pos_upper_3(t_stack *a, t_stack *b, int index, int pos_a)
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
