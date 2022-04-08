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

void	ft_mind(t_stack *a, t_stack *b)
{
	int	index;
	int	pos_a;

	ft_lis(a, b);
	while (b->size > 0)
	{
		ft_optimal(a, b);
		index = a->pos_b;
		pos_a = a->pos_a;
		if (index <= b->size / 2 && pos_a <= a->size / 2)
		{
			while (index > 0 && pos_a > 0)
			{
				ft_rr(a, b);
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
				ft_ra(a, 1);;
				pos_a--;
			}
		}
		else if (index > b->size / 2 && pos_a > a->size / 2)
		{
			while (index < b->size && pos_a < a->size)
			{
				ft_rrr(a, b);
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
		else
		{
			if (index > b->size / 2 && pos_a <= a->size / 2)
			{
				if (index - pos_a < b->size - index)
				{
					while (index > 0 && pos_a > 0)
					{
						ft_rr(a, b);
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
				else if (a->size - pos_a - (b->size - index) < pos_a)
				{
					while (index < b->size && pos_a < a->size)
					{
						ft_rrr(a, b);
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
			else
			{
				if (pos_a - index < a->size - pos_a)
				{
					while (index > 0 && pos_a > 0)
					{
						ft_rr(a, b);
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
				else if (b->size - index - (a->size - pos_a) < index )
				{
					while (index < b->size && pos_a < a->size)
					{
						ft_rrr(a, b);
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
		}
		ft_pa(a, b);
	}
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
