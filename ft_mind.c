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

void	ft_thinker_2(t_stack *a, t_stack *b, int sigma, int o)
{
	int	off;

	if (o == 0)
		off = ft_return_index(b, ft_min(b));
	else
		off = ft_return_index(a, ft_min(a));
	if (sigma == 0)
		ft_push_both_up(a, b, off);
	else if (sigma == 1)
		ft_push_both_down(a, b, off, o);
	else if (sigma > 1)
	{
		ft_o_set(a, b, 0);
		ft_o_set_a(a);
		return ;
	}
	ft_o_set(a, b, o);
}

void	ft_thinker(t_stack *a, t_stack *b, int ind)
{
	int	pos_a;

	pos_a = ft_return_index(a, ft_upper(a, b->stack[ind]));
}

void	ft_mind(t_stack *a, t_stack *b)
{
	int	index;
	int	pos_a;

	ft_find_chunk(a);
	ft_pushinit(a, b);
	while (b->size > 0)
	{
		//sleep(1);
		index = ft_check(a, b, -1);
		pos_a = ft_return_index(a, ft_upper(a, b->stack[index]));
		//printf("%d - %d \n", index, pos_a);
	//	show_stacks(a, b);
		if (index < b->size / 2)
		{
			while (index > 0 && pos_a - index < a->size / 2 && pos_a > 0)
			{
				ft_rr(a, b);
				write(1, "rr\n", ft_strlen("rr\n"));
				index--;
				pos_a--;
			}
			while (index > 0)
			{
				ft_rb(b);
				write(1, "rb\n ", ft_strlen("rb\n"));
				index--;
			}
			if (pos_a < a->size / 2)
			{
				while (pos_a > 0)
				{
					ft_ra(a);
					write(1, "ra\n", ft_strlen("ra\n"));
					pos_a--;
				}
			}
			else
			{
				while (pos_a < a->size)
				{
					ft_rra(a);
					write(1, "rra\n", ft_strlen("rra\n"));
					pos_a++;
				}
			}
		}
		else
		{
			while (index < b->size && pos_a + a->size - index > a->size / 2 && pos_a < a->size)
			{
				ft_rrr(a, b);
				write(1, "rrr\n", ft_strlen("rrr\n"));
				index++;
				pos_a++;
			}
			while (index < b->size)
			{
				ft_rrb(b);
				write(1, "rrb\n", ft_strlen("rrb\n"));
				index++;
			}
			if (pos_a > a->size / 2)
			{
				while (pos_a < a->size)
				{
					ft_rra(a);
					write(1, "rra\n", ft_strlen("rra\n"));
					pos_a++;
				}
			}
			else
			{
				while (pos_a > 0)
				{
					ft_ra(a);
					write(1, "ra\n", ft_strlen("ra\n"));
					pos_a--;
				}
			}
		}
		ft_pa(a, b);
		write(1, "pa\n", ft_strlen("pa\n"));
	}
	index = ft_return_index(a, ft_min(a));
	if (index < a->size / 2)
	{
		while (issorted(a) != 1)
		{
			ft_ra(a);
			write(1, "ra\n", ft_strlen("ra\n"));
		}
	}
	else
		while (issorted(a) != 1)
		{
			ft_rra(a);
			write(1, "rra\n", ft_strlen("rra\n"));
		}
	//show_stack(a, "a");
}
