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

void	ft_op(t_stack *a, t_stack *b)
{
	int	off;
//	int	osize;

	off = a->size / 2;
//	osize = a->size;
	while (a->size > off)
	{
		if (issorted(a) == 0)
			ft_heapsort(a, b);
		else
			break ;
	}
	while (b->size > 0)
	{
		ft_pa(a, b);
		write(1, "pa\n", ft_strlen("pa\n"));
	}
}

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

void	ft_thinker(t_stack *a, t_stack *b)
{
	int	min_a;
	int	min_b;
//	int	off;
	int	sigma;
	int	o;

	min_a = ft_min(a);
	min_b = ft_min(b);
	if (ft_return_index(a, min_a) > ft_return_index(b, min_b))
	{
	//	off = ft_return_index(b, min_b);
		o = 0;
	}
	else
	{
	//	off = ft_return_index(a, min_a);
		o = 1;
	}
	sigma = ft_sigma(a, b, min_a, min_b);
	ft_thinker_2(a, b, sigma, o);
}

void	ft_mind(t_stack *a, t_stack *b)
{
	ft_pushinit(a, b);
	ft_thinker(a, b);
	ft_pa(a, b);
	write(1, "pa\n", ft_strlen("pa\n"));
	if (ft_return_index(a, ft_min(a)) == 1)
	{
		ft_sa(a);
		write(1, "sa\n", ft_strlen("sa\n"));
	}
}

void	ft_heapsort(t_stack *a, t_stack *b)
{
	int	x;
	int	ind;

	x = ft_min(a);
	ind = ft_return_index(a, x);
	if (ind >= a->size / 2)
		ft_push_down(a, a->size - ind);
	else
		ft_push_up(a, ind);
	if (issorted(a) == 0)
	{
		ft_pb(a, b);
		write(1, "pb\n", ft_strlen("pb\n"));
	}
}
