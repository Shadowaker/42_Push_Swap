/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:30:43 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 23:11:48 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_filter_swap(char *todo, t_stack *a, t_stack *b)
{
	if (todo[1] == 'a')
	{
		ft_sa(a);
		write(1, "sa\n", 3);
	}
	else if (todo[1] == 'b')
	{
		ft_sb(b);
		write(1, "sb\n", 3);
	}
	else if (todo[1] == 's')
	{
		ft_ss(a, b);
		write(1, "ss\n", 3);
	}
	else
		return (0);
	return (1);
}

int	ft_filter_push(char *todo, t_stack *a, t_stack *b)
{
	if (todo[1] == 'a')
	{
		ft_pa(a, b);
		write(1, "pa\n", 3);
	}
	else if (todo[1] == 'b')
	{
		ft_pb(a, b);
		write(1, "pb\n", 3);
	}
	else
		return (0);
	return (1);
}

static int	ft_filter_rot2(char *todo, t_stack *a, t_stack *b)
{
	if (todo[2] == 'a')
	{
		ft_rra(a);
		write(1, "rra\n", 4);
	}
	else if (todo[2] == 'b')
	{
		ft_rrb(b);
		write(1, "rrb\n", 4);
	}
	else if (todo[2] == 'r')
	{
		ft_rrr(a, b);
		write(1, "rrr\n", 4);
	}
	else
		return (0);
	return (1);
}

int	ft_filter_rot(char *todo, t_stack *a, t_stack *b)
{
	if (todo[1] == 'a')
	{
		ft_ra(a);
		write(1, "ra\n", 3);
	}
	else if (todo[1] == 'b')
	{
		ft_rb(b);
		write(1, "rb\n", 3);
	}
	else if (todo[1] == 'r' && ft_strlen(todo) == 2)
	{
		ft_rr(a, b);
		write(1, "rr\n", 3);
	}
	else
		return (ft_filter_rot2(todo, a, b));
	return (1);
}
